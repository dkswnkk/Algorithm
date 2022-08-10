#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<pair<int,int>>graph[10001];
unordered_map<int,int> cnt;
vector<int> height_arr[10001];

int N, root;
int col[10001];
int seq = 1;
int height = 1;

void inorder(int node){
    
    for(auto next: graph[node]){
        if(next.first != -1){
            height++;
            inorder(next.first);
            height--;
        }
        height_arr[height].push_back(node);
        col[node] = seq++;
        
        if(next.second !=-1){
            height++;
            inorder(next.second);
            height--;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    for(int i=0; i<N; i++){
        int node, first, second;
        cin>>node>>first>>second;
        graph[node].push_back({first,second});
        cnt[node]++;
        cnt[first]++;
        cnt[second]++;
    }
    
    for(auto it = cnt.begin(); it!=cnt.end(); it++){
        if(it->second == 1){
            root = it->first;
            break;
        }
    }
    inorder(root);
    
    int ans_height = 0, ans_width = 0;
    
    for(int i=0; i<=N; i++){
        if(height_arr[i].empty()) continue;
        int width = col[height_arr[i].back()] - col[height_arr[i].front()] + 1;
        int height = i;
        if(width>ans_width){
            ans_width = width;
            ans_height = height;
        }
    }
    cout<<ans_height << ' '<<ans_width;
}
