#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
vector<pair<ll,int>> a;
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        if (a.empty()){
            cout << 0 << ' ';
            a.push_back({x,i});
        }
        else{
            while (!a.empty() && x <= a.back().first){
                a.pop_back();
            }
            if (a.empty()) cout << 0 << ' ';
            else cout << a.back().second << ' ';
            a.push_back({x,i});
        }
    }
    return 0;
}