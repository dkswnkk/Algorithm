#include <iostream>
#include <algorithm>

#define INF 1e9
using namespace std;

int map[101][101];

string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int find_index(char c){
    for(int i=0; i<alpha.length(); i++){
        if(alpha[i] == c){
            return i;
        }
    }
    return -1;
}

string find_char(int i){
    string out = "";
    return out+alpha[i];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    for(int i=0; i<52; i++){
        for(int k=0; k<52; k++){
            if(i==k) map[i][k] = 0;
            else map[i][k] = INF;
        }
    }
    
    int N; cin>>N;
    cin.ignore();
    for(int i=0; i<N; i++){
        string s; getline(cin, s);
        int a = find_index(s.front());
        int b = find_index(*(--s.end()));
        map[a][b] = 1;
    }
    
    for(int k=0; k<52; k++){
        for(int a=0; a<52; a++){
            for(int b=0; b<52; b++){
                map[a][b] = min(map[a][b], map[a][k] + map[k][b]);
            }
        }
    }
    
    string ans=""; int cnt= 0;
    for(int i=0; i<52; i++){
        for(int k=0; k<52; k++){
            if(map[i][k] != INF && map[i][k]!=0 & i!=k){
                cnt++;
                ans += find_char(i) + " => " + find_char(k);
                ans+="\n";
            }
        }
    }
    cout<<cnt<<'\n'<<ans;
}
