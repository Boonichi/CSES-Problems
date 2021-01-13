#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    ll maxsum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxsum+=a[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    for (int i = n - 1; i >= 0; i--){
        for (int j = i; j < n; j++){
            if (i == j) dp[i][j] = a[i];
            else dp[i][j] = max(a[i] - dp[i+1][j],a[j] - dp[i][j - 1]);
        }
    }    
    cout << (maxsum + dp[0][n - 1])/2 << endl;
    return 0;
}