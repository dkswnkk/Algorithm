#include <iostream>
#include <vector>
using namespace std;

vector<int> preorder, inorder;
void postorder(int start, int end, int idx){
    for(int i=start; i<end; i++){
        if(preorder[idx] == inorder[i]){
            postorder(start, i, idx+1); //left
            postorder(i+1, end,  (i-start+1)+idx); //right
            cout<<preorder[idx]<<' ';
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        inorder.resize(n);
        preorder.resize(n);
        inorder.clear();
        preorder.clear();
        
        for(int i=0; i<n; i++) cin>>preorder[i];
        for(int i=0; i<n; i++) cin>>inorder[i];
        
        postorder(0, n, 0);
        cout<<'\n';
        
    }
}
