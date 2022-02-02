#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

int main()
{
	FILE* fp;
	std::ifstream fin;
	std::ofstream fout;

	std::cout << "<파일에서 문자 하나씩 가져오기>" << std::endl;
	//Case C
	//FILE* fp;
	fp = fopen("HelloWorld1.txt", "r");

	char character;
	do {
		character = getc(fp);//문자 하나를 가져와
		printf("%c", character);
	} while (character != EOF);//파일의 끝이면 루프 탈출

	//Case C++
	//ifstream fin;
	fin.open("HelloWorld1.txt");
	//char character;

	while (true)
	{
		fin.get(character);
		if (fin.fail())
		{
			break;
		}
		std::cout << character;

	}
	fin.close();
	char str[20] = {0};
	std::string line;
	std::string word;
	std::string firstName;
	fin.open("HelloWorld1.txt");
	fin.get(character);//H 가져옴
	fin.getline(str, 20);//파일에서 문자 20개를 읽음 //char* 형태의 인수를 받음 string X
	std::cout << printf("%s", str) << std::endl;
	fin.close();
	fin.open("HelloWorld1.txt");
	getline(fin, line);//파일에서 한 줄을 읽음 fin->line //string 형태를 받음
	std::cout << line << std::endl;
	fin >> word;//파일에서 한 단어를 읽음
	fin.close();
	//파일에서 한 줄씩 읽기
	fin.open("HelloWorld2.txt");
	//std::string line;
	while (!fin.eof())//fin 은 파일의 포인터 해당 파일의 포인터가 EOF에 도달 시 루프 탈출
	{
		getline(fin, line);//한 줄을 읽고 \n 다음 글자로 fin포인터를 옮기거나 파일의 끝일 경우 EOF로 옮긴다.
		std::cout << line << std::endl;
	}
	fin.close();

	//파일에서 한 단어씩 읽기

	fin.open("HelloWorld3.txt");

	std::string name;
	float balance;

	while (!fin.eof())
	{
		fin >> name >> balance;//name 의 경우 띄어쓰기 한개까지 읽는다.
		std::cout << name << ": $" << balance << std::endl;
	}
	fin.close();

	//파일에 잘못된 입력이 섞여있으면? \n 의 경우
	//100 200 300\n
	fin.open("Wrong Input1.txt");
	int number;
	while (!fin.eof())
	{
		fin >> number;
		if(!fin.fail())//\n을 읽었을 때 fail bit가 ON
			std::cout << number << std::endl;
	}
	//마지막에 300이 두번 출력됨
	fin.close();
	//파일에 잘못된 입력이 섞여있으면 숫자 사이에 문자
	//100 C++ 300
	fin.open("Wrong Input2.txt");
	//int number;
	while (!fin.eof())
	{
		fin >> number;
		if (fin.fail())
		{
			fin.clear();//모든 에러 플래그 초기화 이 경우 fail
			fin.ignore(LLONG_MAX, ' ');//띄어쓰기를 만날 때 까지 무시
			//대신 탭 \t에 동작을 안함
		}
		else
		{
			std::cout << number << std::endl;
		}
		
	}
	fin.close();
	//0 무한반복

	//fin.clear()
	//flag를 초기화 해주는 기능 fail이나 EOF 상황에선 fin이나 cin은 읽으려 하지 않기에
	//플래그를 초기화 해주고 읽어줘야한다.

	//숫자만 읽기
	fin.open("Wrong Input3.txt");
	std::string trash;
	while (true)
	{
		fin >> number;
		if (!fin.fail())
		{
			std::cout << number << std::endl;//숫자만 출력
			continue;
		}
		if (fin.eof())
		{
			break;
		}
		fin.clear();
		fin >> trash;//숫자외 모든 것들은 fail flag가 뜨면서 자동으로 trash로 읽힌다.
	}
	fin.close();
	//글자만 읽기
	fin.open("Wrong Input3.txt");
	std::string trash_2;
	while (true)
	{
		fin >> number;
		if (fin.fail())
		{
			fin.clear();//만약 fin.clear()와 fin>>trash위치가 바뀌면 이미 fail이기에 읽으려는 시도도 안한다.
			fin >> trash_2;
			std::cout << trash_2 << std::endl;
		}
		if (fin.eof())
		{
			break;
		}
	}
	fin.close();

	//EOF 처리는 까다롭다.
	//입출력 연산이 스트림 상태 비트를 변경한다.
	//EOF 처리 잘못하면 무한반복 루프에 빠진다.
	//clear() 쓸 때는 두번 생각하자.
	//C#이나 JAVA를 본떠 자신만의 스트림 리더(reader)를 만드는 경우가 흔함

	//훌륭한 테스트 케이스
	//유효한 입력 뒤에 EOF - 100\n200EOF
	//유효한 입력 과 뉴라인 \n 뒤에 EOF - 100\n200\nEOF
	//유효하지 않은 입력 뒤에 EOF - 100\nC++EOF
	//유효하지 않은 입력과 뉴라인 \n 뒤에 EOF - 100\nC++\nEOF
	//공백 탭도 포함할 것인가? - 100 C++\t200EOF
	//키보드 입력과 입력 리다이렉션을 둘다 확인할 것
	return 0;
}
