#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int dr[] = {-1,0,0,1};
int dc[] = {0,-1,1,0};

int main(){
    int N,i,j,R,C,a,b;
    cin>>N;
    while(N--){
        scanf("%d %d",&R,&C);
        vector<vi> grid(R,vi(C,0));;
        for(i=0;i<R;i++){
            for(j=0;j<C;j++){
                scanf("%d",&grid[i][j]);
            }
        }
        vector<vi> dist(R,vi(C,INF));
        dist[0][0] = grid[0][0];
        priority_queue<iii,vector<iii>,greater<iii> > q;
        q.push(iii(grid[0][0],ii(0,0)));
        while(!q.empty()){
            iii u = q.top(); q.pop();
            int r = u.second.first; int c = u.second.second; int d = u.first;
            if(d>dist[r][c])continue;
            if(r==R-1&&C==C-1)break;
            for(i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr<0||nr>=R||nc<0||nc>=C||dist[nr][nc]<=d+grid[nr][nc])continue;
                dist[nr][nc] = d + grid[nr][nc];
                q.push(iii(dist[nr][nc],ii(nr,nc)));    
            }
        }
        cout<<dist[R-1][C-1]<<endl;
    }
    return 0;
}
