bool is_prime(ll n){
    if(n<2) return 0;
    if(n== 2 || n==3 ) return 1;
    if(n%2==0 || n%3 == 0) return 0;

    for(ll i=5LL;i*i<=n;i+=6LL){
        if(n%i==0 || n%(i+2)==0 ) return 0;
    }

    return 1;
}
