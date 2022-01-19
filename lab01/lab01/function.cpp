#include "function.h"

int Ver1::div_fun(int a,int b)
{
	std::cout << "¸òÀº : " << a / b << std::endl;
	return a / b;
}
int Ver2::div_fun(int a, int b)
{
	std::cout << "¸òÀº : " << a / b << "³ª¸ÓÁö´Â : " << a % b << std::endl;
	return a / b;
}