#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
int n;
ll t;
ll a[1000000];
bool check(ll mid){
    ll res = 0;
    for (int i = 0; i < n; i++){
         res+=min(mid / a[i],(ll) 1e9);
    }
    return (res>=t);
}
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;
    for (int i = 0; i < n; i++) cin >> a[i];    
    ll l = 0, r = 1e18,mid;
    while (l < r){
        mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }    
    cout << l << endl;
    return 0;
}