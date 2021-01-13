#include <bits/stdc++.h>

using namespace std;
char a[1000][1000];
long long dp[10000][10000];
long long M = 1e9+7;
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (a[i][j] == '*') dp[i][j] = 0;
            else{
                if (i > 0 && a[i - 1][j] != '*') (dp[i][j]+=dp[i - 1][j]) %= M;
                if (j > 0 && a[i][j - 1] != '*') (dp[i][j]+=dp[i][j - 1]) %= M;
                //cout << dp[i][j] << ' ' << i << ' ' << j << endl;
            }
        }
    }
    cout << dp[n - 1][n - 1] << endl;
    return 0;
}