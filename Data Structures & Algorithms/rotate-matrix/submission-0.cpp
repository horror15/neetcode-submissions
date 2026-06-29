class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i=0; 
        int j = matrix.size()-1;

        while(i<j){
            for(int k=0; k<matrix.size(); k++){
                int tmp = matrix[i][k];
                matrix[i][k] = matrix[j][k];
                matrix[j][k] = tmp; 
            }
            i++;
            j--;
        }
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix.size(); j++){
                if(i<=j){
                    int tmp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = tmp;
                }
            }
        }
    }

};
