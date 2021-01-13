#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1,0));
    if (a[0] == 0){
        for (int i = 1; i <= m; i++) dp[0][i] = 1;
    }
    else dp[0][a[0]] = 1;
    for (int i = 1; i < n; i++){
        if (a[i] == 0){
            for (int j = 1; j <= m; j++){
                for (int k : {j - 1,j,j + 1}){
                    if (k >=1 && k <= m) (dp[i][j] += dp[i - 1][k]) %= M;
                }
            }
        }
        else{
            for (int k : {a[i] - 1, a[i],a[i] + 1}){
                if (k >= 1 && k <= m) (dp[i][a[i]] += dp[i - 1][k]) %= M;
            }
        }
    }
    ll res = 0;
    for (int i = 1; i <= m; i++) (res+=dp[n - 1][i]) %= M;
    cout << res << endl;
    return 0;
}