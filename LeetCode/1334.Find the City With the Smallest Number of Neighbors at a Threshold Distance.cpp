class Solution {
    int graph[101][101]={0,};
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        
        for (int i = 0; i < 101; i++) {
            fill(graph[i], graph[i] + 101, 1e9);
        }
        
        for(int i=0; i<n; i++){
            for(int k=0; k<n; k++){
                if(i==k) graph[i][k]=0;
            }
        }
        
        for(int i=0; i<edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            int cost = edges[i][2];
            graph[a][b] = cost;
            graph[b][a] = cost;
        }
        
        
        for(int k=0; k<n; k++){
            for(int a=0; a<n; a++){
                for(int b=0; b<n; b++){
                    graph[a][b]=min(graph[a][b],graph[a][k]+graph[k][b]);
                }
            }
        }
        
        int ans=0,city=1e9;
        
        for(int i=0; i<n; i++){
            int cnt=0;
            for(int k=0; k<n; k++){
                if(graph[i][k]<=distanceThreshold) cnt++;
            }
            
            if(city>=cnt){
                ans=i;
                city=cnt;
            }
        }
        return ans;
    }
};
