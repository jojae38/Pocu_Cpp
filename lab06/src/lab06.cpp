#include<iostream>
#include<assert.h>
using namespace std;

typedef struct Vector
{
    int X;
    int Y;
    int Z;
}Vector;
//가독성이 떨어짐 뭐가 결과인지 애매함 ->매개변수 이름을 더 잘 짓자
Vector TryDivide_ver0(Vector& a, Vector& b, Vector& c);
//호출자가 실수할 가능성이 있음 ->ex) TryDivide(a,b,result);
Vector TryDivide_ver1(Vector& result, Vector& a, Vector& b);
//읽기 전용 매개변수를 상수화 하자 -> a 나 b 변수 변경시 컴파일 에러 result만 변경 가능 const 는 변경불가
Vector TryDivide_ver2(Vector& result, const Vector& a, const Vector& b);
//일부 코딩 표준
//읽기 전용 매개변수는 상수참조로
//출력 결과용 매개변수는 포인터로
//하지만 앞에 Result가 NULL이 될 가능성이 있으니 함수 내에 assert 함수를 넣어 a가 NULL이 되는 경우를 잡자
Vector TryDivide_finalver(Vector* result, const Vector& a, const Vector& b);
//C#은 out 키워드를 이용해서 더 이쁨
int main()
{
    Vector check;
    Vector vec_res;
    Vector vec_a;
    Vector vec_b;
    vec_b.X = 2;
    vec_a.X = 1;
    vec_res.X = 0;
    //vec_res.X=NULL;

    check=TryDivide_ver0(vec_res, vec_a, vec_b);
    cout << check.X << endl;
    check=TryDivide_ver1(vec_res, vec_a, vec_b);
    cout << check.X << endl;
    check=TryDivide_ver2(vec_res, vec_a, vec_b);
    cout << check.X << endl;
    check=TryDivide_finalver(&vec_res, vec_a, vec_b);
    cout << check.X << endl;
    return 0;
}

Vector TryDivide_ver0(Vector& a, Vector& b, Vector& c)
{
    a.X = b.X + c.X;
    //cout << a.X << " " << b.X << " " << c.X << endl;
    return a;
}
Vector TryDivide_ver1(Vector& result, Vector& a, Vector& b)
{
    result.X = a.X + b.X;
    //cout << result.X << " " << a.X << " " << b.X << endl;
    return result;
}
Vector TryDivide_ver2(Vector& result, const Vector& a, const Vector& b)
{
    result.X = a.X + b.X;
   //cout << result.X << " " << a.X << " " << b.X << endl;
    return result;
}
Vector TryDivide_finalver(Vector* result, const Vector& a, const Vector& b)
{
    assert(result != NULL);//result가 NULL인지 확인한다.
    result->X = a.X + b.X;
   //cout << result->X << " " << a.X << " " << b.X << endl;
    return *result;
}
