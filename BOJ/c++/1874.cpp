#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;
    stack<int>st;
    vector<char> ans;
    
    int curr = 0;
    while(N--){
        int num; cin>>num;
        
        if(st.empty()){
            if(curr>num){
                cout<<"NO";
                return 0;
            }
            int first = curr;
            for(int i=0; i<abs(num-first); i++){
                ans.push_back('+');
                st.push(++curr);
            }
            ans.push_back('-');
            st.pop();
        }
        
        else if(st.top()==num){
            ans.push_back('-');
            st.pop();
        }
        
        else if(st.top()>num){
            while(true){
                if(st.top()==num) break;
                ans.push_back('-');
                st.pop();
            }
        }
        else if(st.top()<num){
            if(curr>num){
                cout<<"NO";
                return 0;
            }
            while(true){
                if(st.top()==num){
                    ans.push_back('-');
                    st.pop();
                    break;
                }
                ans.push_back('+');
                st.push(++curr);
            }
        }
    }
    for(char c: ans) cout<<c<<'\n';
}
