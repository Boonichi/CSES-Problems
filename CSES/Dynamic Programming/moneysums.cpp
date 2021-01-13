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
    int maxx = 0;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxx+=a[i];
    }
    vector<vector<bool>> dp(n + 1,vector<bool>(maxx + 1,false));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= maxx; j++){
            int c = j - a[i - 1];
            dp[i][j] = dp[i - 1][j];
            if (c >=0 && dp[i - 1][c]) dp[i][j] = true;
        }
    }    
    set<int> res;
    for (int j = 1; j <= maxx; j++){
            if (dp[n][j]) res.emplace(j);
    }
    //sort(res.begin(),res.end());
    cout << res.size() << endl;
    for (int i : res) cout << i << ' ';
    return 0;
}