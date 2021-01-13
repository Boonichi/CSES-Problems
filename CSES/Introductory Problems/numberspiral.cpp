#include <bits/stdc++.h>

using namespace std;
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        long long a,b,c;
        cin >> a >> b;
        c = max(a,b);
        long long sl = (c - 1) * 2 + 1;
        long long ssh = (sl - 1) / 2 + 1;
        long long res; 
        if (ssh % 2 == 0) res = ssh / 2 * (sl + 1);
        else res = ssh / 2 * (sl + 1) + (sl + 1) / 2;
        if (c % 2 == 0){
            if (a >= b) cout << res - b + 1;
            else cout << res - sl + a;
        }
        else{
            if (a >= b) cout << res - sl + b;
            else cout << res - a + 1;
        }
        cout << endl;
    }    
    return 0;
}