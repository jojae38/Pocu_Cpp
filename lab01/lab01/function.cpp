#include "function.h"

int Ver1::div_fun(int a,int b)
{
	std::cout << "���� : " << a / b << std::endl;
	return a / b;
}
int Ver2::div_fun(int a, int b)
{
	std::cout << "���� : " << a / b << "�������� : " << a % b << std::endl;
	return a / b;
}