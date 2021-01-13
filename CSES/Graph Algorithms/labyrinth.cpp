#include <bits/stdc++.h>

using namespace std;
int adjx[4] = {-1,1,0,0};
int adjy[4] = {0,0,1,-1};
int endx,endy,n,m,visited[1001][1001];
char a[1001][1001];
int bfs(){
    queue<pair<int,int>> q;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        visited[i][j] = -1;
        if (a[i][j] == 'A') {
            q.push({i,j});
            visited[i][j] = 0;
        }
        if (a[i][j] == 'B'){
            endx = i;
            endy = j;
        }
        }
    }
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++){
            int nextx = x + adjx[i];
            int nexty = y + adjy[i];
            if (a[nextx][nexty] != '#' && visited[nextx][nexty] == -1) {
                visited[nextx][nexty] = i;
                q.push({nextx,nexty});
                //cout << nextx << ' ' << nexty << endl;
            }
            if (nextx == endx && nexty == endy) return 1;        
    }
    }
    return 0;
}
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    if (bfs() == 1){
        cout << "YES" << endl;
        int i = endx, j = endy;
        string s;
        while (a[i][j] != 'A'){
            if (visited[i][j] == 0) s+='U';
            if (visited[i][j] == 1) s+='D';
            if (visited[i][j] == 2) s+='R';
            if (visited[i][j] == 3) s+='L';
            int x = i, y = j;
            i-=adjx[visited[x][y]]; j-=adjy[visited[x][y]];
        }
        cout << s.length() << endl;
        for (int i = s.length() - 1; i>=0; i--) cout <<s[i];
    }   
    else cout << "NO" << endl;
    return 0;
}