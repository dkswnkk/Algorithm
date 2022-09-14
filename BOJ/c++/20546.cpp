#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;
    vector<int> v;
    
    for(int i=0; i<14; i++){
        int inp; cin>>inp;
        v.push_back(inp);
    }
    
    int jun = 0, sung = 0;
    int _N = N;
    for(auto it: v){    // 준현이의 매수
        if(it <= _N){
            jun = _N / it;
            _N = _N % it;
            break;
        }
    }
    jun = _N + (jun * v[13]);  // 준현이의 14일날의 매도
   
    int cnt = 0;
    int buy_idx = 1e9;
    for(int i=1; i<v.size(); i++){
        if(v[i] < v[i-1]) cnt++;
        else cnt = 0;
        if(cnt >= 3){   // 3일 연속 하락했을 경우
            if(v[i] <= N){  // 매수 할 수 있을 경우
                sung += N / v[i];    // 성민이의 매수
                N = N % v[i];
                buy_idx = i;    // 매수일 기억
            }
        }
    }
    cnt = 0;
    bool flag = false;
    for(int i=buy_idx+1; i<v.size(); i++){
        if(v[i] > v[i-1]) cnt++;
        else cnt = 0;
        if(cnt >= 3){   // 3일 연속 상승했을 경우
            flag = true;    // 매도를 했음을 기록
            sung = sung * v[i];    // 성민이의 매도
            break;
        }
    }
    
    if(!flag) sung = N + (sung * v[13]);  // 매도를 못했을 경우 14일에는 필수로 매도해야함
    
    if(sung > jun) cout<<"TIMING";
    else if(sung < jun) cout<<"BNP";
    else cout<<"SAMESAME";
}
