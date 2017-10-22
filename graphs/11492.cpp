#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

vector<vector<vi> > adjList;
map<string,int> ltoI;
vector<string> langs;

int main(){
    int a,b,i,j,M;
    while(1){
        cin>>M;
        if(!M)break;
        vector<vector<string> > words;
        ltoI.clear();
        langs.clear();
        string la,lb,w;
        cin>>la>>lb;
        langs.push_back(la);
        langs.push_back(lb);
        ltoI[la]=0;
        ltoI[lb]=1;
        map<string,int>::iterator it;
        for(i=0;i<M;i++){
            cin>>la>>lb>>w;
            vector<string> vs;
            vs.push_back(la); vs.push_back(lb); vs.push_back(w); words.push_back(vs);
            it = ltoI.find(la);
            if(it==ltoI.end()){
                ltoI[la] = langs.size();
                langs.push_back(la);
            }
            it = ltoI.find(lb);
            if(it==ltoI.end()){
                ltoI[lb] = langs.size();
                langs.push_back(lb);
            }
        }
        adjList.assign(langs.size(), vector<vi>(0, vi(0,0)));
        for(i=0;i<M;i++){
            vector<string> vs = words[i];
            vi tA, tA2;
            int langa = ltoI[vs[0]];
            int langb = ltoI[vs[1]];
            tA.push_back(langb); tA2.push_back(langa);
            tA.push_back(vs[2].size()); tA2.push_back(vs[2].size());
            tA.push_back(int(vs[2][0])); tA2.push_back(int(vs[2][0]));
            adjList[langa].push_back(tA);
            adjList[langb].push_back(tA2);
        }
        vector<vi> dist(langs.size(),vi(128,INF));
        priority_queue<vi, vector<vi>, greater<vi> > pq;
        vi inf(3,0);
        pq.push(inf);
        dist[0][0]=0;
        int ans = INF;
        while(!pq.empty()){
            vi inf = pq.top(); pq.pop();
            int d = inf[0]; int u = inf[1];
            if(d>dist[u][inf[2]])continue;
            if(u==1){
                ans = d;
                break;
            }
            for(i=0;i<adjList[u].size();i++){
                vi edgeinf = adjList[u][i];
                if(edgeinf[2]==inf[2])continue;
                if(d+edgeinf[1]<dist[edgeinf[0]][edgeinf[2]]){
//                    cout << d+edgeinf[1]<<endl;
                    dist[edgeinf[0]][edgeinf[2]] = d+edgeinf[1];
                    vi tP;
                    tP.push_back(edgeinf[1]+d);
                    tP.push_back(edgeinf[0]);
                    tP.push_back(edgeinf[2]);
                    pq.push(tP);
                }
            }
        }
        if(ans<INF) cout<<ans<<endl;
        else cout<<"impossivel"<<endl;
    }
    return 0;
}
