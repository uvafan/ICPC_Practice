#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define pb push_back
#define INF 1000000000

int dp[100][100];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int R,C;

void dfs(vector<vi> grid,int r, int c){
    int best = 0;
    for(int i=0;i<4;i++){
        int nr = r+dx[i]; int nc = c+dy[i];
        if(r+dx[i]<0||r+dx[i]>=R||c+dy[i]<0||c+dy[i]>=C)
            continue;
        if(grid[nr][nc]<grid[r][c]){
            if(dp[nr][nc]<0)
                dfs(grid,nr,nc);
            best = max(best,1+dp[nr][nc]);
        }
    }
    dp[r][c]=best;
}

int main(){
    int N,l;
    string area;
    cin>>N;
    while(N--){
        cin>>area>>R>>C;
        vector<vi> grid(R,vi(C,0));
        for(int i=0;i<100;i++){
            for(int j=0;j<100;j++){
                dp[i][j]=-1;
            }
        }
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                cin>>l;
                grid[i][j]=l;
            }
        }
        int ret = 0;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                dfs(grid,i,j);
                ret = max(1+dp[i][j],ret);
            }
        }
        cout<<area<<": "<<ret<<endl;
    }
    return 0;
}
