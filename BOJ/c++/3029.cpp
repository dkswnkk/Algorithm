//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/3029
//  BOJ3029 경고

#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string now,Na; cin>>now>>Na;
    int now_time,Na_time,ans;
    now_time=stoi(now.substr(0,2))*3600+stoi(now.substr(3,5))*60+stoi(now.substr(6,8));
    Na_time=stoi(Na.substr(0,2))*3600+stoi(Na.substr(3,5))*60+stoi(Na.substr(6,8));
    
    ans=86400-now_time+Na_time;
    if(ans>86400) ans=abs(86400-ans);
    string hour,min,sec;
    hour=to_string(ans/3600);
    ans%=3600;
    min=to_string(ans/60);
    ans%=60;
    sec=to_string(ans);
    
    if(hour.length()==1) hour='0'+hour;
    if(min.length()==1) min='0'+min;
    if(sec.length()==1) sec='0'+sec;
    cout<<hour<<':'<<min<<':'<<sec;
 
}
