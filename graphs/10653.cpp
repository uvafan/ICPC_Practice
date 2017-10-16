#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int R,C;
int dr[] = {-1,0,0,1};
int dc[] = {0,-1,1,0};
vector<vi> grid;
vector<vi> dist;

/*void dfs(int r, int c, int d){
    if(r<0||r>=R||c<0||c>=C||!grid[r][c])return;
    if(dist[r][c]<=d)return;
    dist[r][c]=d;
    for(int i=0;i<4;i++)dfs(r+dr[i],c+dc[i],d+1);
}*/

int main(){
    int i,j,rows;
    while(1){
        cin>>R>>C;
        if(!(R||C))break;
        grid.assign(R,vi(C,1));
        dist.assign(R,vi(C,INF));
        cin>>rows;
        int r, c, a;
        while(rows--){
            cin>>r;
            cin>>a;
            while(a--){
                cin>>c;
                grid[r][c]=0;
            }
        }
        cin>>r>>c;
        int tr,tc;
        cin>>tr>>tc;
        queue<ii> q;
        dist[r][c]=0;
        q.push(ii(r,c));
        while(!q.empty()){
            ii inf = q.front(); q.pop();
            r=inf.first,c=inf.second;
            if(r==tr&&c==tc)break;
            for(i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr<0||nr>=R||nc<0||nc>=C||!grid[nr][nc])continue;
                if(dist[nr][nc]==INF){
                    q.push(ii(nr,nc));
                    dist[nr][nc] = dist[r][c]+1;
                }
            }
        }
        cout<<dist[tr][tc]<<endl;
    }
    return 0;
}
