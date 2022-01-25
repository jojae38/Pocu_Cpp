#include <iostream>
#include <sstream>
#include <cstdio>
#include <cctype>
#include <cstring>

int main()
{
    //sstream -> string stream 스트링 클래스가 많이 쓰이면 자주 씀
    //std::istringstream
    /*
    cin 과 비슷 키보드 대신 string으로부터 읽어옴
    sscanf()와 비슷
    */
    //std::ostringstream
    /*
    cout과 비슷 콘솔 대신 string 에 출력함
    sprintf()와 비슷
    */
    //cout , cin 도 스트림! 허나 그렇게 자주 쓰이지는 않음
    //이유:

    //C++ 에서 C 헤더를 사용해도 될까요?
    // 네 현업에서는 여전히 성능상승의 이유로 많은 C 함수들을 사용
    //예) [C] <string.h> , <stdio.h> , <ctype.h> -> [C++] <cstring> , <cstdio> , <cctype>
    //C++에선 standard header의 .h를 제거 및 앞에 c를 붙여줌

    //그럼 String 클래스가 이렇게 좋은데 어떻게 동작하는가?
    //문자 배열 길이에 관해 고민할 필요가 없음

    //const (상수형) 위치에 따른 기능들//
    //[(const char) * == (char const) *] 상수형 문자에 대한 포인터, 포인터가 가르키는 <변수의 가>을 바꿀 수 없음

    char ch1='a';
    char ch2='b';
    const char* pch0;
    pch0=&ch1;//포인터 변경
    std::cout <<*pch0<<std::endl;
    //*pch0='c';//변경 불가능한 가
    pch0=&ch2;//포인터 변경
    std::cout <<*pch0<<std::endl;

    //[char * const] 문자에 대한 상수형 포인터 <포인터 가>을 바꿀 수 없음

    char ch1='a';
    char ch2='b';
    char *const pch1=&ch1;
    std::cout <<*pch1<<std::endl;
    *pch1='c';//데이터 가 변경가능
    std::cout <<*pch1<<std::endl;
    //pch1=&ch2;//포인터 변경 불가능
    std::cout <<*pch1<<std::endl;
    
    //[const char const *]상수형 문자에 대한 상수형 포인터 포인터가 가르키는 <변수의 가과 포인터 가>을 바꿀 수 없음

    char ch1='a';
    char ch2='b';
    const char *const pch2=&ch1; //초기화
    std::cout <<*pch2<<std::endl;
    //*pch2='c';//변경 불가능한 가
    std::cout <<*pch2<<std::endl;
    //pch2=&ch2;//포인터 변경 불가능
    std::cout <<*pch2<<std::endl;

    std::string line ="POPE";
    const char* cLine=line.c_str(); //글자 변경 불가능 포인터 변경 가능
    printf("%s",line.c_str());
    
}
