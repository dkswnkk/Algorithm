//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/6550
//  BOJ6550 부분 문자열

#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    string find_string,origin_string;
    
    while(cin>>find_string>>origin_string){
        string temp;
        int k=0;
        
        if(find_string.length()>origin_string.length()){
            cout<<"No"<<'\n';
        }
        else{
            for(int i=0; i<find_string.length(); i++){
                for(; k<origin_string.length(); k++){
                    if(find_string[i]==origin_string[k]){
                        temp+=origin_string[k];
                        k++;
                        break;
                    }
                }
            }
            if(temp==find_string) cout<<"Yes"<<'\n';
            else cout<<"No"<<'\n';
        }
    }
}
