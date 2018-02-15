let mysql = require('mysql');

let connection = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: 'afpa',
    database: 'trek_test'
});

connection.connect();

module.exports = connection;