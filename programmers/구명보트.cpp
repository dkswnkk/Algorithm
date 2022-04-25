#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pq;    // 최소 힙
    sort(people.begin(),people.end(),greater<>());  // 내림차순 정렬
    
    for(int i=0; i<people.size(); i++){
        if(pq.empty()) pq.push(people[i]);
        else{
            if(people[i]+pq.top()<=limit){
                pq.pop();
                answer++;
            }
            else pq.push(people[i]);
        }
    }
    return answer+pq.size();
}
