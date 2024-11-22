int minimumDifference(vector<int>& nums, int k) { // Leetcode 3171
        int n=nums.size();
        set<int>fasiable;
        int ans=INT_MAX;
        for(int i=n-1;i>=0;i--){
            set<int>new_fasiable;

            for(auto v : fasiable){
                new_fasiable.insert(nums[i] | v);
            }
            new_fasiable.insert(nums[i]);
            
           // cout<<"start indx "<<i<<"\n";

            for(auto v : new_fasiable){
               // cout<<v<<" ";
                ans=min(ans, abs(v-k));
            }
           // cout<<"\n";

            fasiable=new_fasiable;
        }

        //cout<<ans<<"\n";

        return ans;

        
    }
