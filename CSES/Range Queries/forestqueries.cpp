#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
int main(){
    //freopen("input.inp","r",stdin);
    //freeopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> value(n + 1, vector<int>(n + 1));
    for (int i = 1 ;i <= n; i++){
        for (int j = 1; j <= n; j++){
            char c;
            cin >> c;
            if (c == '*') value[i][j] = 1;
            else value[i][j] = 0;
        }
    }    
    vector<vector<int>> dp(n + 1, vector<int>(n + 1,0));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            dp[i][j] += dp[i - 1][j];
            dp[i][j] += dp[i][j - 1];
            dp[i][j] -= dp[i -1][j - 1];
            dp[i][j]+=value[i][j];
        }
    }
    while (m--){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1- 1] << endl;
    }
    return 0;
}