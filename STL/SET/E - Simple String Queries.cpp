#include<bits/stdc++.h>
using namespace std;
                                                 // SET IN QUERYES FOR DISTINCT CHAR
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<set<int>>vs(26);

    for(int i=0;i<n;i++){
         int x=s[i]-'a';
         vs[x].insert(i);
    }

    int q;
    cin>>q;
    while(q--){
        int t;
        cin>>t;
        if(t==2){
            int l,r;
            cin>>l>>r;
            r--;
            l--;
            int cnt=0;
            for(int i=0;i<26;i++){
                
                if(vs[i].empty()) continue;

                auto lo =vs[i].lower_bound(l);
                
                if(lo==vs[i].end()) continue;

                int ll = *lo;

                if(ll>r)continue;

                cnt++;
            }

            cout<<cnt<<"\n";
        }
        else{
            int pos;
            char ch;
            cin>>pos>>ch;

            pos--;

            int x=s[pos]-'a';
            int y=ch-'a';

            vs[x].erase(pos);

            vs[y].insert(pos);

            s[pos]=ch;
        }
    }
}
