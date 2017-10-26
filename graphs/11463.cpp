#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int main(){
    int i,j,k,N,V,E,a,b,s,d;
    int count = 0;
    cin>>N;
    while(N--){
        count++;
        cin>>V>>E;
        vector<vi> adjMat(V,vi(V,INF));
        for(i=0;i<V;i++){
            adjMat[i][i]=0;
        }
        while(E--){
            cin>>a>>b;
            adjMat[a][b]=1;
            adjMat[b][a]=1;
        }
        cin>>s>>d;
        for(k=0;k<V;k++)
            for(i=0;i<V;i++)
                for(j=0;j<V;j++)
                    adjMat[i][j] = min(adjMat[i][j],adjMat[i][k]+adjMat[k][j]);
        int ma = -INF;
        for(i=0;i<V;i++){
            ma = max(ma,adjMat[s][i]+adjMat[i][d]);
        }
        cout<<"Case "<<count<<": "<<ma<<endl;
    }
    return 0;
}
