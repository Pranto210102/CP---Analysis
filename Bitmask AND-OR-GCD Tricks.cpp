#include<bits/stdc++.h>  // Leetcode 400 D problem
using namespace std;

void minimumDifference(vector<int>& nums,   map<int,vector<pair<int,int>>>&mp) {
    int n = nums.size();
    map<int, int> fasiable;  
   

    for(int i = n - 1; i >= 0; i--) {                
        map<int, int> new_fasiable;

        for(auto v : fasiable) {                
            int newValue = nums[i] & v.first;
            if(new_fasiable.find(newValue) == new_fasiable.end()) {
                new_fasiable[newValue] = max(v.second, i);
            } else {
                new_fasiable[newValue] = max(new_fasiable[newValue], max(v.second, i));
            }
        }
       
        if(new_fasiable.find(nums[i]) == new_fasiable.end()) {
            new_fasiable[nums[i]] = i;
        } else {
            new_fasiable[nums[i]] = max(new_fasiable[nums[i]], i);
        }        

       
       
        for(auto v : new_fasiable) {
           
            mp[i].push_back({v.first,v.second});
        }
        cout << "\n";

        fasiable = new_fasiable;
    }

}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    map<int,vector<pair<int,int>>>mp;
    minimumDifference(a, mp);

    for(auto it : mp){
        cout<<"start indx  "<<it.first<<"\n";

        for(int j=it.second.size()-1; j>=0 ;j--){
            cout<<it.second[j].first << " "<<it.second[j].second<<"\n";
        }
        cout<<"\n";
    }
}

// EX- 
// 5
// 1 3 1 3 4
// start indx  0
// 1 3(end index, value in mid)
// 0 4

// start indx  1
// 3 1
// 1 3
// 0 4

// start indx  2
// 1 3
// 0 4

// start indx  3
// 3 3
// 0 4

// start indx  4
// 4 4




