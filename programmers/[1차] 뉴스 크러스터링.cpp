#include <algorithm>
#include <string>
#include <map>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    int sum=0,cnt=0;
    
    map<string,int>A,B,m;
    
    for(int i=0; i<str1.length(); i++){   //대문자->소문자 변경
        str1[i]=tolower(str1[i]);
    }
    for(int i=0; i<str2.length(); i++){   //대문자->소문자 변경
        str2[i]=tolower(str2[i]);
    }
    for(int i=0; i<str1.length()-1; i++){
        if(str1[i]>='a'&&str1[i]<='z'&&str1[i+1]>='a'&&str1[i+1]<='z'){ //숫자일때
            string temp=str1.substr(i,2);
            A[temp]++;
            m[temp]++;
        }
    }
    for(int i=0; i<str2.length()-1; i++){
        if(str2[i]>='a'&&str2[i]<='z'&&str2[i+1]>='a'&&str2[i+1]<='z'){ //숫자일때
            string temp=str2.substr(i,2);
            B[temp]++;
            m[temp]++;
        }
    }
    
    for(auto it=m.begin(); it!=m.end(); it++){
        cnt+=min(A[it->first],B[it->first]);
        sum+=max(A[it->first],B[it->first]);
    }
    if(sum==0&&cnt==0) sum=1,cnt=1;
    answer=(double)cnt/(double)sum*65536;
    return answer;
}
