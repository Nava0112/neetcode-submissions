class Solution {
public:
    // formula = (maxfreq-1)*(n+1)+countMax
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>map;
        for(char a:tasks){
            map[a]++;
        }
        int maxfreq=0;
        int cntmax=0;
        for(auto a:map){
            if(a.second==maxfreq) cntmax++;
            if(a.second > maxfreq){
                cntmax=1;
                maxfreq=a.second;
            }
        }
        return max((int)tasks.size(),(maxfreq-1)*(n+1)+cntmax);
    }
};
