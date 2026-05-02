class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, float>> cars; 
        stack<float> st;

        for(int i=0; i < position.size(); i++){
            float time = (float) ( target - position[i] )/ speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end());

        for(int i = cars.size()-1; i >=0; i--){

            if(st.empty()){
                st.push(cars[i].second);
            }
            else if (st.top() < cars[i].second ){
                //require more hours so cant part this fleet so create new one 
                st.push(cars[i].second);
            }
        }

        return st.size();
    }
};
