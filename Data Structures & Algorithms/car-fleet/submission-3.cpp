class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, float>> cars; 
        int result = 0; 
        float cur_min;

        for(int i=0; i < position.size(); i++){
            float time = (float) ( target - position[i] )/ speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end());

        for(int i = cars.size()-1; i >=0; i--){
            float dist = cars[i].second; 
            if(result == 0){
                cur_min =dist;
                result++;
            }
            else if (cur_min < dist ){
                cur_min = dist;
                result++;
            }
        }

        return result;
    }
};
