#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
vector<ll> a(100);
int main(){
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[a[i]] = 1;
    }
    for (int i = 0; i < n; i++){
        for (int j = x; j > 0; j-=a[i]){

        }
    }
}