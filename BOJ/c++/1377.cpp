//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/1377
//  BOJ1377 버블 소트

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 배열의 값이 몇 번 인덱스로 이동했는지 구하면 버블 정렬 횟수를 알아낼 수 있다.
 정렬 전과 정렬 후의 인덱스를 비교하여 좌측으로 이동한 값 중 그 차가 가장 큰 값이 출력 값이 된다.

  

 정렬 전
 [0    1    2    3    4 ]   // 인덱스번호
 10    1    5    2    3

  

 정렬 후

 [1    3    4    2    0 ]
  1    2    3    5    10

 인덱스의 차를 구하여 그 값이 양수이면 좌측으로 이동했음을 알 수 있다.

 1    3    4    2    0

 0    1    2    3    4
--------------------------- (빼기)
 1    2    2    -1   -4

 인덱스의 차 중 가장 큰 값+1이 원하는 출력 값이다.
 */
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,ans=-1; cin>>n;
    vector<pair<int,int>>v;
    
    for(int i=0; i<n; i++){
        int inp; cin>>inp;
        v.push_back({inp,i});
    }
    sort(v.begin(),v.end());
    for(int i=0; i<n; i++){
        if(v[i].second-i>=0) ans=max(ans,abs(v[i].second-i));
    }
    cout<<ans+1;
}
