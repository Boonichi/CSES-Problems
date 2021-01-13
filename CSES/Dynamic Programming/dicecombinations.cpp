#include <bits/stdc++.h>

using namespace std;
#define M 1000000007
long long dp[10000000];
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;  
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <=6 ;j++){
            if (i >= j) dp[i]=(dp[i] + dp[i - j]) % M;
        }
    }
    cout << dp[n];
    return 0;
}