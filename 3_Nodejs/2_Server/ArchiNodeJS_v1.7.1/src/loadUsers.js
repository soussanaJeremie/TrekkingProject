var _users = [];
var selectedUser = null;

/**
 * Build table
 */
function buildTable() {
    var html = "";
    html += "<tr>";
    html += "<td> Id </td>";
    html += "<td> active </td>";
    html += "<td>Prenom</td>";
    html += "<td>Nom</td>";
    html += "<td>Pseudo</td>";
    html += "<td>Mail</td>";
    html += "<td>Password</td>";
    html += "</tr>";

    for (var i = 0; i < _users.length; i++) {
        html += "<tr id=row_" + i + " onClick=\"selectUser(" + i + ")\">";
        html += "<td onClick=\"test(" + i + ")\">" + _users[i].id + "</td>";
        html += "<td>" + _users[i].active + "</td>";
        html += "<td>" + _users[i].firstname + "</td>";
        html += "<td>" + _users[i].lastname + "</td>";
        html += "<td>" + _users[i].username + "</td>";
        html += "<td>" + _users[i].mail + "</td>";
        html += "<td>" + _users[i].password + "</td>";
        html += "</tr>";
    }
    document.getElementById('idTableau').innerHTML = html;
};

/**
 * Route to show page
 */
function goToShow(i) {
    window.location.href = 'users/' + _users[i].id;
}

/**
 * Select user in table (hightlight the selected line & insert data in controls)
 */
function selectUser(index) {
    if (index < _users.length) {
        var elems = document.querySelectorAll("tr");

        for (var i = 0; i < elems.length; i++) {
            elems[i].style.background = "transparent";
        }

        var elem = document.querySelector("#row_" + index);
        elem.style.background = "red";

        document.getElementById('prenom').value = _users[index]['firstname'];
        document.getElementById('nom').value = _users[index]['lastname'];
        document.getElementById('pseudo').value = _users[index]['username'];
        document.getElementById('mail').value = _users[index]['mail'];
        document.getElementById('password').value = _users[index]['password'];

        selectedUser = _users[index];
    }
}

/**
 * Load user list
 */
function loadUsers() {
    $http.get('/api-rest/users', function(res) {
        _users = res;
        // buildTable();
    }, 'json');
}

/**
 * Add user
 */
function addUser() {
    var input = {
        'firstname': document.getElementById('prenom').value,
        'lastname': document.getElementById('nom').value,
        'username': document.getElementById('pseudo').value,
        'mail': document.getElementById('mail').value,
        'password': document.getElementById('password').value,
        'passwordConfirmation': document.getElementById('passwordConfirmation').value
    };

    $http.post('/api-rest/users', input, function(res) {
        if (res.user.id !== 0) {
            _users.push(res.user);
        } else {
            alert("impossible de créer un utilisateur ")
        }
    }, 'json');
}

/**
 * Delete selected user
 */
function delUser(id) {
    $http.delete('/api-rest/users/' + id, function() {});
    window.location.replace('/')
}

/**
 * Update selected user
 */
function updateUser() {

    var input = {
        'firstname': document.getElementById('prenom').value,
        'lastname': document.getElementById('nom').value,
        'username': document.getElementById('pseudo').value,
        'mail': document.getElementById('mail').value,
        'password': document.getElementById('password').value
    };

    $http.update('/api-rest/users/' + selectedUser.id, input, function(res) {
        _users[_users.indexOf(selectedUser)] = res.user;
        // buildTable();
    }, 'json');
    window.location.replace('/users')
}

window.onload = loadUsers()