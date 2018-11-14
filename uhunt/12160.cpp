#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int main(){
    int L,U,R,a,b,i,j;
    int count = 0;
    while(1){
        count++;
        cin>>L>>U>>R;
        if(!R)break;
        vi dist(10000,INF);
        vi buttons;
        for(i=0;i<R;i++){
            cin>>a;
            buttons.push_back(a);
        }
        dist[L]=0;
        queue<int> q;
        q.push(L);
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(i=0;i<R;i++){
                int v = (buttons[i]+u)%10000;
                if(dist[u]+1<dist[v]){
                    dist[v] = dist[u]+1;
                    q.push(v);
                }
            }
        }
        if(dist[U]==INF) cout<<"Case "<<count<<": Permanently Locked"<<endl;
        else cout<<"Case "<<count<<": "<<dist[U]<<endl;
    }
    return 0;
}
