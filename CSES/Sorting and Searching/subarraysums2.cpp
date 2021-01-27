#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
map<ll,ll> prevsum;
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll t;
    cin >> n >> t;
    ll cursum = 0;
    ll res =0;
    for (int i = 0; i < n; i++){
        ll x;
        cin >> x;
        cursum+=x;
        if (cursum == t) res++;
        if (prevsum.find(cursum - t) != prevsum.end()){
            res += prevsum[cursum - t];
        }
        prevsum[cursum]++;
    }    
    cout << res << endl;
    return 0;
}