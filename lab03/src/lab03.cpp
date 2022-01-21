#include <iostream>
using namespace std;

int main()
{
	cout << "<입력>" << endl;
	int hours;
	/*입력을 받는 방식 - 입력 연산자*/
	cin >> hours;
	cout << "Today I studied for " << hours <<"hours"<< endl;
	
	char firstName[4];
	/*이것도 C 처럼 4글자가 들어가면 안된다 마지막은 /NULL문자를 생각해야 해서 3글자가 들어가던지 []를 5로 바꿔준다.*/
	cin >> firstName;
	cout <<firstName<<endl;
	
}
