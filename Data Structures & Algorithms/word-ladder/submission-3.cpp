class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int count = 0;
        int n=wordList.size();
        priority_queue<pair<int,string>>q;
        unordered_set<string>st(wordList.begin(), wordList.end());
        if(!st.count(endWord)) return 0;
        q.push({1,beginWord});
        while(!q.empty()){
            auto [cnt, word] = q.top();
            q.pop();
            for(int i=0; i<word.size(); i++){
                string temp = word;
                for(char j='a'; j<='z'; j++){
                    temp[i]=j;
                    if(temp == endWord) return cnt+1;
                    if(st.count(temp)){
                        q.push({cnt+1,temp});
                        st.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};
