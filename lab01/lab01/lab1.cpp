#include "function.h"

int main()
{
	int a, b;
	a = 10; b = 3;
	std::cout << "<====================>" << std::endl; 
	/*function.h ���� iostream ����� �����߱⿡ ��� �����ϴ�.*/
	/*���� ���� using namespace std�� ���� �� std::endl�� endl�� ���� ���� �����ϴ�. */
	using namespace std;
	cout << Ver1::div_fun(a, b) << endl;
	cout << Ver2::div_fun(a, b) << endl;
	//using namespace Ver1;
	//using namespace Ver2;
	/*���⼭ std ó�� �� �ڵ� �� ���� Ȱ��ȭ �� �� div_fun()�Լ��� �׳� ��� ���������� �� �� ���� �Լ����� ����⿡ ������ �߻��Ѵ�.*/
	//div_fun(a, b);
	cout << "<====================>" << endl;
}