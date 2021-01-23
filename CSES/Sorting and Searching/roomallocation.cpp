#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
vector<pair<ll,ll>> a;
int main(){
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    multiset<pair<ll,ll>,ll> ms;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>,greater<ll>> heap;
    for (int i = 0; i < n; i++){
        ll x,y;
        cin >> x >> y;
        ms.insert({x,y},i);
        
    } 
    cout << ms.size() << endl;
    return 0;
}