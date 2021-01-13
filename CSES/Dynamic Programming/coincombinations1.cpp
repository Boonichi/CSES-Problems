#include <bits/stdc++.h>

using namespace std;
#define M 1000000007
long long dp[10000000],a[1000];
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,c;
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[a[i]] = 1;
    }
    for (int i = 1; i <= c; i++){
        for (int j = 0; j < n; j++){
            if (i >= a[j] && dp[i - a[j]] != 0) dp[i] = (dp[i] + dp[i - a[j]]) % M;
            //cout << dp[i] << ' ' << i << endl;
        }
    }
    cout << dp[c] << endl;
    return 0;
}