#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    map<int,int>m;
    for(int i=0; i<numbers.size()-1; i++){
        for(int k=i+1; k<numbers.size(); k++){
            m[numbers[i]+numbers[k]]++;
        }
    }
    for(auto i=m.begin(); i!=m.end(); i++){
        answer.push_back(i->first);
    }
    return answer;
}
