var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
    res.render('core/views/index', { title: "le site de l'application mobile du tracker de trek" });
});
module.exports = router;