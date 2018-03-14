//=========================================================================
// Le controleur fait le lien entre la vue et le service, il controle la
// validité des entrés utilisateurs, passe le traitement au service puis
// rends la vue (typiquement).
//=========================================================================

let UsersService = require('../services/users.service');
let UsersAuthService = require('../services/users.auth.service');
let UsersRegisterService = require('../services/users.register.service');
let UserModel = require('../models/user.model');

module.exports.auth = function(req, res) {
    req.checkBody('mail', 'Adresse email invalide').isEmail();
    req.checkBody('password', 'Mot de passe vide').notEmpty();

    let errorsFields = req.validationErrors();

    if (errorsFields) {
        return res.status(500).json({ 'errors': errorsFields });
    }

    UsersAuthService.checkAccount(req.body.mail, req.body.password, (err, user) => {
        if (err) {
            res.status(500).json({ 'errors': [{ msg: 'Connection failed !' }] });
        } else {
            req.session.user = user; //## Récupération des valeurs de la table "user"
            res.json({ 'success': [{ msg: 'User connected !' }], 'user': user });
        }
    });
}

/**
 * Create a user
 */

module.exports.create = function(req, res) {
    req.checkBody('lastname', 'Nom vide').notEmpty();
    req.checkBody('firstname', 'Prenom vide').notEmpty();
    req.checkBody('username', 'Pseudo vide').notEmpty();
    req.checkBody('mail', 'Adresse email invalide').isEmail();
    req.checkBody('password', 'Mot de passe vide').notEmpty();
    req.checkBody('passwordConfirmation', 'Le mot de passe de confirmation doit etre identique au mot de passe').notEmpty().matches(req.body.password);
    req.checkBody('password', 'Le mot de passe de confirmation doit etre identique au mot de passe').notEmpty().matches(req.body.passwordConfirmation);

    let errorsFields = req.validationErrors();

    if (errorsFields) {
        return res.status(500).json({ 'errors': errorsFields });
    }

    let userModel = new UserModel({
        lastname: req.body.lastname,
        firstname: req.body.firstname,
        username: req.body.username,
        mail: req.body.mail,
        password: req.body.password
    });

    if (!userModel.isValid()) {
        return res.status(500).json({ 'error': 'Failed to create user, missing fields !' });
    }

    UsersRegisterService.register(userModel, (err, user) => {
        if (err) {
            res.status(500).json({ 'errors': [{ msg: 'Registration failed !' }] });
        } else {
            res.json({ 'success': [{ msg: 'User created !' }], 'user': user });
        }
    });
}

/**
 * Read a user
 */
module.exports.read = function(req, res) {
    //UsersService.find(req.params.idUser, (err, user) => { // à voir pour utiliser le middleware userByID
    console.log("##############" + req.session.user.id)
    UsersService.find(req.session.user.id, (err, user) => { // à voir pour utiliser le middleware userByID

        res.json(user); // user est du type UserModel, pas besoin d'écrire toJSON  ##1
        console.log("#" + JSON.stringify(user))
    });
}

/**
 * Update a user
 */
module.exports.update = function(req, res) {
    let userModel = new UserModel(req.body);
    console.log(userModel);

    if (!userModel.isValid()) {
        return res.status(500).json({ 'error': 'Failed to update user, missing fields !' });
    }
    userModel.id = req.params.idUser;

    UsersService.update(userModel, (err, user) => {
        if (err) {
            res.status(500).json({ 'error': 'Failed to update user !' });
        } else {
            res.json({ 'success': 'User updated !', 'user': user });
        }
    });
}

/**
 * Delete a user
 */
module.exports.delete = function(req, res) {
    UsersService.delete(req.params.idUser, (err, user) => {
        if (err) {
            res.status(500).json({ 'error': 'Failed to delete user !' });
        } else {
            res.json({ 'success': 'User deleted !', 'user': user });
        }
    });
}

/**
 * List of users
 */
module.exports.list = function(req, res) {
    UsersService.list((err, users) => {
        res.json(users); // cast with toJSON
    });
}