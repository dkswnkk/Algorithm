#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M; cin>>N>>M;
    vector<string> v, scale;
    for(int i=0; i<N; i++){
        string inp; cin>>inp;
        v.push_back(inp);
    }
    for(int i=0; i<N; i++){
        string inp; cin>>inp;
        scale.push_back(inp);
    }
    for(int idx=0; idx<v.size(); idx++){
        for(int i=0; i<v[idx].length(); i++){   // 원본
            for(int k=i*2; k<i*2+2; k++){ // 늘린거
                if(v[idx][i] != scale[idx][k]){
                    cout<< "Not Eyfa";
                    return 0;
                }
            }
        }
    }
    cout<<"Eyfa";
}
