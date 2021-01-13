#include <bits/stdc++.h>

using namespace std;
long long a[1000];
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    long long res = 10e17;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < (1 << n); i++){
        long long sum1 = 0, sum2 = 0;
        for (int j = 0; j < n; j++){
            if (i & (1 << j)) sum1+=a[j];
            else sum2+=a[j];
        }
        res = min(res,abs(sum1 - sum2));
    }    
    cout << res << endl;
    return 0;
}