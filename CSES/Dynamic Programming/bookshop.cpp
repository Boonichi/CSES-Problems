#include <bits/stdc++.h>

using namespace std;
int a[10000],b[10000],dp[1000000];
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    vector<vector<int>> dp(n + 1, vector<int>(c + 1,0));
    //vector<vector<long long>> dp(n + 1, vector<long long>(c + 1,0));
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= c; j++){
            dp[i][j] = dp[i - 1][j];
            if (j - a[i] >= 0){
                dp[i][j] = max(dp[i][j],dp[i - 1][j - a[i]] + b[i]);
                //cout << dp[i][j] << ' ' << i << ' ' << j << endl;
            }
        }
    }
    cout << dp[n][c] << endl;
    return 0;
}