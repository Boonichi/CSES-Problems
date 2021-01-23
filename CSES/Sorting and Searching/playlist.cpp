#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
ll a[1000000];
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    map<ll,ll> m;
    ll res = 0;
    for (ll i = 0,j = 0; i < n; i++){
        //cout << a[i] << ' ' << m[a[i]] << ' ' << j << endl;
        j = max(m[a[i]],j);
        res = max(res,i - j + 1);
        m[a[i]] = i + 1;
    }
    cout << res;
    return 0;
}