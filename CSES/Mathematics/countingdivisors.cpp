#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
vector<int> is_prime(2000000, 0);
int main(){
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i < 1000005; i++) {
        for (int j = i; j < 1000005; j += i){
            is_prime[j] ++;
            }
        }
    while (t--){
        int n;
        cin >> n;
        cout << is_prime[n] << endl;
    }
    return 0;
}