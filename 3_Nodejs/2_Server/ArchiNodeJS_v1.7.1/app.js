var express = require('express');
var session = require('express-session');
var path = require('path');
var logger = require('morgan');
var bodyParser = require('body-parser');
var expressValidator = require('express-validator');
var multer = require('multer');

var app = express();

// set global variable for root directory
global.__base = __dirname + '/';

// view engine setup
app.set('views', path.join(__dirname, 'pages'));
app.set('view engine', 'jade');
app.locals.basedir = path.join(__dirname, 'pages');

// middlewares
app.use(logger('dev'));
app.use('/src', express.static('src'));
app.use('/pictures', express.static('pictures'));
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));
app.use(expressValidator());
app.use(session({
    secret: 'keyboard cat',
    resave: false,
    saveUninitialized: true,
    cookie: { secure: false }
}));

app.use('/assets', express.static('public'));

// api-rest routes
app.use('/api-rest/users', require('./api-rest/users/routes/users.route'));
app.use('/api-rest/treks', require('./api-rest/treks/routes/treks.route'));
app.use('/api-rest/photos', require('./api-rest/photos/routes/photos.route'));

// pages routes
app.use('/', require('./pages/core/routes/index.route'));
app.use('/users', require('./pages/users/routes/users.route'));
app.use('/treks', require('./pages/treks/routes/treks.route'));
app.use('/photos', require('./pages/photos/routes/photos.route'));
app.use('/login', require('./pages/login/routes/logins.route'));
app.use('/signup', require('./pages/signup/routes/signups.route'));


// catch 404 and forward to error handler
app.use(function(req, res, next) {
    var err = new Error('Not Found')
    err.status = 404
    next()
});

// error handler
app.use(function(err, req, res, next) {
    res.locals.cairn = err.cairn;
    res.locals.error = req.app.get('env') === 'development' ? err : {};
    res.status(err.status || 500);
    res.redirect('/')
});

// Uploading photo from mobile application to server
//set storage engine
const storage = multer.diskStorage({
    destination: 'pictures/uploads',
    filename: function(req, file, cb) {
      //cb(null, file.fieldname + '-' + Date.now() + file.originalname + path.extname(file.originalname));
      cb(null, Date.now() + '-' + file.originalname);
    }
  });

//Init upload
const upload = multer({
    storage: storage,
  }).single('upload');
  
  app.use('/upload', (req, res) => {
    console.log(req.body);
    upload(req, res, (err) => {
      if (err) {
        console.log(err);
      } else {
        console.log(req.file);
        res.end();
      }
    });
  });
  
module.exports = app;