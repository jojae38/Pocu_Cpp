#include <iostream>
#include <iomanip>
int main()
{
	/*C++���� ���α׷��Ӱ� �������� ������ �ٲ� �� �ִ�. (�����ε�) */
	/*����� ��� �����ڷ� ���̴� ���*/
	std::cout << "<������>" <<std::endl;
	std::cout << "hello, world" << std::endl;

	using namespace std;

	cout << "<���� ����غ���>" << endl;
	 
	int integer = 10;
	float decimal = 3.5f;
	char letter = 'A';
	char string[] = "Hello World";

	cout << integer << endl;
	cout << decimal << endl;
	cout << letter << endl
	<< string << endl;

	cout << "<������� ����>" << endl;
	int number = 123;
	cout << showbase << hex << number << endl;
	/*showbase << hex �� ���� ���� ���ڸ� 16������ ǥ���Ѵ�.*/
	cout << dec;
	cout << showpos << number << endl;//+ �߰� +123
	cout << noshowpos << number << endl;// �׳� ǥ�� 123

	cout << dec << number << endl; //������ 123
	cout << hex << number << endl; //16���� 7b
	cout << oct << number << endl; //������ 173

	cout << uppercase << hex << number << endl; //�빮�� 7B
	cout << nouppercase << hex << number << endl; //�ҹ��� 7b

	cout << showbase << hex << number << endl; //�տ� 0x �߰� 0x7b
	cout << noshowbase << hex << number << endl; //�տ� 0x ���� 7b
	cout << dec;

	cout << "<����>" << endl;
	/*#include <iomanip> �� ȣ���� ��*/
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

	cout << setw(5) << number<<endl; //5ĭ ������ ���� |   123|
	cout << setfill('*') << setw(5) << number<<endl; //�� ������ �������� ä���� ����
	cout << setprecision(3) << number_f<<endl; //�Ҽ����� �� �� �ڸ��� ������ ������;

	return 0;
}