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
    ll maxsum  = 0;
    for (int i = 1; i <= n; i++) maxsum+=i;
    vector<vector<ll>> dp(n + 1,vector<ll>(maxsum + 1,0));
    dp[0][0] = 1;
    if (maxsum % 2 != 0) cout << 0 << endl;
    else{
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= maxsum / 2; j++){
            dp[i][j] = dp[i - 1][j];
            int c = j - i;
            if (c >= 0 && dp[i][c]){
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][c]) % M;
            }
        }
    }
    cout << dp[n - 1][maxsum / 2];
    }
    return 0;
}