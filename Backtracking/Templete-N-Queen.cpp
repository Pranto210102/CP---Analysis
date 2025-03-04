#include<bits/stdc++.h>
using namespace std;
                            // LCCM Framwork...................
int n;
vector<int>queens;

void printer(){
    cout<<"queens { ";
    for(auto it : queens){
        cout<<it<<",";
    }
    cout<<" }\n";
}


bool is_valid(int row, int col){
    for(int prow=0;prow<row;prow++){
        int pcol=queens[prow];
        if(col == pcol || abs(col-pcol)==abs(row-prow)){
            return 0;
        }
    }
    return 1;
}

void rec(int level){
    //base case
     if(level==n){
        printer();
        return;
     }
    //choice
    for(int col=0;col<n;col++){
        //check
        if(is_valid(level, col)){
            // move
            queens.push_back(col);
            rec(level+1);
            queens.pop_back();
        }
    }

}

int main(){
    cin>>n;
    rec(0);

}
