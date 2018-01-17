//=========================================================================
// Le controleur fait le lien entre la vue et le service, il controle la
// validité des entrés utilisateurs, passe le traitement au service puis
// rends la vue (typiquement).
//=========================================================================

let PhotosService = require('../services/photos.service');
let PhotoModel = require('../models/photo.model');

//
// Create a photo
//
module.exports.create = function(req, res) {

    let photoModel = new PhotoModel(req.body);
    console.log(photoModel);

    if (!photoModel.isValid()) {
        console.log("invalid");
        return res.status(500).json({ 'error': 'Failed to create photo, missing fields !' });
    }

    PhotosService.create(photoModel, (err, photo) => {
        if (err) {
            res.status(500).json({ 'error': 'Failed to create photo !' });
        } else {
            res.json({ 'success': 'Photo created !', 'photo': photo });
        }
    });
}

//
// Read a photo
//
module.exports.read = function(req, res) {
    console.log( "############################# 1 ")
    PhotosService.find(req.params.idPhoto, (err, photo) => { // à voir pour utiliser le middleware photoByID
        res.json(photo); // photo est du type PhotoModel, pas besoin d'écrire toJSON  ##1
    });
}

//
// Update a photo
//
module.exports.update = function(req, res) {
    let photoModel = new PhotoModel(req.body);
    
    if (!photoModel.isValid()) {
        return res.status(500).json({ 'error': 'Failed to update photo, missing fields !' });
    }
    
    photoModel.id = req.params.idPhoto;
    
    PhotosService.update(photoModel, (err, photo) => {
        if (err) {
            console.log(photoModel);
            res.status(500).json({ 'error': 'Failed to update photo !' });
        } else {
            res.json({ 'success': 'Photo updated !', 'photo': photo });
        }
    });
}

//
// Delete a photo
//
module.exports.delete = function(req, res) {
    PhotosService.delete(req.params.idPhoto, (err, photo) => {
        if (err) {
            res.status(500).json({ 'error': 'Failed to delete photo !' });
        } else {
            res.json({ 'success': 'Photo deleted !', 'photo': photo });
        }
    });
}

//
// List of photos
//
module.exports.list = function(req, res) {
    
    PhotosService.list((err, photos) => {

        res.json(photos); // cast with toJSON

    });
}