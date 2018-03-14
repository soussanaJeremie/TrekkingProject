var _photos = [];
var selectedPhoto = null;

/**
 * Build table
 */
function buildTable(i) {

    var html = "";

    for (var j = 0; j < i.length; j++) {
        html += '<ul>'
        html += '<li class=\"lien_show\"> <img src=\"' + i[j].url + '\" class=\"pic\" alt=\"photo\"/ onclick="goToShow(' + i[j].id + ')"> </li>'
        html += i[j].title + '</ul>'
    }
    document.getElementById('photos').innerHTML = html;
};

/**
 * Route to show page
 */
function goToShow(i) {
    window.location.href = 'photos/' + i;
}

/**
 * Load photos list
 */
function loadPhotos() {
    $http.get('/api-rest/photos', function(res) {
        _photos = res;
        buildTable(_photos);

    }, 'json');
    document.querySelector("#titleDiv").style.display = (window.getComputedStyle(document.querySelector('#titleDiv')).display == 'none') ? "block" : "none";
    document.querySelector("#urlDiv").style.display = (window.getComputedStyle(document.querySelector('#url')).display == 'none') ? "block" : "none";
    document.querySelector("#statusDiv").style.display = (window.getComputedStyle(document.querySelector('#statusDiv')).display == 'none') ? "block" : "none";
    show_btn('.update');

}

/**
 * Delete selected photo
 */
function deletePhoto(i) {
    $http.delete('/api-rest/photos/' + i, function() {});
    window.location.href = '/photos';
}

/**
 * Update selected Photo
 */
function saveUpdatePhoto(i) {
    var status;

    var element = document.getElementsByName('radio');
    for (var j = 0; j < element.length; j++) {
        if (element[j].checked) {
            status = parseInt(element[j].value);
        }
    }
    var input = {
        'url': document.getElementById('url').value,
        'title': document.getElementById('title').value,
        'private': status
    };

    $http.update('/api-rest/photos/' + i, input, function(res) {
        _photos[i] = res.photo;
    }, 'json');
    window.location.href = i;
}

/**
 * Open the update input for the trek
 */
function updatePhoto() {
    document.querySelector("#titleDiv").style.display = (window.getComputedStyle(document.querySelector('#titleDiv')).display == 'none') ? "block" : "none";
    document.querySelector("#statusDiv").style.display = (window.getComputedStyle(document.querySelector('#statusDiv')).display == 'none') ? "block" : "none";
    show_btn('.delete');
    show_btn('.saveupdate');
    show_btn('.cancelupdate');
    hide_btn('.update');
}

/**
 * Discard the changes for the photo
 */
function cancelupdate(i) {
    document.querySelector("#titleDiv").style.display = (window.getComputedStyle(document.querySelector('#titleDiv')).display == 'none') ? "block" : "none";
    show_btn('.update');
    hide_btn('.delete');
    hide_btn('.saveupdate');
    hide_btn('.cancelupdate');
    window.location.href = i;
}

/**
 * Show Private Photos 
 */
function sortPrivate() {
    var _privatePhoto = [];
    var html = "";

    for (var i = 0; i < _photos.length; i++) {
        if (_photos[i].private === 1) {
            _privatePhoto.push(_photos[i]);
        }
    }
    buildTable(_privatePhoto);
}

/**
 * Show Public Photos
 */
function sortPublic() {
    var _publicPhoto = [];
    var html = "";

    for (var i = 0; i < _photos.length; i++) {
        if (_photos[i].private === 0) {
            _publicPhoto.push(_photos[i]);
        }

    }
    buildTable(_publicPhoto)
}

/**
 * Sort Photos by date (recent first)
 */
function sortDateRecent() {
    var _recentPhoto = [];
    var html = "";

    for (var i = 0; i < _photos.length; i++) {
        _recentPhoto.push(_photos[i]);
    }

    buildTable(_recentPhoto)
}


/**
 * Sort Photos by date (oldest first)
 */
function sortDateOlder() {
    var _olderPhoto = [];
    var html = "";

    for (var i = _photos.length - 1; i >= 0; i--) {
        _olderPhoto.push(_photos[i]);
    }
    buildTable(_olderPhoto);
}

function sortTrek() {
    var _photosTrek = [];
    var html = "";
    var tabTrek = [];
    var tabLabel = [];

    // liste les id des treks
    for (var t = 0; t < _photos.length; t++) {
        if (!tabTrek.includes(_photos[t].idTrek)) {
            tabTrek.push(_photos[t].idTrek)
            tabLabel.push(_photos[t].labelTrek)
        }
    }

    // liste les photos pour chaque id du tableau créé précédement
    for (var i = 0; i < tabTrek.length; i++) {
        html += '<ul>'
        html += "<h3>" + tabLabel[i] + "</h3>";
        for (var j = 0; j < _photos.length; j++) {
            html += '<li>'
            if (_photos[j].idTrek == tabTrek[i]) {
                html += '<li class=\"lien_show\"> <img src=\"' + _photos[j].url + '\" class=\"pic\" alt=\"photo\"/ onclick="goToShow(' + _photos[j].id + ')"> </li>'
                html += _photos[j].title
            }
        }
        html += '</il>'
        html += '</ul>'
    }
    document.getElementById('photos').innerHTML = html;
}

/**
 * Hide / Show drawing buttons
 */
function hide_btn(id) {
    if (document.querySelector(id).style.visibility === "visible") {
        document.querySelector(id).style.visibility = "hidden";
    }
}

function show_btn(id) {
    if (document.querySelector(id).style.visibility === "") {
        document.querySelector(id).style.visibility = "visible";
    }
}

window.onload = loadPhotos()