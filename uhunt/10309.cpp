#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define pb push_back
#define INF 1e9

int N,i,j;
int ans,test;

int dr[] = {-1,0,0,0,1};
int dc[] = {0,-1,0,1,0};

vector<vi> flip(vector<vi> m, int r, int c){
    for(i=0;i<5;i++){
        int nr=r+dr[i]; int nc=c+dc[i];
        if(nr<0||nr>9||nc<0||nc>9)
            continue;
        m[nr][nc] = 1-m[nr][nc];
    }
    return m;
}

void next_row(vector<vi> lights, int r, int flipped){
    for(int c=0;c<10;c++){
        if(lights[r-1][c]){
            lights = flip(lights,r,c);
            flipped++;
        }
    }
    if(r<9){
        next_row(lights,r+1,flipped);
    }
    else{
        for(int c=0;c<10;c++){
            if(lights[r][c])
                return;
        }
        ans = min(flipped,ans);
    }
}

void first_row(vector<vi> lights, int c, int flipped){
    if(c>9){
        next_row(lights,1,flipped);
        return;
    }
    first_row(lights,c+1,flipped);
    lights = flip(lights,0,c);
    first_row(lights,c+1,flipped+1);
}

int main(){
    string name;
    while(cin>>name){
        test=0;
        if(name=="end")break;
        vector<vi> lights(10,vi(10,0));
        ans = INF;
        string line;
        for(i=0;i<10;i++){
            cin>>line;
            for(j=0;j<10;j++){
                if(line[j]!='#'){
                    lights[i][j]=1;
                }
            }
        }
        first_row(lights,0,0);
        if(ans==INF)
            cout<<name<<" "<<-1<<endl;
        else
            cout<<name<<" "<<ans<<endl;
    }
    return 0;
}
