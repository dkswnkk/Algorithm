#include <string>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

char map[17][17];

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0; i<arr1.size(); i++){
        int cnt = n;
        int num = arr1[i];
        string bit = "";
        while(cnt--){
            bit+=(num%2)+'0';
            num/=2;
        }
        reverse(bit.begin(),bit.end());
        for(int k=0; k<n; k++){
            if(bit[k]=='0'&&map[i][k]!='#') map[i][k] = ' ';
            else if(bit[k]=='1') map[i][k] = '#';
        }
    }
    for(int i=0; i<arr2.size(); i++){
        int cnt = n;
        int num = arr2[i];
        string bit = "";
        while(cnt--){
            bit+=(num%2)+'0';
            num/=2;
        }
        reverse(bit.begin(),bit.end());
        for(int k=0; k<n; k++){
            if(bit[k]=='0'&&map[i][k]!='#') map[i][k] = ' ';
            else if(bit[k]=='1') map[i][k] = '#';
        }
    }
    
    for(int i=0; i<n; i++){
        string inp ="";
        for(int k=0; k<n; k++){
            inp+=map[i][k];
        }
        answer.push_back(inp);
    }
    return answer;
}
