#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int>height[1025];
vector<int>v(1025);
void inorder(int start, int end, int level){
    if(start > end) return;
    int mid = (start+end)/2;
    height[level].push_back(v[mid]);
    
    inorder(start, mid-1, level+1);
    inorder(mid+1, end, level+1);

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int K; cin>>K;
    
    for(int i=0; i<pow(2,K)-1; i++){
        cin>>v[i];
    }
    
    inorder(0, pow(2,K)-2, 1);
    
    for(int i=1; i<=K; i++){
        for(auto it: height[i]){
            cout<<it<<' ';
        }
        cout<<'\n';
    }
}
