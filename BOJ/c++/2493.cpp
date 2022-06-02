#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;
    stack<pair<int,int>>st; // {탑 번호, 높이}
    
    for(int i=0; i<N; i++){
        int height; cin>>height;

        while(!st.empty()){
            if(st.top().second>height){
                cout<<st.top().first<<' ';
                break;
            }
            st.pop();
        }
        if(st.empty()) cout<< 0 <<' ';
        st.push({i+1,height});
        
    }
}
