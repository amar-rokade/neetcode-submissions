class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
    
        for(int i = 0; i < m.size(); i++ ){
            if(m[i][0] <= t && t <= m[i][m[i].size()-1]){
                int start = 0; 
                int end = m[i].size()-1;
                int mid;
                while(start <= end){
                    mid= start  + (end - start)/2;
                    if(m[i][mid] == t) return true;
                    else if(m[i][mid] < t) start = mid +1 ;
                    else end = mid -1;
                }
                return false;
            }
        }
        return false;
    }
};
