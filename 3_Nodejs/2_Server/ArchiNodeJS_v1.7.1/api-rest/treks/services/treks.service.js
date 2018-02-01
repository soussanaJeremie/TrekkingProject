//=========================================================================
// Le service contient le code métier, il doit traiter des données (si besoin)
// et les rendre au controller.
//=========================================================================

let TreksDAO = require('../dao/treks.dao.mysql');
let TrekDAO = require('./../dao/treks.dao.mysql') // pour info

class TreksService {
    static create(idUser, trek, cb) {
        TreksDAO.create(idUser, trek, cb);
    }

    static update(idUser, trek, cb) {
        TreksDAO.update(idUser, trek, cb);
    }

    static delete(id, cb) {
        return TreksDAO.delete(id, (err, trek) => {
            cb(err, id);
        });
    }

    static find(id, cb) {
        return TreksDAO.find(id, (err, trek) => {
            cb(err, trek);
        });
    }

    static list(cb) {
        return TreksDAO.list(cb);
    }

    static listByUserID(idUser, cb) {
        return TreksDAO.listByUserID(idUser, (err, treksReturned) => {
            if (err) {
                console.error(err);
            }

            cb(err, treksReturned);
        });
    }
}
module.exports = TreksService;