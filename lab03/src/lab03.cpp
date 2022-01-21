#include <iostream>
#include <iomanip>
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
	
	//C++에서 쓸 수 있는 안전한 방법 setw()
	cin >> setw(4)>>firstName; 
	//내가 가진 버퍼 사이즈가 4밖에 안되니 만약 firstName 이 "POPE" 라면 "POP\0"가 저장된다.
	
	//C 출력
	char line[512];
	char firstData[512];
	int secondData;
	//입력된 line = "               Hello           123"
	if(fgets(line,512,stdin)!=NULL)
	{
	sscanf(line,"%s%d",firstData,&secondData);//문자열 형태와 정수 형태의 데이터를 분리해서 가져온다.
		//띄어쓰기만 제거해서 아닌 부분만 가져온다.
	}
}
