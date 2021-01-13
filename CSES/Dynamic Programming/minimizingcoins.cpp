#include <bits/stdc++.h>

using namespace std;
long long dp[1000000],a[1000];
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,c;
    cin >> n >> c;
    for (int i = 1; i <= c; i++) dp[i] = INT_MAX;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        dp[a[i]] = 1;
    }
    for (int i = 1; i <= c; i++){
        for (int j = 1; j <= n; j++){
            if (i >= a[j] && dp[i - a[j]] != 0) dp[i] = min(dp[i],dp[i - a[j]] + 1);
        }
    }    
    if (dp[c] == INT_MAX) cout << -1;
    else cout << dp[c];
    return 0;
}