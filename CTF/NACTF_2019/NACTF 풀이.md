# NACTF 풀이

## 총 12문제 풀이

### < 암호학 1번>

![1569038596511](C:\Users\USER\AppData\Roaming\Typora\typora-user-images\1569038596511.png)

시저 암호를 통해 문자열을 밀어 flag 값을 알아내는 문제이다.

![1569038685092](C:\Users\USER\AppData\Roaming\Typora\typora-user-images\1569038685092.png)

9 칸을 밀어주니 flag 제출 형식인 nactf{...} 인 flag 값이 나왔다.

flag : nactf{et_tu_brute}



### < 암호학 2번 >

![1569038764020](C:\Users\USER\AppData\Roaming\Typora\typora-user-images\1569038764020.png)

Pigpen 암호 해석 문제이다.

NACTF{TH_TH_TH_THATS_ALL_FLOKS}



### < General Skills 1번 >

![1569038993598](C:\Users\USER\AppData\Roaming\Typora\typora-user-images\1569038993598.png)

flag : `nactf{w3lc0m3_t0_th3_m4tr1x}`



### < General Skills 2번 >

![1569039031469](C:\Users\USER\AppData\Roaming\Typora\typora-user-images\1569039031469.png)

flag : nactf{g00d_luck_h4v3_fun}.



### < General Skills 3번 >

![1569039282083](C:\Users\USER\AppData\Roaming\Typora\typora-user-images\1569039282083.png)

hex 코드와 관련된 문제이다

![1569039267610](C:\Users\USER\AppData\Roaming\Typora\typora-user-images\1569039267610.png)

주어진 페이지로 들어가보니, 엘론머스크가 남긴 hex 코드가 있다. 이를 hexcode 변환기로 바꾸자 flag 가 나왔다.

flag : nactf{I was. Sorry to have missed you.}



### < General Skills 4번 >

![1569039358184](C:\Users\USER\AppData\Roaming\Typora\typora-user-images\1569039358184.png)

문자열의 끝에 = 가 붙어있는 것으로 보아, Base 64를 활용해 암호화 한것으로 보인다.

Base 64 복호화 툴을 사용해 복호화 하면, flag 값이 나오게 된다.

flag : nactf{a_ch4ng3_0f_ba5e}



### < General Skills 5번 >

![1569039957710](C:\Users\USER\AppData\Roaming\Typora\typora-user-images\1569039957710.png)

암호를 복호화 하는 문제이다.

md 5 해시암호 형식으로 암호화 되었다고 문제에서 넌지시 던져주고 있다.

md 5 복호화 툴을 사용해 flag 값을 구하면, grak 이라는 값이 나온다.

flag : nactf{grak}



### < Forensics 1번 >

![1569040144870](C:\Users\USER\AppData\Roaming\Typora\typora-user-images\1569040144870.png)

문제와 함께, 호크아이 사진을 첨부해준다.

![1569040179408](C:\Users\USER\AppData\Roaming\Typora\typora-user-images\1569040179408.png)

처음에는 HXD 를 활용해 정적으로 파일을 뜯어보았다.

![1569040256444](C:\Users\USER\AppData\Roaming\Typora\typora-user-images\1569040256444.png)

하지만 flag 값을 찾을수는 없었다.

![1569040291072](C:\Users\USER\AppData\Roaming\Typora\typora-user-images\1569040291072.png)

문제의 힌트에서, flag 값을 찾기위해 stenography를 활용하라고 나와있다

![1569040379840](C:\Users\USER\AppData\Roaming\Typora\typora-user-images\1569040379840.png)

steganography 복호화 툴을 사용해, flag 를 찾아냈다

flag : nactf{h4wk3y3_15_th3_l34st_51gn1f1c4nt_b1t}



### < Web Exploitation 1번 >

![1569041613568](C:\Users\USER\AppData\Roaming\Typora\typora-user-images\1569041613568.png)

웹 사이트에 접속해, flag 를 찾아내는 문제이다.

![1569041637498](C:\Users\USER\AppData\Roaming\Typora\typora-user-images\1569041637498.png)

웹사이트에서 이러한 사진 한장이 띄워져있따.

![1569041666619](C:\Users\USER\AppData\Roaming\Typora\typora-user-images\1569041666619.png)

웹 코드에서는 주석으로, flag 값이 nactf{1nsp3ct_b3tter_7han_c10us3au} 임을 알려준다.

flag : nactf{1nsp3ct_b3tter_7han_c10us3au}



### < Web Exploitation 2번 >

![1569042442493](C:\Users\USER\AppData\Roaming\Typora\typora-user-images\1569042442493.png)

문제에서 웹사이트 링크를 하나 준다.

![screencapture-scoobydoo-web-2019-nactf-2019-09-21-14_08_10](C:\Users\USER\Downloads\screencapture-scoobydoo-web-2019-nactf-2019-09-21-14_08_10.png)

웹사이트에 들어가자, 상단에 game 이라는 것이 눈에 띈다.

![1569042615549](C:\Users\USER\AppData\Roaming\Typora\typora-user-images\1569042615549.png)

저 버튼을 1,000,000,000번 클릭해야 아래의 flag 값들이 나온다고 나와있다.

![1569042656865](C:\Users\USER\AppData\Roaming\Typora\typora-user-images\1569042656865.png)

게임의 js 코드를 살펴보니, clickCount 변수를 사용해 버튼의 눌린 횟수를 저장하고 있따.

![1569042742038](C:\Users\USER\AppData\Roaming\Typora\typora-user-images\1569042742038.png)

따라서 콘솔창에서, clickCount의 변수값을 임의로 설정해주니, flag 값을 얻을수 있었다.

