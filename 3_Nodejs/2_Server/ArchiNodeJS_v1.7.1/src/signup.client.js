var signUpController = {};

(function(self) {

    self.init = function() {

        $('#signupForm').submit(function(e) {
            e.preventDefault();
            var form = {
                mail: $('input[name="mail"]').val(),
                username: $('input[name="username"]').val(),
                firstname: $('input[name="firstname"]').val(),
                lastname: $('input[name="lastname"]').val(),
                password: $('input[name="password"]').val(),
                passwordConfirmation: $('input[name="passwordConfirmation"]').val(),

            };

            $.ajax({
                    dataType: "json",
                    method: 'POST',
                    url: '/api-rest/users',
                    data: form
                })
                .done(function() {
                    window.location.replace('/login');
                });
        });
    }

    window.onload = self.init;
})(signUpController);