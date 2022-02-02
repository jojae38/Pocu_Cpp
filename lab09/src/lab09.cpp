#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::cout << "<파일 입력 출력>" << std::endl;
	//ifstream 파일 입력
	//ofstream 파일 출력
	//fstream 파일 입력 및 출력

	//Case C

	FILE* fp;
	//읽기 전용으로 파일을 오픈
	fp = fopen("helloWorld.txt", "r");//fp에 파일 포인터 반환

	//쓰기 전용으로 파일을 오픈(파일이 없으면 만듦)
	fp = fopen("helloWorld.txt", "w+");

	//읽기와 쓰기 범용으로 파일을 오픈
	fp = fopen("helloWorld.txt", "r+");

	//Case C++

	//읽기 전용으로 파일을 오픈
	std::ifstream fin;
	fin.open("helloWorld.txt");

	//쓰기 전용으로 파일을 오픈(파일이 없으면 만듦)
	std::ofstream fout;
	fout.open("helloWorld.txt");

	//읽기와 쓰기 범용으로 파일을 오픈
	std::fstream fs;
	fs.open("helloWorld.txt");

	//파일 읽기
	//각 스트림 마다 open()메서드가 있음
	//fin.open("helloWorld.txt",std::ios_base::in|std::ios_base::binary)//입력 이진파일

	//파일 닫기
	//Case C
	//fclose(fp);

	//Case C++
	//fin.close(); //파일을 닫음

	//스트림 상태 확인하기
	//Case C
	fp = fopen("helloWorld.txt", "r+");
	if (fp != NULL)
	{
		//파일이 비어있을 경우 널 포인터를 반환
	}

	//Case C++
	//std::fstream fs;
	fs.open("HelloWorld.txt");
	if (fs.is_open()) //is_open() //파일이 열려있는지 확인
	{
		//파일이 열려있을 경우 
	}
 return 0; 
}
