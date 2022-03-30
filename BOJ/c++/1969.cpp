#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M; cin>>N>>M;
    vector<string>v;
    string dna;
    int hamming_distance_cnt = 0;
    
    for(int i=0; i<N; i++){
        string inp; cin>>inp;
        v.push_back(inp);
    }
    
    for(int i=0; i<M; i++){
        map<char,int> cnt;
        int max_cnt = -1;
        char max_char = 'Z';
        for(int k=0; k<N; k++){
            cnt[v[k][i]]++;
            if(max_cnt<cnt[v[k][i]]){
                max_cnt = cnt[v[k][i]];
                max_char = v[k][i];
            }
            else if(max_cnt==cnt[v[k][i]]){
                max_char = min(max_char, v[k][i]);
            }
        }
        dna += max_char;
    }
    
    for(int i=0; i<M; i++){
        for(int k=0; k<N; k++){
            if(v[k][i]!=dna[i]) hamming_distance_cnt++;
        }
    }
    cout<<dna<<'\n'<<hamming_distance_cnt;
}
