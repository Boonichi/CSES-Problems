#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
int n,m;
int a[1000000];
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    multiset<int,greater<int>> s;
    for (int i = 0; i < n; i++) s.insert(a[i]);
    for (int i = 0; i < m; i++){
        int x;
        cin >> x;
        auto t = s.lower_bound(x);
        if (t == s.end()) cout << -1 << endl;
        else{
            cout << *t << endl;
            s.erase(t);
        }
    }
    return 0;
}