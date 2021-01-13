#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1,s2;
    cin >> s1 >> s2;
    vector<vector<ll>> dp(s1.size() + 1,vector<ll>(s2.size() + 1,1e9));
    dp[0][0] = 0;
    for (int i = 0; i <= s1.size(); i++){
        for (int j = 0; j <= s2.size(); j++){
            if (i) dp[i][j] = min(dp[i][j],dp[i-1][j] + 1);
            if (j) dp[i][j] = min(dp[i][j],dp[i][j - 1] + 1);
            if (i && j) dp[i][j] = min(dp[i][j],dp[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]));
        }
    }
    cout << dp[s1.size()][s2.size()];
    return 0;
}