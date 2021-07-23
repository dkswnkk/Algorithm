#include <iostream>
#include <string>
#include <vector>


using namespace std;

long long int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

int solution(vector<int> arr) {
    int answer = 0;
    
    long long int gcd_value=1,lcm_value=1;
    
    if(arr.size()==1) lcm_value=arr[0];
    else{
        lcm_value = arr[0];
        for(int i=1; i<arr.size(); i++){
            lcm_value = (lcm_value * arr[i]) / gcd(lcm_value,arr[i]);
        }
    }
    
    
    answer=lcm_value;
    
    return answer;
}
