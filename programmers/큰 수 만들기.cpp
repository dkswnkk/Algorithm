#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int index = 0;
    for(int i=0; i<number.length()-k; i++){
        int max_val = 0;
        for(int j=index; j<=k+i; j++){
            if(number[j]-'0'>max_val){
                max_val = number[j]-'0';
                index = j+1;
            }
        }
        answer+=to_string(max_val);
    }
    return answer;
}

