#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};
int R,C;

bool bordersObs(int r, int c, vector<vi> obs){
    int cdr[] = {0,0,-1,-1};
    int cdc[] = {0,-1,0,-1};
    for(int i=0;i<4;i++){
        int nr = r + cdr[i]; int nc = c + cdc[i];
        if(nr<0||nr>=R||nc<0||nc>=C)continue;
        if(obs[nr][nc])return true;
    }
    return false;
}

int dirToNum(string d){
    if(d=="north")return 0;
    if(d=="west")return 1;
    if(d=="south") return 2;
    return 3;
}

int main(){
    int i,j,RR,CR;
    while(1){
        cin>>R>>C;
        if(!R&&!C)break;
        RR=R+1;
        CR=C+1;
        vector<vi> obs;
        int ob;
        for(i=0;i<R;i++){
            vi tA;
            for(j=0;j<C;j++){
                cin>>ob;
                tA.push_back(ob);
            }
            obs.push_back(tA);
        }
        vector<vi> grid;
        for(i=0;i<RR;i++){
            vi tA;
            for(j=0;j<CR;j++){
                if(bordersObs(i,j,obs)){
                    //cout << "r= " << i << "c= " << j << endl;
                    tA.push_back(0);  
                }
                else{
                    tA.push_back(1);
                }
            }
            grid.push_back(tA);
        }
        //0=north,1=west,2=south,3=east
        vi dist(RR*CR*4,INF);
        int a,b,c,d;
        string dir;
        cin>>a>>b>>c>>d>>dir;
        int source = a*CR+b;
        int target = c*CR+d;
        dist[source*4+dirToNum(dir)]=0;
        queue<int> q;
        q.push(source*4+dirToNum(dir));
        while(!q.empty()){
            int u = q.front(); q.pop();
            int myDir = u%4;
            int myDist = dist[u];
            u/=4;
            int myR = u/CR; int myC = u%CR;
            //cout << "myR = " << myR << " myC = " << myC << endl;
            //move
            for(i=1;i<4;i++){
                int nDist = myDist+1;
                int newR = myR + dr[myDir]*i;
                int newC = myC + dc[myDir]*i;
                if(newR>=RR-1||newR<=0||newC<=0||newC>=CR-1)break;
                if(!grid[newR][newC])break;
                int v = (newR*CR+newC)*4+myDir;
                if(nDist<dist[v]){
                    //cout<< "myR = " << myR << "myC = " << myC << "newR = " << newR << " newC = " << newC << " nDist = " << nDist << endl;
                    dist[v]=nDist;
                    q.push(v);
                }
            }
            //turn
            for(i=0;i<4;i++){
                if(i==myDir)continue;
                int v = u*4 + i;
                int nDist = myDist + (abs(i-myDir) == 2 ? 2 : 1);
                if(nDist<dist[v]){
                    dist[v]=nDist;
                    q.push(v);
                }
            }
        }
        int min = INF;
        for(i=target*4;i<target*4+4;i++){
            if(dist[i]<min){
                min=dist[i];
            }
        }
        if(min==INF)cout<<"-1"<<endl;
        else cout<<min<<endl;
    }
    return 0;
}
