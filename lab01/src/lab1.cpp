#include "function.h"

int main()
{
	int a, b;
	a = 10; b = 3;
	std::cout << "<====================>" << std::endl; 
	/*function.h 내에 iostream 헤더를 포함했기에 사용 가능하다.*/
	/*만약 내가 using namespace std를 선언 시 std::endl을 endl로 쓰는 것이 가능하다. */
	using namespace std;
	cout << Ver1::div_fun(a, b) << endl;
	cout << Ver2::div_fun(a, b) << endl;
	//using namespace Ver1;
	//using namespace Ver2;
	/*여기서 std 처럼 위 코드 두 줄을 활성화 할 시 div_fun()함수를 그냥 사용 가능하지만 둘 다 같은 함수명을 지녔기에 오류가 발생한다.*/
	//div_fun(a, b);
	cout << "<====================>" << endl;
}
