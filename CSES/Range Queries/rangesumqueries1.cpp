#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
int n,m;
vector<ll> fen(1000000);
void increase(int p, ll value){
    for (int i = p; i <= n; i+=i&-i){
        fen[i]+=value;
    }
}
ll sum(int p){
    ll res = 0;
    for (int i = p; i; i-=i&-i){
        res += fen[i];
    }
    return res;
}
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        increase(i,x);
    }    
    while (m--){
        int x,y;
        cin >> x >> y;
        cout << sum(y) - sum(x - 1) << endl;
    }
    return 0;
}