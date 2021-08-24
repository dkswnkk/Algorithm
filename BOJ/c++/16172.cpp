//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/16172
//  BOJ16172 나는 친구가 적다(Large)

#include <iostream>
#include <string.h>
#define MAX 200001
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    char origin[MAX],find[MAX]; cin>>origin>>find;;
    string temp;
    
    for(int i=0; i<MAX; i++){
        if(!(origin[i]>='0'&&origin[i]<='9')) temp+=origin[i];
    }
    
    for(int i=0; i<temp.length(); i++){
        origin[i]=temp[i];
    }
    char *ans=strstr(origin,find);
    if(ans!=NULL) cout<<1;
    else cout<<0;
    
    
}
