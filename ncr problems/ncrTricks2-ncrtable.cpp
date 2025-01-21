const int MAX = 1002;
ll ncr[MAX + 1][MAX + 1];

void precomput() {
    for (int i = 0; i <= MAX; i++) {
        ncr[i][0] = 1;  
        ncr[i][i] = 1;  
    }
    for (int i = 1; i <= MAX; i++) {         //pascle's triangle
        for (int j = 1; j < i; j++) {
            ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j]) % mod;
        }
    }
}


// another code ------------
int mod=1e9+7;
    int ncr[100001][71];
    void precomput(int n){
       
        for(int i=0;i<=n;i++){
            for(int j=0;j<=min(70,i);j++){
               if(j==0)ncr[i][j]=1;
               else {
                  ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j])%mod;
               }
            }
        }
    }
