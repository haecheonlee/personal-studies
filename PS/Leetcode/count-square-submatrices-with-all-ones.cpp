class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int max = (m < n) ? m : n;
        int count = 0;
        for(int i=1; i<=max; i++) {
            for(int y=0; y<m; y++) {
                for(int x=0; x<n; x++) {
                    int max_x = x + i;
                    int max_y = y + i;
                    
                    bool check = false;
                    if(max_x <= n && max_y <= m) {
                        check = true;
                        for(int a = y; a < max_y; a++) {
                            for(int b = x; b < max_x; b++) {
                                if(matrix[a][b] == 0) {
                                    check = false;
                                    break;
                                }
                            }
                            
                            if(!check) break;
                        }                        
                    }
                    
                    if(check) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};

/*
https://leetcode.com/problems/count-square-submatrices-with-all-ones/
*/
