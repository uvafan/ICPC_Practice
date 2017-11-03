#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

string printPath(int i, int j, vector<vi> p){
    string ret;
    if(i!=j&&p[i][j]!=j)ret += printPath(i,p[i][j],p);
    ret += to_string(j+1);
    return ret + " ";
}

int main(){
    int a,b,i,j,k,C;
    while(cin>>C){
        vector<vector<double> > adjMat(C,vector<double>(C,1.0));
        vector<vi> p(C,vi(C,0));
        for(i=0;i<C;i++){
            for(j=0;j<C;j++){
                p[i][j] = i;
                if(i==j)continue;
                double d;
                cin>>d;
                adjMat[i][j]=d;
            }
        }
        for(k=0;k<C;k++)
            for(i=0;i<C;i++)
                for(j=0;j<C;j++){
                if(k==j||i==k)continue;
                    if(adjMat[i][k]*adjMat[k][j]>adjMat[i][j]){
                        cout<<"i = "<<i<<" j = "<<j<<" k = "<<k<<" d = "<<adjMat[k][j]*adjMat[i][k]<<endl;
                        adjMat[i][j] = adjMat[i][k]*adjMat[k][j];
                        p[i][j] = p[k][j];
                    }  
                }
        bool found = false;
        for(i=0;i<C;i++){
            if(adjMat[i][i]>1.01){
                string path = printPath(i,p[i][i],p);
                if(path.size()<=2*C){
                    cout<<path<<i+1<<endl;
                    found = true;
                    break;
                }
            }
        }
        if(!found)cout<<"no arbitrage sequence exists"<<endl;
    }
    return 0;
}
