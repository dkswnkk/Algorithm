#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

string solution(string s) {
    string answer = "",temp;
    vector<int>v;
    
    for(int i=0; i<s.length()+1; i++){
        if(s[i]!=' '&&s[i]!='\0') temp+=s[i];
        else{
            v.push_back(stoi(temp));
            temp.clear();
        }
    }
    sort(v.begin(),v.end());
    
    
    answer+=to_string(v[0]);
    answer+=" ";
    answer+=to_string(v[v.size()-1]);    
    return answer;
}
