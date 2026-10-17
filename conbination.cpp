#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uns= unsigned long long;
#define judge(a) if(a){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define rep(i,a,b) for(ll i = (a); i < (b); i++)

//nCr (mod m)
ll conbination(ll n,ll r, ll m){
    ll bunsi=1;
    rep(i,n-r+1,n+1){
        bunsi*=i;
        bunsi%=m;
    }
    ll bunbo=1;
    rep(i,1,r+1){
        bunbo*=i;
        bunbo%=m;
    }

    ll bo=1;
    ll copy=m;
    m-=2;
    vector<int> a(40);
    rep(i,1,40){
        a[i]=m%2;
        m/=2;
    }
    m=copy;
    vector<ll> B(40);
    B[1]=bunbo;
    rep(i,2,40){
        B[i]=B[i-1]*B[i-1];
        B[i]%=m;
    }
    rep(i,1,40){
        if(a[i]){
            bo*=B[i];
            bo%=m;
        }
    }
    bunsi*=bo;
    bunsi%=m;
    return bunsi;
}