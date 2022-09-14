#include <iostream>
#include <unordered_map>
#include <vector>


using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;
    unordered_map<string, int> um;
    vector<string> inp;
    
    for(int i=0; i<N; i++){
        string _inp; cin>>_inp;
        um.insert({_inp, i});
    }
    
    
    for(int i=0; i<N; i++){
        string _inp; cin>>_inp;
        inp.push_back(_inp);
    }
   
    int cnt = 0;
    
    for(int i=0; i<inp.size(); i++){
        for(int k=i+1; k<inp.size(); k++){
            if(um[inp[i]] > um[inp[k]]){
                cnt++;
                break;
            }
        }
    }
    cout<<cnt;
}
