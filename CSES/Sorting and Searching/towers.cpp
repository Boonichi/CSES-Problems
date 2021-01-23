#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
vector<pair<ll,int>> a;
bool cmp(const pair<ll,int> a, const pair<ll,int> b){
    if (a.first == b.first) return b.second < a.second;
    else return a.first > b.first;
}
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    multiset<ll> ms;
    cin >> n;
    for (int i = 0; i < n; i++){
        ll x;
        cin >> x;
        auto it = ms.upper_bound(x);
        if (it == ms.end()){
            ms.insert(x);
        }
        else{
            ms.erase(it);
            ms.insert(x);
        }
        cout << endl;
    }
    cout << ms.size() << endl;
    return 0;
}