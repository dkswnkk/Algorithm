#include <iostream>
#include <vector>

using namespace std;

vector<int>v;

void postorder(int start, int end){
    if(start>end) return;
    if(start==end){
        cout<<v[start]<<'\n';
        return;
    }
    
    int root_index = start;
    while(true){
        root_index++;
        if(v[start]<v[root_index]) break;
        if(root_index>end) break;
    }
    
    postorder(start+1, root_index-1);
    postorder(root_index, end);
    cout<<v[start]<<'\n';   // 루트노드 출력
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int inp;
    while(cin>>inp){
        v.push_back(inp);
    }
    
    postorder(0, v.size()-1);
    
}
