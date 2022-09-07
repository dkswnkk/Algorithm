#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, max_money;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N>>M;
    
    for(int i=0; i<N; i++){
        int inp; cin>>inp;
        v.push_back(inp);
        max_money += inp;
    }
    int ans = 0;
    int start = 1, end = max_money; // 최대 인출 금액은 모든 날의 이용할 금액을 합한 값이다.
    
    while(start <= end){
        bool flag = false;
        int take_cnt = 1;
        int mid = (start + end) / 2;
        int money = mid;
        int temp_money = money;
        
        for(int i=0; i<v.size(); i++){
            if(v[i] > temp_money){
                take_cnt++;
                temp_money = money;
            }
            temp_money -= v[i];
            if(temp_money < 0){
                flag = true;
                break;
            }
        }
        if(flag || take_cnt > M) start = mid + 1;
        /*
            아래 조건을 추가하면 틀림
            2 2
            100 200
            와 같은 부분에서 225를 출력하는데 더 작은 값을 찾을 수 있음에도 불구하고 종료하기 때문
         else if(take_cnt == M){
             cout<<money;
             break;
         }
         */
        else{
            ans = money;
            end = mid - 1;
        }
    }
    cout<<ans;
}
