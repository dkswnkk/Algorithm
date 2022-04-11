#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    
    map<int,bool> prime;
    sort(nums.begin(), nums.end());
    for(int i=0; i<=nums.back()*3; i++) prime[i] = true;
    prime[0] = prime[1] = false;
    for(int i=2; i<=nums.back()*3; i++){  //소수 저장
        if(prime[i]==true){
            int k = 2;
            while(i*k <=nums.back()*3){
                prime[i*k] = false;
                k++;
            }
        }
    }
    
    for(int a=0; a<nums.size()-2; a++){
        for(int b=a+1; b<nums.size()-1; b++){
            for(int c=b+1; c<nums.size(); c++){
                int check_num = nums[a] + nums[b] + nums[c];
                if(prime[check_num]) answer++;
            }
        }
    }
    
    return answer;
}
