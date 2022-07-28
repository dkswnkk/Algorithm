#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, K; cin>>N>>K;
    string num; cin>>num;
    stack<char> st;
    int remove_cnt = 0;
    int i=0;
    
    for(i; i<N; i++){
        if(st.empty()) st.push(num[i]);
        else if(st.top()>num[i]) st.push(num[i]);
        else{
            while(true){
                if(!st.empty() && num[i]>st.top()){
                    if(remove_cnt == K) break;
                    st.pop();
                    remove_cnt++;
                }
                else break;
            }
            st.push(num[i]);
        }
    }
    

    string ans = "";
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    ans = ans.substr(0, N-K);
    cout<<ans;
}
