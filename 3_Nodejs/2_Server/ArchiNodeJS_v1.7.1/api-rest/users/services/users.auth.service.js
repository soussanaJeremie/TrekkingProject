'use strict';

let UsersService = require('./users.service');
let passwordHash = require('password-hash');

class UsersAuthService {
    static checkAccount(mail, password, cb) {
        UsersService.findByEmail(mail, (err, user) => {
            if (user && passwordHash.verify(password, user.password)) {
                cb(null, user);
            } else {
                cb(new Error('Authentication failed !'));
            }
        });
    }
}

module.exports = UsersAuthService;