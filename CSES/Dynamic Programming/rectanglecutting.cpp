#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin >> a >> b;
    vector<vector<ll>>dp(a + 1, vector<ll>(b + 1,0));
    for (int i = 1; i <= a; i++){
        for (int j = 1; j <= b; j++){
            if (i == j) dp[i][j] = 0;
            else dp[i][j] = INT_MAX;
            for (int k = 1; k < i; k++){
                dp[i][j] = min(dp[i][j],dp[k][j] + dp[i - k][j] + 1);
            }
            for (int k = 1; k < j; k++){
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[i][j - k] + 1);
            }
        }
    }    
    cout << dp[a][b] << endl;
    return 0;
}