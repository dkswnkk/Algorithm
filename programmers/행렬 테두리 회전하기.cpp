#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    vector<int>v[10001];
    int num = 1;
    
    for(int i=0; i<rows; i++){
        for(int k=0; k<columns; k++){
            v[i].push_back(num);
            num++;
        }
    }
    
    for(int i=0; i<queries.size(); i++){
        int min_value = 1e9;
        int x1 = queries[i][0]-1, y1 = queries[i][1]-1;
        int x2 = queries[i][0]-1, y2 = queries[i][3]-1;
        int x3 = queries[i][2]-1, y3 = queries[i][3]-1;
        int x4 = queries[i][2]-1, y4 = queries[i][1]-1;
        int temp = v[x1][y1];
        
        for(int i=x1; i<x4; i++){
            v[i][y1] = v[i+1][y1];
            min_value = min(min_value, v[i][y1]);
        }
        for(int i=y4; i<y3; i++){
            v[x3][i] = v[x3][i+1];
            min_value = min(min_value, v[x3][i]);
        }
        for(int i=x3; i>x2; i--){
            v[i][y3] = v[i-1][y3];
            min_value = min(min_value, v[i][y3]);
        }
        for(int i=y2; i>y1; i--){
            v[x2][i] = v[x2][i-1];
            min_value = min(min_value, v[x2][i]);
        }
        v[x1][y1+1] = temp;
        min_value = min(min_value, temp);
        answer.push_back(min_value);
    }
    
    return answer;
}
