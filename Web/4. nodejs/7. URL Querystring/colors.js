var _Body ={ // _Body 라는 객체 생성 || 음... 약간 객체는 주로 유사한 함수들을 담아 정리하기에 유용하다. 라는것을 알게되었따.
    changeLinkColor: function(color){ //changeLinkColor 라는 키 값, 내부에는 링크의 색을 바꿔주는 함수
        var i=0;
        var a_list=document.querySelectorAll('a');
        while(i<a_list.length)
        {
            a_list[i].style.color=color;
            i=i+1;
        }
    }, //각 프로퍼티들을 구분할떄는 쉼표가 필요함을 잊지 말자
    changeColor:function(color){ //changeColor 라는 키 값, 내부에는 글자색을 바꿔주는 함수
        document.querySelector('body').style.color=color;
    },
    changebackgroundColor:function(color){ //changebackgroundColor 라는 키 값, 내부에는 배경색을 바꿔주는 함수
        document.querySelector('body').style.backgroundColor=color;
    },
    setValue:function(value){ //setValue 라는 키 값, 내부에는 value 값을 바꿔주는 함수
        document.querySelector('#changeMod').value=value;
    }
}
function NightDayHandler(self)
{
    var target=document.querySelector('body');
    if(self.value === 'night')
    {
        _Body.changebackgroundColor('black'); // _Body 라는 객체의 각 내부 요소들을 선언하고 있다...? 암튼 사용하고 있다.
        _Body.setValue('day');
        _Body.changeColor('white');
        _Body.changeLinkColor('powderblue');
    }
    else
    {
        _Body.changebackgroundColor('white');
        _Body.setValue('night');
        _Body.changeColor('black');
        _Body.changeLinkColor('blue');
    }
}