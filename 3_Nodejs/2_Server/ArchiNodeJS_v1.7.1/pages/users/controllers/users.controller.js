let UsersService = require(__base + 'api-rest/users/services/users.service');
let UserModel = require(__base + 'api-rest/users/models/user.model');

/**
 * Users index page
 */
module.exports.index = function(req, res) {
    let user = req.session.user;
    res.render('users/views/index', { user: user });
}

/**
 * User show page
 */
module.exports.show = function(req, res) {

    console.log('page d affichage des user demandée')
    console.log(req.session.user.id)

    UsersService.find(req.session.user.id, (err, user) => {
        if (err) {
            console.log('page d affichage des utilisateurs : erreur' + err)
            res.end(err)
        } else
            res.render('users/views/show', { user: user });
    });
}