#include<bits/stdc++.h>
using namespace std;

int n;
int d;

string cur;

void rec(int level, int depth){
    
     if(level==n){
        if(depth==0){
            cout<<cur<<"\n";
        }
        return;
     }
     // '('

     if(depth+1<=d){
         cur+='(';
         rec(level+1, depth+1);
         cur.pop_back();
     }
     // ")"

     if(depth-1>=0){
        cur+=')';
        rec(level+1, depth-1);
        cur.pop_back();
    }

}

int main(){
    cin>>n>>d;
    rec(0,0);
}
