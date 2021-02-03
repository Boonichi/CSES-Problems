#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll x; int n;
    cin >> x >> n;
    set<ll> s;
    s.insert(0);
    s.insert(x);
    multiset<ll> ms;
    ms.insert(x);
    while (n--){
        ll x;
        cin >> x;
        auto it1 = s.lower_bound(x);
        auto it2 = it1;
        it2--;
        ms.erase(ms.find(*it1 - *it2));
        ms.insert(x - *it2);
        ms.insert(*it1 - x);
        cout << *--ms.end() << endl;
        s.insert(x);
    }
    return 0;
}