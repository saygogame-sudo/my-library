#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uns= unsigned long long;
#define judge(a) if(a){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define rep(i,a,b) for(ll i = (a); i < (b); i++)


//配列の出力
void output(vector<int> data){
    rep(i,0,data.size()-1){
        cout<<data[i]<<' ';
    }
    cout<<data[data.size()-1]<<endl;
}

