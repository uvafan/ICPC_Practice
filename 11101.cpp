#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int dr[] = {-1,0,0,1};
int dc[] = {0,-1,1,0};

int main(){
    int p,i,j,r,c;
    while(1){
        cin>>p;
        if(!p)break;
        vii points;
        int R = -1;
        int C = -1;
        vii pointsa;
        vii pointsb;
        while(p--){
            cin>>c>>r;
            if(r>=R)R=r+1;
            if(c>=C)C=c+1;
            pointsa.push_back(ii(r,c));
        }
        cin>>p;
        while(p--){
            cin>>c>>r;
            if(r>=R)R=r+1;
            if(c>=C)C=c+1;
            pointsb.push_back(ii(r,c));
        }
        vi dist(R*C,INF);
        //cout << R << " " << C << endl;
        queue<int> q;
        for(i=0;i<pointsa.size();i++){
            ii coord = pointsa[i];
            dist[coord.first*C+coord.second]=0;
            q.push(coord.first*C+coord.second);
        }
        while(!q.empty()){
            int u = q.front(); q.pop();
            int myR = u/C; int myC = u%C;
            for(i=0;i<4;i++){
                int newR = myR+dr[i];
                int newC = myC+dc[i];
                if(newR<0||newR>=R||newC<0||newC>=C)continue;
                int v = newR*C + newC;
                if(dist[u]+1<dist[v]){
                    //cout << "u = " << u << " v = " << v << endl;
                    dist[v]=dist[u]+1;
                    //cout << dist[v] << endl;
                    q.push(v);
                }
            }
        }
        int min = INF;
        for(i=0;i<pointsb.size();i++){
            ii coord = pointsb[i];
            if(dist[coord.first*C+coord.second]<min)
                min = dist[coord.first*C+coord.second];
        }
        cout<<min<<endl;
    }   
    return 0;
}
