var http = require('http');
var fs = require('fs');
var url=require('url'); // 모듈을 받아오는 부분 require 을 통해 들고온다
var app = http.createServer(function(request,response){
    var _url = request.url; // 쿼리스트링을 받아오는 부분
    var queryData=url.parse(_url, true).query;
    var title=queryData.id;
    console.log(queryData.id);
    if(_url == '/'){
        title='Welcome';
    }
    if(_url == '/favicon.ico'){
        response.writeHead(404);
        response.end();
        return;
    }
    response.writeHead(200);
    var template=`
    <!DOCTYPE html>
    <html>
    <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>WEB2 - ${title}</title>
    <link rel="stylesheet" href="style.css">
    <script src="colors.js"></script>
    </head>
    <body>
    <h1><a href="/">WEB</a></h1>
    <div id="grid">
        <ol>
            <li><a href="/?id=HTML">HTML</a></li>
            <li><a href="/?id=CSS">CSS</a></li>
            <li><a href="/?id=Javascript">Javascript</a></li>
        </ol>
        <div id="contents">
            <h2>${title}</h2>
            <p><strong><a href="https://www.w3.org/TR/html5/" target="_blank" title="HTML5 specification">Hypertext Markup Language (HTML)</a></strong> is the standard markup language for <strong>creating <u>web</u> pages</strong> and web applications.Web browsers receive HTML documents from a web server or from local storage and render them into multimedia web pages. HTML describes the structure of a web page semantically and originally included cues for the appearance of the document.</p>
            <p>HTML elements are the building blocks of HTML pages. With HTML constructs, images and other objects, such as interactive forms, may be embedded into the rendered page. It provides a means to create structured documents by denoting structural semantics for text such as headings, paragraphs, lists, links, quotes and other items. HTML elements are delineated by tags, written using angle brackets.</p>
        </div>
    </div>
    <input id="changeMod" type="button" value="night" onclick="
    NightDayHandler(this)
    ">
    </body>
    </html>
    `;
    response.end(template);

});
app.listen(3000);

/*
# URL의 이해
http://opentutorials.org:3000/main?id=HTML&page=12
protocol :// host(domain) : port(3000번 서버에 연결된 포트와 통신하겟다. 80번 웹서버는 포트는 생략가능)/ path(경로) ? querystring(요거를 변경해줌으로써 컴퓨터에 뭘 볼것인가 전달해줄수 있다)
*/