#include <bits/stdc++.h>
#include <bits/stdtr1c++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
long long M = 1e9 + 7;
int main(){
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    ordered_multiset<ll> s;
    queue<ll> q;
    for (int i = 0; i < n; i++){
        ll m;
        cin >> m;
        if (q.size() == k){
            if (k % 2 == 0){
                cout << s.find_by_order(k / 2) << ' ';
            }
            else{
                cout << s.find_by_order(k / 2 - 1) << ' ';
            }
            ll x = q.front();
            s.erase(x);
            q.pop();
        }
        q.push(m);
        s.insert(m);
    }
    return 0;
}