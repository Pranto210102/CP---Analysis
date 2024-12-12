#include<bits/stdc++.h>
using namespace std;                                        //Number of Subarray with at most K distinct
                                          
int freq[1000001];

void solve(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];

    int tail=0,head=-1;
    long long ans=0;
    int distinct=0;
    
    while(tail<n){
        while(head+1<n && (distinct<k || freq[a[head+1]]>=1)){
            head++;
            
            if(freq[a[head]]==0){
                distinct++;
            }
            freq[a[head]]++;

        }
        ans+=(head- tail +1);
        if(tail>head){
            tail++;
            head=tail-1;
        }else{
            freq[a[tail]]--;
            if(freq[a[tail]]==0){
                distinct--;
            }

            tail++;
        }
    }

    cout<<ans<<"\n";

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
