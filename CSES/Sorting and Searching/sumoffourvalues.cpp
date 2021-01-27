#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
vector<pair<ll,ll>> a;
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll t;
    cin >> n >> t;
    for (int i = 0; i < n; i++){
        ll x;
        cin >> x;
        a.push_back({x,i});
    }
    int k;
    sort(a.begin(),a.end());
    for (int i = 0; i < n - 3; i++){
        for (int j = i + 1; j < n - 2; j++){
            int low = j + 1, high = n - 1;
            while (low < high){
                if (a[i].first + a[j].first + a[low].first + a[high].first == t){
                cout << a[i].second + 1 << ' ' << a[j].second + 1 << ' ' << a[low].second + 1 << ' ' << a[high].second + 1;
                return 0;
                }
                else if (a[i].first + a[j].first + a[low].first + a[high].first > t) high--;
                else low++;
            }
        }
    } 
    cout << "IMPOSSIBLE";
    return 0;
}