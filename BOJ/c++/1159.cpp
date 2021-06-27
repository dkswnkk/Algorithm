//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnzz
//  https://www.acmicpc.net/problem/1159
//  BOJ1159 농구 경기

#include <iostream>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    map<char,int>m;
    int n; cin>>n;
    while(n--){ //모든 이름 입력
        string name; cin>>name;
        m[name[0]]++;
    }
    
    bool flag=false;
    for(auto i=m.begin(); i!=m.end(); i++){
        if(i->second>=5){   //같은 성을 가진 선수가 5명 이상일경우
            flag=true;  //선발 유무를 참을 바꾼다.
            cout<<i->first; //성을 출력 한다.
        }
    }
    if(!flag) cout<<"PREDAJA"; //선발이 불가 할 경우 불가 출력
}
