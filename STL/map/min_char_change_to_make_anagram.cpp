#include<bits/stdc++.h>
using namespace std;
vector<int>mp_s(26), mp_t(26);
int n,m;
int ans =0;

void add (int x){
    ans -= max(0, mp_s[x] - mp_t[x]);
    mp_s[x]++;
    ans += max(0, mp_s[x] - mp_t[x]);
}

void cut (int x){
    ans -= max(0, mp_s[x] - mp_t[x]);
    mp_s[x]--;
    ans +=max(0, mp_s[x] - mp_t[x]);
}

int main(){
    cin>>n>>m;
    string s,t;
    cin>>s>>t;

    for(int i=0;i<m;i++){
        mp_t[t[i]-'a']++;
    }

    for(int i=0;i<n;i++){
        //insert
        add(s[i]-'a');
        
        // remove
        if(i-m>=0){
            cut(s[i-m]-'a');
        }

        // check
        if(i>=m-1){
            cout<<ans<<" ";
        }
    }
}
