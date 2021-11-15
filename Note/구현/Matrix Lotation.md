<img src = "https://user-images.githubusercontent.com/74492426/141762284-228733a1-088b-44e9-9e34-8f0b762f174d.png" width="50%" height="50%">

In-Place Lotation
--
```cpp

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
```

