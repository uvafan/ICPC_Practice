#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define repr(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define d(arg) do {cerr << #arg << ": "; cerr << arg; cerr << endl;} while(0)
#define pb push_back
#define INF (int)1e9
#define EPS 1e-9
#define MAX_V 331

//city c and day d -> 1+11*c+d

int mf,f,s,t,mid;
vi p;
int cost[MAX_V][MAX_V];
int ores[MAX_V][MAX_V];
int res[MAX_V][MAX_V];

void augment(int v, int minEdge){
    if(v==s){f=minEdge;return;}
    else if(p[v]!=-1){
        augment(p[v],min(minEdge,res[p[v]][v]));
        res[p[v]][v]-=f;res[v][p[v]]+=f;
    }
}

void calcmf(){
    mf=0;
    while(1){
        f=0;
        vi dist(MAX_V,INF); dist[s]=0; queue<int> q; q.push(s);
        p.assign(MAX_V,-1);
        while(!q.empty()){
            int u=q.front();q.pop();
            if(u==t)break;
            int v;
            repr(v,0,MAX_V){
                if(res[u][v]&&dist[v]==INF&&mid>=cost[u][v])
                    dist[v]=dist[u]+1,q.push(v),p[v]=u;
            }
        }
        augment(t,INF);
        if(f==0)break;
        mf+=f;
    }
}

int main(){
    int N,i,j;
    cin>>N;
    int ca=0;
    while(N--){
        ca++;
        int C,D,F;
        cin>>C>>D>>F;
        int u,v,c,p,e;
        repr(i,0,MAX_V){
            repr(j,0,MAX_V){
                ores[i][j]=0;
                cost[i][j]=0;
            }
        }
        for(i=1;i<MAX_V;i++){
            if(i%11)
                ores[i][i+1]=INF;
        }
        repr(j,0,F){
            cin>>u>>v>>c>>p>>e;u--;v--;
            if(u==v)continue;
            int a=1+11*u+e;
            int b=1+11*v+e+1;
            ores[a][b]=c;
            cost[a][b]=p;
        }
        int expected=0;
        repr(j,0,C){
            cin>>i;
            expected+=i;
            ores[0][1+11*j]=i;
        }
        s=0;
        t=1+11*(C-1)+D;
        int lo=0;
        int hi=100000;
        while(lo<hi){
            mid=(lo+hi)/2;
            repr(i,0,MAX_V){
                repr(j,0,MAX_V){
                    res[i][j]=ores[i][j];
                }
            }
            calcmf();
            //d(mid);
            //d(mf);
            if(mf==expected){
                hi=mid;
            }
            else{
                lo=mid+1;
            }
        }
        if(lo==100000){
            repr(i,0,MAX_V){
                repr(j,0,MAX_V){
                    res[i][j]=ores[i][j];
                }
            }
            mid=lo;
            calcmf();
            if(mf==expected){
                cout<<"Case #"<<ca<<": "<<lo<<endl;
            }
            else{
                cout<<"Case #"<<ca<<": Impossible"<<endl;
            }
        }
        else{
            cout<<"Case #"<<ca<<": "<<lo<<endl;
        }
    }
    return 0;
}
