//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnzz
//  https://www.acmicpc.net/problem/4999
//  BOJ4999 아!


#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string peo,doc; cin>>peo>>doc;
    
    bool flag =false;
    if(doc.length()>peo.length()) cout<<"no";   //재환이가 낼 수 있는 소리보다 의사가 요구하는 소리가 더 길경우
    else{
        for(int i=0; i<peo.length(); i++){
            for(int k=0; k<doc.length(); k++){
                if(peo[i]==doc[k]){ //재환이의 말과 의사의 말이 같을때
                    flag=true; //플래그를 참으로 저장
                }
            }
            if(flag){
                cout<<"go";
                break;
            }
        }
    if(!flag) cout<<"no";
    }
}
