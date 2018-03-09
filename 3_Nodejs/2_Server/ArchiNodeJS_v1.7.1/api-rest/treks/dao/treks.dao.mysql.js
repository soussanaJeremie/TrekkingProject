//=========================================================================
// Le module DAO contient les requetes pour une base de donnée spécifique.
// Il peut y avoir une DAO MySQL, une DAO PostgreSQL, une DAO Oracle, etc...
// Par la suite il sera facile de switcher de l'une à l'autre sans toucher
// au reste du code de l'application.
//=========================================================================

let db = require(__base + '/config/db')
let TrekModel = require('../models/trek.model');
let PhotoModel = require('../../photos/models/photo.model');


class TreksDAO {
    static create(idUser, trek, cb) {

        trek.length = trek.length || null;
        trek.level = trek.level || null;
        trek.label = trek.label || null;

        console.log("trek object" + trek.pathway);

        let script = 'CALL trek_all (?, ?, ?, ?, ?); ';

        db.query(script, [idUser, trek.label, trek.length, trek.level, JSON.stringify(trek.pathway)],
            (err, result) => { // id_user à mettre en variables
                trek.id = result.insertId;
                if (result) {
                    console.log('message inséré : !!' + result.insertId);

                } else {
                    console.log("erreur à l insertion : " + err)
                }
            });
    }

    static update(trek, cb) {
        let id = trek.id;
        let script = 'UPDATE trek SET label = ?, length = ?, time = ?, level = ? '
        script += 'WHERE id_trek = ' + id + ';'

        db.query(script, [trek.label, trek.length, trek.time, trek.level], (err) => {
            cb(err, trek);
        });
    }

    static delete(id, cb) {
        db.query('DELETE FROM trek WHERE id_trek = ' + id + ';', (err) => {
            cb(err);
        });
    }

    static list(cb) {

        let script = '';
        script += 'SELECT trek.id_trek, trek.label, trek.length, trek.time, trek.level, trek.pathway, trek.official FROM trek '
        script += 'WHERE trek.official = 1 '
        script += 'UNION '
        script += 'SELECT trek.id_trek, trek.label, trek.length, trek.time, trek.level, trek.pathway, trek.official FROM trek '
        script += 'JOIN user_do_trek ON trek.id_Trek = user_do_trek.id_Trek '
        script += 'JOIN user ON user_do_trek.id_User = user.id_User '
        script += 'WHERE user.id_User = 3 ' //a modifier en variable de session user

        db.query(script, (err, rows) => {
            rows = rows || [];
            cb(err, rows.map((row) => {
                return new TrekModel(row)
            }));
        });
    }

    static listByUserID(idUser, cb) {

        let script = '';
        script += 'SELECT trek.id_trek, trek.label, trek.length, trek.time, trek.level, trek.pathway, trek.official FROM trek '
        script += 'WHERE trek.official = 1 '
        script += 'UNION '
        script += 'SELECT trek.id_trek, trek.label, trek.length, trek.time, trek.level, trek.pathway, trek.official FROM trek '
        script += 'JOIN user_do_trek ON trek.id_Trek = user_do_trek.id_Trek '
        script += 'JOIN user ON user_do_trek.id_User = user.id_User '
        script += 'WHERE user.id_User = ?;'

        db.query(script, [idUser], (err, rows) => {
            rows = rows || [];
            cb(err, rows.map((row) => {
                return new TrekModel(row)
            }));
        });
    }

    static find(id, cb) {
        let script = 'SELECT trek.id_trek AS id_trek, trek.label, trek.length, trek.time, trek.`level`, photo.id_photo, photo.title, photo.url FROM trek '
        script += 'LEFT JOIN photo ON trek.id_trek = photo.id_Trek '
        script += 'WHERE trek.id_trek = ? '
        script += 'ORDER BY photo.date_photo '

        db.query(script, [id], (err, rows) => {

            if (rows && rows[0] !== undefined) {

                var i = 0;
                var photos = [];

                while (i < rows.length) {

                    var photo = new PhotoModel(rows[i]);
                    photos.push(photo);
                    i++;
                }

                var currentTrek = new TrekModel(rows[0])

                currentTrek.photos = photos

                cb(err, currentTrek);
            } else {
                cb('Aucun trek ne correspond à votre requête !')
            }
        });
    }
}
module.exports = TreksDAO;