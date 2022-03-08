#include <iostream>
using namespace std;

int N;
int tree[52][2];



void preorder(int curr){
    if(curr==-1) return;
    cout<<(char)(curr+65);
    preorder(tree[curr][0]);
    preorder(tree[curr][1]);
}

void inorder(int curr){
    if(curr==-1) return;
    inorder(tree[curr][0]);
    cout<<(char)(curr+65);
    inorder(tree[curr][1]);
}

void postorder(int curr){
    if(curr==-1) return;
    postorder(tree[curr][0]);
    postorder(tree[curr][1]);
    cout<<(char)(curr+65);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    
    while(N--){
        char a,b,c; cin>>a>>b>>c;
        a = a - 65;
        if(b =='.') tree[a][0]= -1;
        else tree[a][0]=b-65;
        if(c =='.') tree[a][1]= -1;
        else tree[a][1]=c-65;
    }
    
    preorder(0);    //전위 순회
    cout<<'\n';
    inorder(0);     //중위 순회
    cout<<'\n';
    postorder(0);   //후위 순회
    
}
