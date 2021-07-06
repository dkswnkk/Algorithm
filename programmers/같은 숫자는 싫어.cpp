#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr){
    vector<int> answer;
    
    int flag=0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]!=flag||i==0){
            answer.push_back(arr[i]);
            flag=arr[i];
        }
        if(arr[i]==arr[i+1]) i++;
    }
    
    return answer;
}
