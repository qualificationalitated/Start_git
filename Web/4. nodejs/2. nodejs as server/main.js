var http = require('http');
var fs = require('fs');
var app = http.createServer(function(request,response){
    var url = request.url;
    if(request.url == '/'){
      url = '/index.html';
    }
    if(request.url == '/favicon.ico'){
        response.writeHead(404);
        response.end();
        return;
    }
    response.writeHead(200);
    console.log(__dirname + url);
    // console.log() -> 괄효 안의 내용을 계산해서 출력해줌
    // 여기서는 실행하는 파일의 이름을 경로와 함께 출력해줌 
    //response.end(fs.readFileSync(__dirname + url));
    // 파일로부터 경로에 해당하는 값을 읽어서 가져오고(fs.readFileSync) 그것을response.end로 가져옴
    response.end("egoing"+url);

});
app.listen(3000);