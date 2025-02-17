#include<bits/stdc++.h>                       //https://codeforces.com/problemset/problem/702/C
using namespace std;
#define ll long long 
#define int long long

int a[200200];
int b[200200];
 int n,m;

bool check(ll mid){
    ll lastTowerCoverTill=-1e18;
    for(int i=0;i<n;i++){
        if(lastTowerCoverTill>=a[i])continue;

        int low = a[i]-mid;
        int high= a[i]+mid;

        auto itr = upper_bound(b,b+m, high);

        if(itr==b){
            return 0;
        }
        itr--;
        if(*itr>=low){
            lastTowerCoverTill= (*itr) + mid;
        }else{
            return 0;
        }
    }

    return 1;

}
signed main(){
   
    cin>>n>>m;
    
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];

    ll low = 0;
    ll high = 2e10+1;
    ll ans =high;
    while(low<=high){

         ll mid = (low+high)/2LL;
         if(check(mid)){
             high=mid-1;
             ans = mid;
         }else{
            low =mid+1;
         }
    }

    cout<<ans<<"\n";
}
