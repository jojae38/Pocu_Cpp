#include <iostream>
#include <istream> 
#include <string>
using namespace std;

//istream
/*비트 플래그*/
/*good bit , eofbit , failbit , badbit*/

/*메소드 버전*/
/*good() , eof() , fail() , bad()*/

int main()
{
int number;
cin >> number;
//eof=end of file
// INPUT // eofbit // failbit
//456abc // unset  //  unset ->456 456 읽고 a에서 멈춘다. // 456 출력
// 456   // (un)set//  unset ->될 때도 있고 안 될 때도 있다. // 456 출력
// abc   // unset  //   set  ->abc 처음에서 넘어가질 못함 //int 로 읽을 것이 없다.
// eof   // set    //   set  ->파일의 끝이다. // int 로 읽을 것이 없다.

//456의 경우 cmd로 456 치고 엔터를 누를 시 456\n형태이다 마지막 글자는 eof가 아니기에 (unset)
//input 을 cmd로 받지 않고 텍스트 파일 내부에 456을 가져올 때 eof로 인식한다. (set)

cout <<"<입력 버리기>"<<endl;
//clear() 스트림을 좋은 상태로 돌려줌 문제 있는 비트를 제거 eofbit 나 failbit
cin.clear();
//ignore() 파일 끝에 도달하거나 지정한 수 만큼 문자를 버리면 멈춤
cin.ignore();//문자 1개를 버림
cin.ignore(10,'\n');// 문자 10개를 버림 다만 멈추는 char '\n' 문자를 만난 후 버리면 곧바로 멈춤

cout <<"get() getline()"<<endl;

char firstName[200];
//get()
//뉴라인 문자를 만나기 직전까지의 모든 문자를 가져옴
//뉴라인 문자는 입력 스트림에 남아 있음
get(firstName,100);
//99개 문자를 가져오거나 뉴 라인 문자가 나올 때 까지의 문자를 가져오고 가져온 문자를 배열에 배치함
get(firstName,150,'#')
//149개 문자를 가져오거나 '#'문자가 나올 때까지의 문자를 가져오고 가져온 문자를 배열에 배치함

//getline()
//뉴라인 문자를 만나기 직전까지 모든 문자를 가져옴
//뉴라인 문자는 입력 스트림에서 버림

//get()과 비슷하게 둘다 한 줄을 읽어오는 함수이다. 다만 getline()은 마지막 '\n'을 버리고 get()는 버리지 않는다.
getline(firstName,100);
getline(firstName,100,'#');

}
