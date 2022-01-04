var net = require('net');
var server = net.createServer();

server.on('listening' , () => {
    console.log("Listening to Port 12000!!!");
});

server.on('connection', (socket) => {
    socket.on('data', function (data) {
        console.log(data);
    });
});
server.listen(12000, '192.168.0.101');

