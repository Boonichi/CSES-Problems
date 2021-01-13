#include <bits/stdc++.h>

using namespace std;
long long dp[10000000];
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) dp[i] = INT_MAX;
    dp[0] = 0;
    for (int i = 0; i <= n; i++){
        for (char c : to_string(i)){
            dp[i] = min(dp[i],dp[i - (c - '0')] + 1);
        }
    }    
    cout << dp[n];
    return 0;
}