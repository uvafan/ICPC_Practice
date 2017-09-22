#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int N;
vector<vi> grid;
int dr[] = {-1,0,0,1};
int dc[] = {0,-1,1,0};

void floodfill(int r, int c){
    if(r<0 || r>=N || c<0 || c>=N || grid[r][c] == -2 || grid[r][c] == 1) return;
    grid[r][c] = 1;
    for(int i=0;i<4;i++)floodfill(r+dr[i],c+dc[i]);
}

int main(){
    int k,i,j;
    string line;
    cin >> k;
    for(int ca=1;ca<=k;ca++){
        grid.clear();
        cin >> N;
        for(i=0;i<N;i++){
            cin >> line;
            vi toAdd;
            for(j=0;j<N;j++){
                if(line[j]=='x')
                    toAdd.push_back(0);
                else if(line[j]=='@')
                    toAdd.push_back(-1);
                else
                    toAdd.push_back(-2);
            }
            grid.push_back(toAdd);
        }
        int regions = 0;
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                if(grid[i][j]==0){
                    floodfill(i,j);
                    regions++;
                }
            }
        }
        cout << "Case " << ca << ": " << regions << endl;
    }
    return 0;
}
