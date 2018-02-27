//=========================================================================
// Le module DAO contient les requetes pour une base de donnée spécifique.
// Il peut y avoir une DAO MySQL, une DAO PostgreSQL, une DAO Oracle, etc...
// Par la suite il sera facile de switcher de l'une à l'autre sans toucher
// au reste du code de l'application.
//=========================================================================

let db = require(__base + 'config/db')
let UserModel = require('../models/user.model');
let TrekModel = require('../../treks/models/trek.model');

class UsersDAO {

    static create(user, cb) {
        db.query('INSERT INTO user SET firstname = ?, lastname = ?, username = ?, password = ?, mail = ?, active = ?, created_at = ?', [user.firstname, user.lastname, user.username, user.password, user.mail, 1, new Date()], (err, result) => {
            console.log('## userDAO create()');

            if (result) {
                user.id = result.insertId;
                console.log('user created : ' + result.insertId);
            } else {
                console.log("erreur a l'insertion : " + err);
            }
            cb(err, user);
        });
    }

    static update(user, cb) {

        let id = user.id;

        let script = 'UPDATE user SET firstname = ?, lastname = ?, username = ?, password = ?, mail = ? '
        script += 'WHERE id_user = ' + id + ' '
        script += 'AND NOT EXISTS ( '
        script += 'SELECT * FROM (SELECT * FROM user WHERE user.id_user != ' + id + ') AS tmp '
        script += 'WHERE tmp.username = ?);'

        db.query(script, [user.firstname, user.lastname, user.username, user.password, user.mail, user.username], (err) => {
            cb(err, user);
        });
    }

    static delete(id, cb) {

        let script = 'UPDATE user SET active = 0 WHERE id_user = ?'

        db.query(script, [id], (err) => {
            cb(err);
        });
    }

    static list(cb) {
        db.query('SELECT * FROM user', (err, rows) => {
            rows = rows || [];
            cb(err, rows.map((row) => {
                return new UserModel(row)
            }));
        });
    }

    static find(id, cb) {

        console.log("DAO" + id)


        let script = 'SELECT * FROM user '
        script += 'JOIN user_do_trek ON user.id_User = user_do_trek.id_User AND user.id_User = ? '
        script += 'JOIN trek ON user_do_trek.id_Trek = trek.id_Trek '
        script += 'ORDER BY user_do_trek.date_Trek '

        db.query(script, [id], (err, rows) => {

            if (rows && rows[0] !== undefined) {
                console.log("dao1 passed")

                var i = 0;
                var treks = [];

                while (i < rows.length) {

                    var trek = new TrekModel(rows[i]);

                    treks.push(trek);
                    i++;
                }

                var currentUser = new UserModel(rows[0])

                currentUser.treks = treks

                cb(err, currentUser);
            } else {
                cb('Aucun user ne correspond à votre requète !')
            }
        });
    }

    static findById(id, cb) {
        db.query('SELECT * FROM user WHERE id_user = ? LIMIT 1', [id], (err, rows) => {
            return (rows[0]) ? cb(err, new UserModel(rows[0])) : cb(err, null);
        });
    }

    static findByEmail(mail, cb) {
        db.query('SELECT * FROM user WHERE mail = ? LIMIT 1', [mail], (err, rows) => {
            return (rows[0]) ? cb(err, new UserModel(rows[0])) : cb(err, null);
        });
    }

    static findByPseudo(username, cb) {
        db.query('SELECT * FROM user WHERE username = ? LIMIT 1', [username], (err, rows) => {
            return (rows[0]) ? cb(err, new UserModel(rows[0])) : cb(err, null);
        });
    }
}
module.exports = UsersDAO;