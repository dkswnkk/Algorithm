#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;



int solution(int N, vector<vector<int> > road, int K) {
    int graph[51][51]={0, };
    int answer = 0;
    vector<int>memory_city_cnt;

    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            if(i==k) graph[i][k] = 0;
            else graph[i][k] = INF;
        }
    }
    
    for(int i=0; i<road.size(); i++){
        int a = road[i][0]-1;
        int b = road[i][1]-1;
        int cost = road [i][2];
        graph[a][b] = min(graph[a][b],cost);
        graph[b][a] = min(graph[b][a],cost);
    }
    
    for(int k=0; k<N; k++){
        for(int a=0; a<N; a++){
            for(int b=0; b<N; b++){
                graph[a][b]=min(graph[a][b],graph[a][k]+graph[k][b]);
            }
        }
    }
    
    for(int k=0; k<N; k++){
        if(graph[0][k]<=K) memory_city_cnt.push_back(k);
    }
    
    answer = memory_city_cnt.size();
    return answer;
}
