#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<vi> grid;
int dr[] = {-1,0,0,1};
int dc[] = {0,-1,1,0};
int M,N;

int floodfill(int r, int c, int region){
    if(r<0 || r>=M) return 0;
    if(c==-1) c=N-1;
    else if(c==N) c=0;
    if(grid[r][c]!=0) return 0;
    grid[r][c] = region;
    int ret = 1;
    for(int i=0;i<4;i++) ret+= floodfill(r+dr[i],c+dc[i],region);
    return ret;
}

int main(){
    int i,j;
    while(cin >> M >> N){
        grid.clear();
        string row;
        char guess;
        for(i=0;i<M;i++){
            vi toAdd;
            cin >> row;
            if(!i)guess=row[i];
            for(j=0;j<N;j++){
                if(row[j]==guess)
                    toAdd.push_back(-1);
                else
                    toAdd.push_back(0);
            }
            grid.push_back(toAdd);
        }
        int mx, my;
        cin >> mx >> my;
        if(grid[mx][my]==-1){
            //reverse the grid
            for(i=0;i<M;i++){
                for(j=0;j<N;j++){
                    if(grid[i][j]==0)
                        grid[i][j]=-1;
                    else
                        grid[i][j]=0;
                }
            }
        }
        int regions = 0;
        vi regionCounts (1,0);
        for(i=0;i<M;i++){
            for(j=0;j<N;j++){
                if(grid[i][j]==0){
                    regions++;
                    regionCounts.push_back(floodfill(i,j,regions));
                }
            }
        }
        int mRegion = grid[mx][my];
        int maxCount = 0;
        for(i=1;i<regionCounts.size();i++){
            if(regionCounts[i]>maxCount && mRegion != i)
                maxCount = regionCounts[i];
        }
        cout << maxCount << endl;
    }
    return 0;
}
