#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int X; cin>>X;
    int sum = 0;
    vector<int>piece;
    piece.push_back(64);
    
    if(X==64){
        cout<<1;
        return 0;
    }
    while(true){
        sort(piece.begin(),piece.end());
        for(int i:piece) sum+=i;
        if(sum==X) break;
        if(sum>X){
            int half = piece.front()/2;
            if(sum-half>X){
                piece.erase(piece.begin());
                piece.push_back(half);
            }
            else{
                piece.erase(piece.begin());
                piece.push_back(half);
                piece.push_back(half);
            }
        }
        sum=0;
    }
    cout<<piece.size()-1;
}
