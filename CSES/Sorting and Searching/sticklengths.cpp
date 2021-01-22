#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
int n;
ll a[1000000];
ll summ(ll t){
    ll res = 0;
    for (int i = 0; i < n; i++){
        res+=abs(a[i] - t);
    }
    return res;
}
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n;i++) cin >> a[i];
    sort(a,a + n);
    if (n % 2 == 0){
        if (summ(a[n / 2] < summ(a[n / 2 + 1]))){
            cout << summ(a[n / 2]);
        }
        else cout << summ(a[n / 2 + 1]);
    }
    else cout << summ(a[n / 2 + 1]);
    return 0;
}