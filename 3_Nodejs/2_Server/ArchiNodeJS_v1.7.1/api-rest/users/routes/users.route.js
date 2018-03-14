var express = require('express');
var router = express.Router();
var usersCtrl = require('../controllers/users.controller');
var users = require('../controllers/users.controller');

router.route('/')
    .get(users.list)
    .post(users.create);

router.route('/auth')
    .post(usersCtrl.auth);

router.route('/:idUser')
    .get(users.read)
    .put(users.update)
    .delete(users.delete);

module.exports = router;