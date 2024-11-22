class Solution {
public:                                                                   // Leetcode 3347
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        // 1-> add
        // 2->
        // 3-> remove
        map<int,int>fq;
        vector<pair<int,int>>events;

        for(auto num : nums){
            fq[num]++;
            events.push_back({num-k, 1});
            events.push_back({num, 2});
            events.push_back({num+k, 3});
        }
        int cnt=0;
        int res=0;
        sort(events.begin(), events.end());
        for(auto & [num, type] : events){
             if(type==1){
                cnt++;
             }
             else if(type==3){
                cnt--;
             }
           int  reqNumOp=cnt - fq[num];

             res = max(res, fq[num]+ min(reqNumOp, numOperations));
        }

        return res;

        
    }
};
