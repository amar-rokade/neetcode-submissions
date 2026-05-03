class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mt, int t) {
    
        
                // int start = 0; 
                // int end = m[i].size()-1;
                // int mid;
                // while(start <= end){
                //     mid= start  + (end - start)/2;
                //     if(m[i][mid] == t) return true;
                //     else if(m[i][mid] < t) start = mid +1 ;
                //     else end = mid -1;
                // }
                // return false;
        
        int r = mt.size();
        int c= mt[0].size();

        int start = 0; 
        int end = (c * r) - 1;
        int mid;

        while(start <= end){
            mid = start + (end -start)/2;
            int value = mt[mid/c][mid% c];
            if(t == value)return true;
            else if(value  < t) start = mid +1;
            else end = mid -1;
        }
        return false;
        
    }
};
