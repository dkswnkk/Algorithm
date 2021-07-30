//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/1107
//  BOJ1107 리모컨

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int broken[11]={1,1,1,1,1,1,1,1,1,1};

bool check(int i){
    string s = to_string(i);
    for(int i=0; i<s.length(); i++){
        if(!broken[s[i]-'0']) return false; //버튼이 고장났으면 false
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N,M; cin>>N>>M;
    
    for(int i=0; i<M; i++){     //고장 난 버튼 입력
        int broken_num; cin>>broken_num;
        broken[broken_num]=0;
    }
    
    int ans=abs(N-100); //100번 부터 원하는 번호까지 ++ 혹은 --만 해서 가는 경우,
    
    for(int i=0; i<=1000000; i++){
        if(check(i)){   //입력 가능할때
            int click=abs(N-i)+(int)to_string(i).length();  //번호 자릿수만큼  입력 + 그 번호부터 ++ 혹은 -- 갯수 체크
            ans=min(ans,click);
        }
    }
    
    cout<<ans;
}
