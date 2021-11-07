#include <string>
#include <vector>
#include <map>
using namespace std;

map<int,int>m;

int solution(vector<int> numbers) {
    int answer = 0;
    for(int i=0; i<=9; i++) m[i]++;
    for(int i:numbers) m[i]++;
    for(auto i=m.begin(); i!=m.end(); i++){
        if(i->second==1) answer+=i->first;
    }
    return answer;
}
