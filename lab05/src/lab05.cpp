#include <iostream>

using namespace std;

typedef struct
{
    int number;
    int number2;
}Mystruct;


void swap_value(int arg1, int arg2);
void swap_reference(int& arg1, int& arg2);
void swap_pointer(int* arg1, int* arg2);

void Increase_value(Mystruct abc);
void Increase_pointer(Mystruct* abc);
void Increase_shift(Mystruct* argument);
int main()
{

    cout << "Bool 데이터 형" << endl;

    //C에서는 bool이 없지만 
#define TRUE 1
#define FALSE 0
//이런식으로 치환해서 사용하기도 함

    cout << "참조(Reference)" << endl;


    //C++ 에만 있는 기능
    //포인터를 사용하는 좀 더 안전한 방법 하지만 JAVA만큼 제한적이진 않음

    int a = 5;
    int b = 10;

    //(Call by value) Value를 뽑아서 전달 (단 지역변수에 전달하기에 원본이 바뀌지 않는다.)
    swap_value(a, b);
    cout << a << "  " << b << endl;

    //(Call by reference) <--
    swap_reference(a, b);
    cout << a << "  " << b << endl;

    //(Pointer) 변수의 주소를 뽑아서 전달 (주소가 바뀌기에 원본이 바뀐다.)
    swap_pointer(&a, &b);
    cout << a << "  " << b << endl;

    //비슷하게 구조체를 생성했을 때 포인터로 구조체를 받느냐 그냥 받느냐에 따라 원본이 바뀌는지 바뀌지 않는지 알 수 있다.
    Mystruct abc;
    abc.number = 100;

    //Value가 변하지 않음
    Increase_value(abc);

    //Value가 변함
    Increase_pointer(&abc);

    //구조체 주소가 변함
    Increase_shift(&abc);

    //자바는 C와 다르게 항상 참조에 의하 전달된다 (주소가 복사됨)
    //C 입장에서 JAVA 코드를 봤을 때 Call by Value지만 실제론 참조에 의한 복사처럼 작동한다.
    //단 JAVA는 주소를 바꿀 수 없다 고로 포인터 연산자가 아니다.

    cout << "<본격적으로 참조>" << endl;

    //참조는 별칭 언뜻 보면 포인터랑 비슷해보이지만 엄연히 다르다.
    int number = 100;
    int& reference_example = number; //넘버를 다른 이름으로 부르고 싶다.
    //NULL이 될수는 없다.
    //int& reference = NULL; error
    //초기화 중에 반드시 선언되어야 함
    //int& reference; error

    //참조하는 대상을 바꿀 수 없음
    int number1 = 100;
    int number2 = 200;

    int& reference = number1;
    reference = number2;//이건 순수하게 대입이다. 즉 number1 = reference 이기에 number1=number2로 둘다 200이 된다.

    //참조형
    swap_reference(a, b);
    cout << a << "  " << b << endl;

    //포인터형
    swap_pointer(&a, &b);
    cout << a << "  " << b << endl;

    //참조형을 사용했을 때 장점 ->포인터보다 안전하다.
    //number1 과 number2 변수가 NULL이 될 수 앖음 -> NULL체크 필요없음
    //우리가 소유하지 않은 메모리 장소를 가리킬 수 없음 -> *(number+1)이런 연산 작용중 오류 발생을 막을 수 있음

    cout << "컴퓨터는 참조가 뭔지 알까?" << endl;

    //일단 모름
    //포인터와 참조는 똑같은 어셈블리 명령어를 생성한다.
    //참조는 오직 사람을 위한 것임
    //컴파일러는 참조를 포인터로 바꿔줌 기계가 이해할 수 있도록
}

void swap_value(int arg1, int arg2)
{
    int temp = arg1;
    arg1 = arg2;
    arg2 = temp;
}
void swap_reference(int& arg1, int& arg2)
{
    int temp = arg1;
    arg1 = arg2;
    arg2 = temp;
}
void swap_pointer(int* arg1, int* arg2)
{
    int temp = *arg1;
    *arg1 = *arg2;//해당 주소에서 읽어온 arg1 Value를 arg2 Value로 덮어쓰라고 한다.
    *arg2 = temp;
}
void Increase_value(Mystruct abc)
{
    abc.number++;//원본이 변하지 않음 (전역변수로 선언하면 변함)
}
void Increase_pointer(Mystruct* abc)
{
    abc->number++;//원본이 변함
}

void Increase_shift(Mystruct* argument)
{
    cout << "바뀌기 전 주소: " << argument << endl;
    argument = argument + 1;//이때 1은 1바이트가 늘어나는 게 아니라 argument 사이즈 만큼 주소가 Shift된다.
    cout << "바뀐 주소: " << argument << endl;
    //주소가 4096이면 +4 +4 해서 4104로
}
