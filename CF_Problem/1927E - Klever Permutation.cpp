#include<bits/stdc++.h>
using namespace std;                                  // here time complexity k *(n/k) = O(n)  thus we can itetate over a loop by k increasing each time  is linear time-----

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n+1);
    int j=1;
    int revj=n;
    for(int i=1;i<=k;i++){

        if(i&1){
         int pos=i;
         while(pos<=n){
            a[pos]=j;
            j++;
            pos+=k;
         }
        }
        else{

            int pos=i;

            while(pos<=n){
                a[pos]=revj;
                revj--;
                pos+=k;
            }
        }
    }

    a.erase(a.begin() + 0);

    for(auto i : a)
    cout<<i<<" ";
    cout<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--)
    solve();
}
