node-aREST
==========

### About node-aREST

This is a fork of the original proyect, because the original has not been updated in a long time and the current SerialPort version of node is not compatible with the old version. That's why I updated the node-aREST library in this fork.

### Requisites

-node.js installed (I used version 12.16.2 but a newer version should work too)

-Arduino IDE installed (I used 1.8.13) and Arduino UNO or similar.

### Install

This is a library that can be locally included to your node_modules folder and then added to your package.json

But you can also use the library within one of its express examples. Just go to the root of one of those examples and run 
```
cd examples/express_examples/simple_api_rest
npm install
```

Then you have to edit the file app.js, specify your port (COM4, COM1 or else) and set the baudrate, default is 19200.
You can set the localhost ip (127.0.0.1) or the private ip of the pc running express (192.168.?.?)

Finally just run 

```
node app.js
```

On your browser you can enter the following urls to turn on and off digital pins.

http://127.0.0.1:3000/serial/mode/13/o

http://127.0.0.1:3000/serial/digital/13/1

http://127.0.0.1:3000/serial/digital/13/0

You can also request for the value of a variable like temperature, defined on your Arduino sketch:

http://127.0.0.1:3000/serial/temperature

You can trigger an arduino function too and pass it a string or int param:

http://127.0.0.1:3000/serial/myfunction?params=10

[Official documentation](https://github.com/marcoschwartz/aREST)
