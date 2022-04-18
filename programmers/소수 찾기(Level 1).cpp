#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> prime(n+1, true);  // 최종적으로 true일때 소수
    prime[0] = false; prime[1] = false;

    for(int i=2; i<=n; i++){  // 소수 만들기
        if(prime[i]){
            int k = 2;
            while(i*k<=n){
                prime[i*k] = false;
                k++;
            }
        }
    }
    
    for(int i=2; i<=n; i++){
        if(prime[i]) answer++;
    }
    
    return answer;
}
