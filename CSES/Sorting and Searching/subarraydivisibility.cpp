#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
ll division[2000000];
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll summ = 0;
    for (int i = 0; i < n; i++){
        ll x;
        cin >> x ;
        summ+=x;
        division[((summ % n) + n) % n]++;
    }
    ll res = 0;
    for (int i = 0; i < n; i++){
        if (division[i] > 1){
            res+=(division[i] * (division[i] - 1)) / 2;
        }
    }
    res+=division[0];
    cout << res << endl;
    return 0;
}