#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string> //string class 선언해 줄 것

int main()
{
	std::fstream cin;
	char line[256];
	cin.getline(line, 256);

	//이 경우에는 문제가 될 여지가 두가지 경우
	//1. 아무것도 읽지 못했을 때
	//2. 한줄의 문자가 256자 이상일 때 (버퍼가 충분히 크지 못할경우)
	//#define을 사용하는 경우도 있지만 가능하면
	const int LINE_LENG = 256;
	char line_2[LINE_LENG];
	cin.getline(line_2, LINE_LENG);
	//이런식으로 바꿔주자

	std::cout << "<std::string 클래스>" << std::endl;

	//문자열 길이가 길어질 수 있음
	//std::string firstName_1;//
	//std::cin >> firstName_1;

	//C의 경우 -> 안전하지 않다.

	char firstName_2[30] = "This is 21 Word abcde";
	char secondName_2[30] = "This is 21 Word fghij";//f지점이 39번째 g는 40번째
	char fullName_2[40];
	//대입 - 안전하지 않음 39자 이상 넘어가면 NULL값이 밖으로 나감
	strcpy(fullName_2, firstName_2);
	//덧붙이기 - 안전하지 않음 마찬가지로 39자 이상 초과시 NULL값이 밖으로 나감
	strcat(fullName_2, "KIM");

	//살짝 안전한 버전
	snprintf(fullName_2, 40, "%s %s", firstName_2, secondName_2); 
	//fullName_2의 크기를 고려해 40자만 받겠다. 40이 넘어가는 순간 40에 NULL char를 넣어준다.
	snprintf(fullName_2, sizeof(fullName_2), "%s %s", firstName_2, secondName_2);
	printf("C_Version: %s fullname_2 size: %d\n", fullName_2, sizeof(fullName_2));


	//C++의 경우 -> 안전함 , +연산자를 이용해 직관적이다.

	std::string firstName_3	= "POPE";
	std::string secondName_3 = "KIM";
	std::string fullName_3 = "John Doe";

	//대입 - 알아서 늘어남?
	fullName_3 = firstName_3;
	//덧붙이기
	fullName_3 += "KIM";//C에선 strcat을 써야 하지만 여기선 + 연산자로 string과 string간의 덧붙이기가 가능하다.
	std::cout << fullName_3 << " " << sizeof(fullName_3) << std::endl; //POPEKIN 28이 출력된다.
	//보시는 바와 같이 무조건 28의 크기를 가진다.
	//printf("%s %d", fullName_3, sizeof(fullName_3)); C Printf로 출력하려고 보니 에러 발생한다.
	fullName_3 = firstName_3 + " " + secondName_3;//정말 C와 다르게 간편하게 string을 다루는 모습
	std::cout << fullName_3 << std::endl;
	
	//C의 비교
	if (strcmp(firstName_2, secondName_2)==0)
	{
		//둘다 같은 경우
	}
	else if (strcmp(firstName_2, secondName_2) > 0)
	{
		//앞이 더 큰 경우
	}
	else if (strcmp(firstName_2, secondName_2) < 0)
	{
		//앞이 더 작은 경우
	}
	//C++의 비교
	if (firstName_3 == secondName_3)
	{
		//같을 시
	}
	//그외 사용 가능한 부호로
	//!=, ==, >=, >, <=, < 등이 있다.
	//글자가 string 이면 사전 순서로 비교를 해준다.

	std::cout << "<C++ 여러 함수 기능들>" << std::endl;

	//size(), length()
	std::cout << fullName_3.size() << std::endl;
	std::cout << fullName_3.length() << std::endl;
	//보통 size를 많이 쓴다.

	//c_str() -> 자주 쓰인다.
	//const char*
	//해당 string 문자배열의 시작주소를 가르키는 포인터를 반환
	std::string line_3;
	std::cin >> line_3;
	const char* cLine_3 = line_3.c_str();
	//아까 56줄에 printf로 string class를 넣으니 오류가 나는 모습 string class가 아니라 배열의 첫 주소(const char*)를 전달해 줘야 한다.
	//그래서 c_str()를 사용해 포인터를 전달해 주니 정상적으로 출력이 된다.
	printf("%s\n", line_3.c_str());

	//String 속의 한 문자에 접근하기
	std::string firstName_4 = "POKE";
	char letter = firstName_4[1];//firstName_4[1]이거 자체가 함수이다.
	firstName_4[2] = 'P';//모양은 call by value 지만 참조로 바꾸기에 값이 변경되는 것을 알 수있다.
	std::cout << letter << " " << firstName_4 << std::endl;

	//at()
	//해당 문자열에서 주어진 위치에 있는 문자를 참조로 반환
	//근데 실질적으로 잘 안씀 솔직히 배열 형태로 많이 사용함 -> firstName_4[3];
	letter = firstName_4.at(1);
	firstName_4.at(3) = 'P';
	std::cout << letter << " " << firstName_4 << std::endl;

	//한줄 읽기
	std::string mailHeader;
	getline(cin, mailHeader);//'\n'문자를 만날 때 까지 cin에서 문자들을 꺼내서 mailHeader에 저장
	getline(cin, mailHeader,'@');//@문자를 만날 때 까지 cin에서 문자들을 꺼내서 mailHeader에 저장
	//end of file을 만날 때 eofbit 값이 true가 됨
	//구분 문자를 만날 때 까지 (구분 문자는 버려짐) -> '\n' 이나 '@'(설정된 문자)

	return 0;
}
