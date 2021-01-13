#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
ll summ(ll n){
    return (n * (n + 1) / 2)% M;
}
ll rangesum(ll a, ll b){
    return (summ(a) - summ(b)) % M;
}
ll totalsum(ll n){
    ll i = 1;
    ll res = 0;
    while (n){
        res += rangesum(n/i,n/(i + 1)) * (i % M) % M;
        res%=M;
        if (i == n) break;
        i = (n / (n /(i + 1)));
    }
    return res;
} 
int main(){
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    cout << totalsum(n) << endl;    
    return 0;
}