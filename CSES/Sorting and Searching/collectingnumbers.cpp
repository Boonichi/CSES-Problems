#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
int b[1000000];
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        b[x] = i;
    }
    int res = 1;
    for (int i = 2; i <= n; i++){
        if (b[i] < b[i - 1]) res++;
    }
    cout << res << endl;
    return 0;
}