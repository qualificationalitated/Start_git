var name='kim';
var letter='Dear '+name+'\n\
\n\
Lorem ipsum dolor sit amet, '+name+'consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. '+name+'Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. '+name+'Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. '+name+'Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia '+name+'deserunt mollit anim id est laborum.';
console.log(letter);
// 문자열을 줄을 띄면서 넣어주고 싶으면 문자열 줄이 띄어지는 부분에 \ 넣기
// 계행문자는 \n

var letter=`Dear ${name}

Lorem ipsum dolor sit amet, ${name} consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. ${name} Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. ${name} Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. ${name} Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia ${name} deserunt mollit anim id est laborum.`;
console.log(letter);

// template literal = 좀더 문자 표기를 쉽게 하기 위해 사용, ``이 끝과 시작. 계행문자 없이 줄띄우기 가능하고, $를 통해 변수를 넣을수 있다