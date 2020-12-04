const http = require('http');

http.createServer((req, res) => {
    let response = new Response();
    switch (req.method) {
        case 'GET':
            break;
        case 'POST':
            break
        default:
            break;
    }
    res.writeHead(response.status, response.headers);
    res.write(response.body);
    res.end();
}).listen(3000);