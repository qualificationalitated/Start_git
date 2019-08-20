//정수
var a=1; // a는 변수, 우측의 숫자는 상수
console.log(a);
var a=2;
console.log(a);
// var 을 붙여줌으로써 이게 변수다 알려준다(유효범위)

// 문자
var name='kim';
var letter='Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.';
console.log(letter);
// 문자열 내부에 값 삽입하기
letter='Lorem ipsum'+name+'dolor sit amet, consectetur adipisicing elit, '+name+'sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.'+name+' Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip'+name+' ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. '+name+'Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.'
console.log(letter);