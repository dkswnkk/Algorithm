#include <iostream>
using namespace std;

// 점프: 베터리 듬, 순간이동: 배터리 안듬
// 거꾸로 계산
int solution(int n){
    int battery = 0;
    while(n>2){
        if(n&1){
            battery++;
            n--;
        }
        else n/=2;
    }
    return battery+1;
}
