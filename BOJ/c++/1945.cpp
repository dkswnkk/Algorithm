#include <iostream>
#include <stack>
using namespace std;

int arr[26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;
    string cmd; cin>>cmd;
    
    stack<double>st;
    for(int i=0; i<N; i++) cin>>arr[i];
    
    for(int i=0; i<cmd.length(); i++){
        if(cmd[i]=='*'){
            double num1 = st.top();
            st.pop();
            double num2 = st.top();
            st.pop();
            st.push(num2*num1);
        }
        else if(cmd[i]=='+'){
            double num1 = st.top();
            st.pop();
            double num2 = st.top();
            st.pop();
            st.push(num2+num1);
        }
        else if(cmd[i]=='/'){
            double num1 = st.top();
            st.pop();
            double num2 = st.top();
            st.pop();
            st.push(num2/num1);
        }
        else if(cmd[i]=='-'){
            double num1 = st.top();
            st.pop();
            double num2 = st.top();
            st.pop();
            st.push(num2-num1);
        }
        else st.push(arr[cmd[i]-65]);
    }
    
    cout<<fixed;
    cout.precision(2);
    cout<<st.top();
    
}
