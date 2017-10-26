#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int main(){
    int i,j,k,e,S,ly,lm;
    char a,b,c,d;
    int coun = 0;
    while(1){
        cin>>S;
        if(!S)break;
        vector<vi> adjMatY(26,vi(26,INF));
        vector<vi> adjMatM(26,vi(26,INF));
        for(i=0;i<26;i++){
            adjMatY[i][i]=0;
            adjMatM[i][i]=0;
        }
        while(S--){
            cin>>a>>b>>c>>d>>e;
            int u = int(c)-65;
            int v = int(d)-65;
            //cout<<u<<endl;
            if(a=='Y'){
                adjMatY[u][v] = min(adjMatY[u][v],e);
                if(b=='B')
                    adjMatY[v][u] = min(adjMatY[v][u],e);
            }
            else{
                adjMatM[u][v] = min(adjMatM[u][v],e);
                if(b=='B')
                    adjMatM[v][u] = min(adjMatM[v][u],e);
            }
        }
        cin>>a>>b;
        ly = int(a)-65; lm = int(b)-65;
        for(k=0;k<26;k++)
            for(i=0;i<26;i++)
                for(j=0;j<26;j++){
                    adjMatY[i][j] = min(adjMatY[i][j],adjMatY[i][k]+adjMatY[k][j]);
                    adjMatM[i][j] = min(adjMatM[i][j],adjMatM[i][k]+adjMatM[k][j]);
                }
        int mi = INF;
        vi miV;
        for(i=0;i<26;i++){
            if(adjMatY[ly][i]+adjMatM[lm][i]<mi){
                mi = adjMatY[ly][i]+adjMatM[lm][i];
                miV.clear(); miV.push_back(i);
            }
            else if(adjMatY[ly][i]+adjMatM[lm][i]==mi) miV.push_back(i);
        }
        if(mi==INF)cout<<"You will never meet."<<endl;
        else {
            cout<<mi<<" ";
            for(i=0;i<miV.size();i++){
                if(i)cout<<" ";
                cout<<char(miV[i]+65);
            }
            cout<<endl;
        }
    }
    return 0;
}
