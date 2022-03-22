// 01:19(문제 이해 시작)
// 01:27(문제 구현 시작) ~ 01:44(풀이 완료)
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    
    int answer = 0;
    map<int,int>docs;
    queue<int>q;
    
    
    for(int i=0; i<priorities.size(); i++){
        docs[i] = priorities[i]; // 문서마다 우선순위 부여
        q.push(i);  //문서 이름 부여
    }
    
    
    sort(priorities.begin(), priorities.end(), greater<>());
    
    
    while(!priorities.empty()){
        if(docs[q.front()]!=priorities.front()){  //현재 뺴넨 문서보다 우선순위 문서가 존재한다면
            int doc = q.front();
            q.pop();
            q.push(doc);
            
        }
        else{
            answer++;
            priorities.erase(priorities.begin());
            if(q.front()==location) break;
            q.pop();
        }
    }
    
    
    return answer;
}
