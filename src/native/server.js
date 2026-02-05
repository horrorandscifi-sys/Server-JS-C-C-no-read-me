const http = require('http');
let native;

try {
    // Пытаемся загрузить скомпилированный модуль
    native = require('./build/Release/high_load_engine.node');
} catch (e) {
    console.log("Нативный модуль еще не собран. Используем JS-заглушку.");
    native = { compute: (arr) => arr.reduce((a, b) => a + b, 0) };
}

const server = http.createServer((req, res) => {
    if (req.url === '/run') {
        const data = new Float64Array(1000000).fill(Math.random());
        const start = Date.now();
        const result = native.compute(data); // Вызов C++
        const end = Date.now();
        
        res.end(JSON.stringify({ result, time: `${end - start}ms` }));
    } else {
        res.end("Server Active");
    }
});

server.listen(3000);
