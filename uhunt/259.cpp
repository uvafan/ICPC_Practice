#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int MAX_V=38;
int res[38][38], mf, f, s, t;
vi p;

void augment(int v, int minEdge){
    if (v==s) { f = minEdge; return; }
    else if (p[v] != -1) { augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f; res[v][p[v]] += f; } 
}

int main(){
    mf = 0;
    s=0;
    t=37;
    string line;
    while(getline(cin,line)){
        int numTotal=0;
        mf=0;
        for(int i=0;i<MAX_V;i++){
            for(int j=0;j<MAX_V;j++){
                res[i][j]=0;
                if(i<37&&i>26&&j==37)
                    res[i][j]=1;
            }
        }
        int app = int(line[0])-'A'+1;
        int num = int(line[1])-'0';
        numTotal+=num;
        res[0][app]=num;
        for(int i = 3; i < line.size(); i++){
            res[app][27+int(line[i]-'0')]=1;
        }
        while(getline(cin,line)){
            if(line.empty())
                break;
            int app = int(line[0])-'A'+1;
            int num = int(line[1])-'0';
            numTotal+=num;
            res[0][app]=num;
            for(int i = 3; i < line.size(); i++){
                res[app][27+int(line[i]-'0')]=1;
            }
        }
        while(1){
            f=0;
            vi dist(MAX_V,INF); dist[s] = 0; queue<int> q; q.push(s);
            p.assign(MAX_V, -1);
            while(!q.empty()){
                int u = q.front(); q.pop();
                if (u==t) break;
                for(int v=0;v<MAX_V;v++)
                    if(res[u][v]>0 && dist[v]==INF)
                        dist[v] = dist[u]+1, q.push(v), p[v]=u;
            }
            augment(t,INF);
            if(f==0) break;
            mf+=f;
        }
        if(mf==numTotal){
            for(int i=27;i<37;i++){
                bool found=false;
                for(int j=1;j<27;j++){
                    if(res[i][j]){
                        found=true;
                        cout<<char(j+'A'-1);    
                        break;
                    }    
                }
                if(!found)
                    cout<<"_";
            }
            cout<<endl;
        }
        else
            cout<<"!"<<endl;
    }
    return 0;
}
