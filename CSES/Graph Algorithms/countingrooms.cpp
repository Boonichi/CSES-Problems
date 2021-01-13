#include <bits/stdc++.h>

using namespace std;
int adjx[4] = {0,0,1,-1};
int adjy[4] = {1,-1,0,0};
int n,m;
char a[1001][1001];
int check[1001][1001];
void bfs(int s, int t){
    queue<pair<int,int>> q;
    q.push({s,t});
    check[s][t] = 1;
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++){
            int dx = x + adjx[i];
            int dy = y + adjy[i];
            if (a[dx][dy] == '.' && check[dx][dy] == 0){
                check[dx][dy] = 1;
                q.push({dx,dy});
            }
        }
    }
}
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            check[i][j] = 0;
        }
    int res = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (a[i][j] == '.' && check[i][j] == 0){
                res++;
                bfs(i,j);
            }
        }
    }
    cout << res;
    return 0;
}