#include <iostream>
#include <map>
#include <vector>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    map<char,int>alpha;
    int cnt = 0;
    for(char c = 'a'; c<='z'; c++) alpha[c]=++cnt;
    
    
    int T; cin>>T;
    while(T--){
        int n,m; cin>>n>>m;
        int min_v = 1e9;
        vector<string>v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        
        for(int a=0; a<n; a++){
            for(int b=a+1; b<n; b++){
                string s1 = v[a], s2 = v[b];
                int temp_v = 0;
                for(int i=0; i<m; i++){
                    temp_v += abs(alpha[s1[i]] - alpha[s2[i]]);
                }
                min_v = min(min_v, temp_v);
            }
        }
        cout<<min_v<<'\n';
    }
}
