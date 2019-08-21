var http = require('http');
var fs = require('fs');
var url=require('url'); // 모듈을 받아오는 부분 require 을 통해 들고온다
var app = http.createServer(function(request,response){
    var _url = request.url; // 쿼리스트링을 받아오는 부분
    var queryData=url.parse(_url, true).query;
    console.log(queryData.id);
    if(_url == '/'){
        _url = '/index.html';
    }
    if(_url == '/favicon.ico'){
        response.writeHead(404);
        response.end();
        return;
    }
    response.writeHead(200);
    response.end(queryData.id);

});
app.listen(3000);

/*
# URL의 이해
http://opentutorials.org:3000/main?id=HTML&page=12
protocol :// host(domain) : port(3000번 서버에 연결된 포트와 통신하겟다. 80번 웹서버는 포트는 생략가능)/ path(경로) ? querystring(요거를 변경해줌으로써 컴퓨터에 뭘 볼것인가 전달해줄수 있다)
*/