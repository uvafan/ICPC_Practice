#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int main(){
    int a,b,i,j,k,E,V;
    int coun = 0;
    while(1){
        coun++;
        cin>>V>>E;
        if(!E&&!V)break;
        vector<vi> adjMat(V,vi(V,INF));
        vector<string> peeps;
        map<string,int> m;
        for(i=0;i<V;i++){
            adjMat[i][i]=0;
        }
        string s1,s2;
        for(i=0;i<E;i++){
            cin>>s1>>s2;
            //cout<<peeps.size()<<endl;
            if(m.find(s1)==m.end()){
                m[s1] = peeps.size();
                peeps.push_back(s1);
            }
            if(m.find(s2)==m.end()){
                m[s2] = peeps.size();
                peeps.push_back(s2);
            }
            adjMat[m[s1]][m[s2]] = 1;
            adjMat[m[s2]][m[s1]] = 1;
        }
        for(k=0;k<V;k++)
            for(i=0;i<V;i++)
                for(j=0;j<V;j++)
                    adjMat[i][j] = min(adjMat[i][j],adjMat[i][k]+adjMat[k][j]);
        int ma = 0;
        for(i=0;i<V;i++){
            for(j=0;j<V;j++){
                ma = max(ma,adjMat[i][j]);
            }
        }
        cout<<"Network "<<coun<<": ";
        if(ma==INF)cout<<"DISCONNECTED";
        else cout<<ma;
        cout<<endl<<endl;
    }
    return 0;
}
