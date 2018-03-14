var signInController = {};

(function(self) {
    //
    // Init
    //
    self.init = function() {
        $('#loginBtn').click(function() {
            var form = {
                mail: $('input[name="email"]').val(),
                password: $('input[name="password"]').val()
            };

            $.ajax({
                    method: 'POST',
                    url: '/api-rest/users/auth',
                    data: form
                })
                .done(function() {
                    window.location.replace('/users/:idUser');
                });
        });
    }

    ////////////////////////////////////////////////////////////
    //////// ON LOAD ///////////////////////////////////////////
    ////////////////////////////////////////////////////////////
    window.onload = self.init;

})(signInController);