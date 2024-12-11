#include<bits/stdc++.h>
using namespace std;             // XOR tricks . see how xor changes 

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    string s;
    cin>>s;
    int xor_zero_pos=0, xor_one_pos=0;

    int xor_arr[n];

    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            xor_zero_pos^=a[i];
        }else{
            xor_one_pos^=a[i];
        }
        if(i==0){
            xor_arr[i]=a[i];
        }else{
            xor_arr[i]=xor_arr[i-1]^a[i];
        }
    }

    int q;
    cin>>q;
    while(q--){
        int t;
        cin>>t;
        if(t==1){

            int l,r;
            cin>>l>>r;
            l--;
            r--;

            int xor_val = xor_arr[r]^(l>0? xor_arr[l-1] : 0);

            xor_one_pos^=xor_val;
            xor_zero_pos^=xor_val;

        }
        else{
            int g;
            cin>>g;
            if(g==0){
                cout<<xor_zero_pos<<" ";
            }else{
                cout<<xor_one_pos<<" ";
            }
        }
    }

    cout<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--)
    solve();
}
