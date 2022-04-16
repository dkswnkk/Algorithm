#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string s) {
    
    if(islower(s[0])) s[0] = toupper(s[0]);
    for(int i=1; i<s.length(); i++){
        if(!isdigit(s[i-1])&&!isalpha(s[i-1])) s[i]=toupper(s[i]);
        else s[i] = tolower(s[i]);
    }
    return s;
}
