
class Solution {
public:
    vector<pair<int,int>>graph[101];
    int d[101];
    
    void dijkstra(int start){
        priority_queue<pair<int,int>>pq;
        pq.push({0,start});
        d[start]=0;
        
        while(!pq.empty()){
            int dist = -pq.top().first;
            int now  = pq.top().second;
            pq.pop();
            if(d[now]<dist) continue;
            
            for(int i=0; i<graph[now].size(); i++){
                int cost = dist + graph[now][i].second;
                int neighbor = graph[now][i].first;
                if(cost<d[neighbor]){
                    d[neighbor] = cost;
                    pq.push({-cost,neighbor});
                }
            }
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(int i=0; i<times.size(); i++){
            graph[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        
        fill(d,d+101,1e9);
        
        dijkstra(k);
        
        int ans=0;
        
        for(int i=1; i<=n; i++){
            if(d[i]==1e9) return -1;
            else ans=max(ans,d[i]);
        }
        
        return ans;
    }
    
};
