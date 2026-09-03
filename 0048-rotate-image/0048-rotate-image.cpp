class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //find transpose
        for(int i =0; i<n; i++){
            for(int j=i; j<n; j++){
                //swap
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        //reverse each row
        for(int i=0; i<n; i++){
            //reverse ith row
            for(int j=0; j<n/2; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n-j-1];
                matrix[i][n-j-1] = temp;
            }
        }
    }
};