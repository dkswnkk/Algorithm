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
    
    for(i; i<N; i++) st.push(num[i]);

    string temp = "", ans = "";
    while(!st.empty()){
        temp += st.top();
        st.pop();
    }
    reverse(temp.begin(), temp.end());
    
    for(int i=0; i<N-K; i++) ans +=temp[i];
    cout<<ans;
}
