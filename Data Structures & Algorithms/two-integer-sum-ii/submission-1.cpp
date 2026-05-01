class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int n= numbers.size();

        for(int i=0; i < n-1; i++){
            int comp = target - numbers[i];

            for(int j=i+1; j <n; j++){
                if(numbers[j] == comp) return {i+1, j+1};
            }
        }
        return {};
    }
};
