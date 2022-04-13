#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define MAX 9999999+1
using namespace std;
int visited[MAX];
vector<bool> prime (MAX, true); // true일때 소수

int cnt = 0;

void permutation(string inp, string origin, int index){
    if(inp.length()>origin.length()) return;
    
    string number = inp;
    reverse(number.begin(),number.end());
    while(!number.empty()&&number.back()==0) number.pop_back();
    reverse(number.begin(),number.end());
    if(!number.empty()&&prime[stoi(number)]&&!visited[stoi(number)]){
        visited[stoi(number)] = 1;
        //        cout<<"조합: "<< stoi(number)<<'\n';
        cnt++;
    }
    
    
    for(int i=index; i<origin.length(); i++){
        string temp = number + origin[i];
        permutation(temp, origin, i+1);
    }
}
int solution(string numbers) {
    int answer = 0;
    
    prime[0] = false, prime[1] = false;
    for(int i=2; i<=MAX; i++){
        if (prime[i] == true) {
            int k = 2;
            while (i * k <= MAX) {
                prime[i * k] = false;
                k++;
            }
        }
    }
    sort(numbers.begin(),numbers.end());
    do{
        permutation("",numbers, 0);
    }while(next_permutation(numbers.begin(),numbers.end()));
    
    answer = cnt;
    return answer;
}
