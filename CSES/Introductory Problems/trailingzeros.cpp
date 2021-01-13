#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    long long res = 0;
    long long i = 5;
    while (i <= n)
    {
        res+=n / i;
        i*=5;
    }
    cout << res << endl;
    return 0;
}