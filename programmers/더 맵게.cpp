#include <string>
#include <vector>
#include <queue>

using namespace std;


int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int,vector<int>,greater<int>>pq;
    
    for(int i=0; i<scoville.size(); i++){
        pq.push(scoville[i]);
    }
    
    while(pq.top()<K){
        if(pq.size()==2){
            int a=pq.top(); pq.pop();
            int b=pq.top(); pq.pop();
            int mix=a+(b*2);
            if(mix<K){
                answer=-1;
                break;
            }
            else{
                answer++;
                break;
            }
        }
      else if(pq.size()!=1){
            answer++;
            int a=pq.top(); pq.pop();
            int b=pq.top(); pq.pop();
            int mix=a+(b*2);          
            pq.push(mix);
        }        
    }   
    
    return answer;
}
