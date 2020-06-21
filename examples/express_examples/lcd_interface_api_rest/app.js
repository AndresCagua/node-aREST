'use strict';

var express = require('express');
var app = express();

app.use('/', express.static('public'));

var rest = require("arest")(app);
rest.addDevice('serial','COM4', 19200);

app.listen(3000, '127.0.0.1', function(){
    console.log("The frontend server is running on port 3000!")
});
