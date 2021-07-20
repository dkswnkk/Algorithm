#include <string>
#include <vector>
#include <algorithm>


using namespace std;

bool cmp(string a, string b){
    
    if(a.length()!=b.length())  return stoi(a+b)>stoi(b+a);
    else return stoi(a)>stoi(b);
    
}



string solution(vector<int> numbers) {
    string answer = "";
    vector<string>temp;
    
    for(int i=0; i<numbers.size(); i++){
        temp.push_back(to_string(numbers[i]));
    }
    
    sort(temp.begin(),temp.end(), cmp);
    
    for(int i=0; i<temp.size(); i++){
        answer+=temp[i];
    }
    
    if(answer[0]=='0') return "0";
    else return answer;
}
