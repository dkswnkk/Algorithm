class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>ans(n);

        for(int i=0; i<n; i++){
            for(int k=n-1; k>=0; k--){
                ans[i].push_back(matrix[k][i]);
            }
        }
        matrix = ans;
    }
};



class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=0; i<n; i++){

            for(int k=0; k<=i; k++){
                swap(matrix[i][k],matrix[k][i]);
            }
        }

        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
