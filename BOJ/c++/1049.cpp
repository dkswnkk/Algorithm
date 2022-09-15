#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M; cin>>N>>M;
    
    vector<int> v1, v2;
    for(int i=0; i<M; i++){
        int a, b; cin>>a>>b;
        v1.push_back(a);
        v2.push_back(b);
    }
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    int money = 0;
    while(N > 0){
        if(v1[0] < v2[0] * 6){  // 패키지로 사는게 저렴할 경우
            if(N < 6){  // 필요한 기타줄 갯수가 6개보다 적을 경우
                if(N == 5 && (v1[0] < v2[0] * 5)){
                    money += v1[0];
                    break;
                }
                else if(N == 4 && (v1[0] < v2[0] * 4)){
                    money += v1[0];
                    break;
                }
                else if(N == 3 && (v1[0] < v2[0] * 3)){
                    money += v1[0];
                    break;
                }
                else if(N == 2 && (v1[0] < v2[0] * 2)){
                    money += v1[0];
                    break;
                }
                else if(N == 1 && (v1[0] < v2[0])){
                    money += v1[0];
                    break;
                }
                else{
                    money += v2[0] * N;
                    break;
                }
            }
            else {
                money += (N / 6) * v1[0];
                N = N % 6;
            }
        }
        else{   // 낱개로 사는게 저렴할 경우
            money += v2[0] * N;
            N = 0;
        }
    }
    cout<<money;
}
