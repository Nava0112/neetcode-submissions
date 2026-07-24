class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n = position.size();
        map<int,double> mp;

        for(int i=0;i<n;i++){
            mp[position[i]] =
                (double)(target-position[i]) / speed[i];
        }

        int fleets = 0;
        double prev = -1;

        for(auto it = mp.rbegin(); it != mp.rend(); ++it){

            if(prev == -1 || it->second > prev){
                fleets++;
                prev = it->second;
            }
        }

        return fleets;
    }
};