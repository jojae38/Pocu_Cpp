#include "function.h"

int Ver1::div_fun(int a,int b)
{
	std::cout << "Val : " << a / b << std::endl;
	return a / b;
}
int Ver2::div_fun(int a, int b)
{
	std::cout << "Val : " << a / b << "Res : " << a % b << std::endl;
	return a / b;
}
