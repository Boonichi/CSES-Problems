#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000007
long long dac(long long a,long long n){
    if (n == 0) return 1;
    if (n == 1) return a;
    if (n % 2 == 0)
        return (dac(a,n / 2) * dac(a,n / 2)) % MOD;
    else return (dac(a,n / 2) * dac(a,n / 2) * a) % MOD;
}
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << dac(2,n) << endl;    
    return 0;
}