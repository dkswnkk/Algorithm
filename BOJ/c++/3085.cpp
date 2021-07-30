//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/3085
//  BOJ3085 사탕게임

#include <iostream>
#include <vector>
#include <iostream>

using namespace std;
vector<vector<char>>v;

int check(vector<vector<char>>&v){
    int ans_temp=0;
    for(int i=0; i<v.size(); i++){  //가장 긴 행 연속부분 탐색
        int check=0;
        for(int k=1; k<v.size(); k++){
            if(v[i][k-1]==v[i][k]) check++;
            else{
                ans_temp=max(check,ans_temp);
                check=0;
            }
        }
        ans_temp=max(check,ans_temp);
    }
    for(int i=0; i<v.size(); i++){    //가장 긴 열 연속부분 탐색
        int check=0;
        for(int k=0; k<v.size()-1; k++){
            if(v[k+1][i]==v[k][i]) check++;
            else{
                ans_temp=max(check,ans_temp);
                check=0;
            }
            
        }
        ans_temp=max(check,ans_temp);
    }
    
    
    return ans_temp;
}

int main(){
    int N,ans=0; cin>>N;
    cin.ignore();
    for(int i=0; i<N; i++){ //입력
        vector<char>temp;
        for(int k=0; k<N; k++){
            char inp; scanf("%c",&inp);
            temp.push_back(inp);
        }
        cin.ignore();
        v.push_back(temp);
    }
    
    
    for(int i=0; i<N; i++){
        for(int k=0; k<N-1; k++){
            swap(v[i][k],v[i][k+1]);    //좌 우 교환
            ans=max(ans,check(v));  //탐색 후 최댓값으로 갱신
            swap(v[i][k],v[i][k+1]); //다시 원상태로 교환.
            swap(v[k][i],v[k+1][i]);    //상 하 교환
            ans=max(ans,check(v));  //탐색 후 최댓값으로 갱신
            swap(v[k][i],v[k+1][i]); //다시 원상태로 교환.
        }
    }
    
    cout<<ans+1;
}
