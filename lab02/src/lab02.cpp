#include <iostream>
#include <iomanip>
int main()
{
	/*C++에선 프로그래머가 연산자의 동작을 바꿀 수 있다. (오버로딩) */
	/*현재는 출력 연산자로 쓰이는 모습*/
	std::cout << "<연산자>" <<std::endl;
	std::cout << "hello, world" << std::endl;

	using namespace std;

	cout << "<모든걸 출력해보자>" << endl;
	 
	int integer = 10;
	float decimal = 3.5f;
	char letter = 'A';
	char string[] = "Hello World";

	cout << integer << endl;
	cout << decimal << endl;
	cout << letter << endl
	<< string << endl;

	cout << "<출력형식 지정>" << endl;
	int number = 123;
	cout << showbase << hex << number << endl;
	/*showbase << hex 를 통해 다음 숫자를 16진수로 표현한다.*/
	cout << dec;
	cout << showpos << number << endl;//+ 추가 +123
	cout << noshowpos << number << endl;// 그냥 표기 123

	cout << dec << number << endl; //십진수 123
	cout << hex << number << endl; //16진수 7b
	cout << oct << number << endl; //팔진수 173

	cout << uppercase << hex << number << endl; //대문자 7B
	cout << nouppercase << hex << number << endl; //소문자 7b

	cout << showbase << hex << number << endl; //앞에 0x 추가 0x7b
	cout << noshowbase << hex << number << endl; //앞에 0x 생략 7b
	cout << dec;

	cout << "<정렬>" << endl;
	/*#include <iomanip> 꼭 호출할 것*/
	cout << setw(6) << left << number << endl;// |-123     |
	cout << setw(6) << internal << number << endl;// |-     123|
	cout << setw(6) << right << number << endl;// |     -123|

	float decimal1 = 100.0f;
	float decimal2 = 100.12f;
	cout << noshowpoint << decimal1 << " " << decimal2 << endl; //100 100.12
	cout << showpoint << decimal1 << " " << decimal2 <<endl; //100.000 100.120

	float number_f = 123.456789;
	cout << fixed << number_f << endl; //123.456789
	cout << scientific << number_f << endl; //1.234568E+02
	cout << fixed;

	bool bReady = true;
	cout << boolalpha << bReady << endl;//ture
	cout << noboolalpha << bReady<<endl;//1

	cout << setw(5) << number<<endl; //5칸 여유로 정렬 |   123|
	cout << setfill('*') << setw(5) << number<<endl; //빈 공간을 무엇으로 채울지 결정
	cout << setprecision(3) << number_f<<endl; //소수점을 총 몇 자리를 보여줄 것인지;

	return 0;
}
