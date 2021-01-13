#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) cout << i * i * (i * i - 1) / 2 - 4 * (i - 1) * (i - 2) << endl;
    return 0;
}