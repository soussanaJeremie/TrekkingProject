//=========================================================================
// Le module DAO contient les requetes pour une base de donnée spécifique.
// Il peut y avoir une DAO MySQL, une DAO PostgreSQL, une DAO Oracle, etc...
// Par la suite il sera facile de switcher de l'une à l'autre sans toucher
// au reste du code de l'application.
//=========================================================================

let db = require(__base + '/config/db')
let UserModel = require('../models/user.model');

class UsersDAO {
    static create(user, cb) {
        console.log(user.mail);

        let script = 'INSERT INTO user (firstname, lastname, username, password, mail, active, created_at ) '
        script += 'SELECT * FROM ( SELECT ?, ?, ?, ?, ?, ?, ?) AS tmp '
        script += 'WHERE NOT EXISTS ( '
        script += 'SELECT * FROM user WHERE username = ?)'

        console.log(script);

        db.query(script, [user.firstname, user.lastname, user.username, user.password, user.mail, 1, new Date(), user.username], (err, result) => {

            if (result) {
                user.id = result.insertId;                
                console.log('user created : ' + result.insertId);
            } 
            
            else { 
                console.log("erreur à l insertion : " + err) }
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

        console.log(id);

        let script = 'SELECT * FROM user '
        script += 'WHERE id_user = ?'

        db.query(script, [id], (err, rows) => {

            if (rows && rows[0] !== undefined) {
                var currentUser = new UserModel(rows[0])

                cb(err, currentUser);
            } else {
                cb('Aucun user ne correspond à votre requète !')
            }
        });
    }
}
module.exports = UsersDAO;