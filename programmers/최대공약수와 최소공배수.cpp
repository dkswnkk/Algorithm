#include <string>
#include <vector>
#include <iostream>



using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
vector<int> solution(int n, int m) {
    vector<int> answer;
    
    int inp = gcd(n,m);
    answer.push_back(inp);
    answer.push_back(n*m/inp);
    return answer;
}
