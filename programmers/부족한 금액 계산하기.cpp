#include <iostream>
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1,check=0;
    long long original_price=price;
    long long prices=(long long)price;
    long long moneys=money;
    
    while(check!=count){
        moneys-=prices;
        prices+=original_price;
        check++;
    }
    
    if(moneys<0) answer=abs(moneys);  //금액이 부족한 경우
    else answer=0;  //금액이 부족하지 않은 경우
    return answer;
}
