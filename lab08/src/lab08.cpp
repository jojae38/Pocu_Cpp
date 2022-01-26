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
    std::string My_string="This Line size is about 36byte";
    std::cout << sizeof(My_string) << std::endl;//string class의 기본 크기 -> 포인터, String 길이, 용량이 있다.
    std::cout << "첫 string 주소위치: "<<&My_string <<std::endl;
    std::cout << "String 크기: " <<"" << My_string.size() << std::endl;//string의 사이즈를 출력
    std::cout << "String 길이: " << My_string.length() << std::endl;//string의 길이를 출력
    std::cout << "String에 선언된 처음 배열 크기: " << My_string.capacity() << std::endl;//16*n-1의 법칙으로 늘어나는 듯 함
    My_string += "abcdabcd";
    std::cout << "String에 선언된 바뀐 배열 크기: " << My_string.capacity() << std::endl;//16*n-1의 법칙으로 늘어나는 듯 함
    std::cout << "바뀐 string 주소위치: " << &My_string << std::endl;

    //string 클래스의 기본 크기는 28바이트임
    //이 클래스가 함유한 정보는 대표적으로 포인터, 길이, 그리고 용량이다.
    //길이가 길어지면 배열 크기도 그에 따라 늘어나며(31->47) 다른 위치에 생성한다.->고로 포인터가 변함
    // 힙(heap)메모리 할당은 느리고(string 동적할당) 메모리 단편화 문제가 일어날 수 있음(string길이가 변하면 다른 곳에 동적할당)
    // 그에 비해 스택은 컴파일 시 exe파일에 미리 들어간 공간이기에 포인터만 변경하는 것으로 메모리 할당 없이 빠르게 이동 가능
    // 힙은 OS가 가진 모든 메모리를 찾아야 하기에 (2GB) 오래 걸린다.
    // 내부 버퍼 증가는 멀티스레드 환경에서 바람직하지 않음 -> 연속된 큰 크기의 메모리 버퍼를 찾기 힘들 수도 있음
    // 그래서 여전히 sprintf 와 char[]를 같이 많이 사용한다.
   
    //const (상수형) 위치에 따른 기능들//
    //[(const char) * == (char const) *] 상수형 문자에 대한 포인터, 포인터가 가르키는 <변수의 값>을 바꿀 수 없음

    char ch1 = 'a';
    char ch2 = 'b';
    const char* pch0;
    pch0 = &ch1;//포인터 변경
    std::cout << *pch0 << std::endl;
    //*pch0='c';//변경 불가능한 값
    pch0 = &ch2;//포인터 변경
    std::cout << *pch0 << std::endl;

    //[char * const] 문자에 대한 상수형 포인터 <포인터 가>을 바꿀 수 없음

    
    char* const pch1 = &ch1;
    std::cout << *pch1 << std::endl;
    *pch1 = 'c';//데이터 값 변경가능
    std::cout << *pch1 << std::endl;
    //pch1=&ch2;//포인터 변경 불가능
    std::cout << *pch1 << std::endl;

    //[const char const *]상수형 문자에 대한 상수형 포인터 포인터가 가르키는 <변수의 값과 포인터 값>을 바꿀 수 없음

   
    const char* const pch2 = &ch1; //초기화
    std::cout << *pch2 << std::endl;
    //*pch2='c';//변경 불가능한 값
    std::cout << *pch2 << std::endl;
    //pch2=&ch2;//포인터 변경 불가능
    std::cout << *pch2 << std::endl;

    std::string line = "POPE";
    const char* cLine = line.c_str(); //글자 변경 불가능 포인터 변경 가능
    printf("%s", line.c_str());

}
