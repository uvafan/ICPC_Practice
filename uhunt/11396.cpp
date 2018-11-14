#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int main(){
    int i,j,v;
    while(1){
        cin >> v;
        if(!v)break;
        vector<vi> adjList (v,vi(0,0));
        int a,b;
        while(1){
            cin >> a >> b;
            if(!(a||b))break;
            adjList[a-1].push_back(b-1);
            adjList[b-1].push_back(a-1);
        }
        vi group(v,INF);
        queue<int> q;
        bool possible = true;
        int count = 0;
        vi visited;
        while(visited.size()<v && possible){
            sort(visited.begin(),visited.end());
            for(i=0;i<visited.size();i++){
                if(visited[i]!=i)
                    break;
            }
            q.push(i);
            group[i] = 0;
            while(!q.empty()){
                int u = q.front();q.pop();
                visited.push_back(u);
                for(i=0;i<adjList[u].size();i++){
                    int nextu = adjList[u][i];
                    if(group[nextu]==INF){
                        q.push(nextu);
                        group[nextu] = 1 - group[u];
                    }
                    else if(group[nextu] == group[u]){
                        possible = false;
                        break;
                    }
                }
            }
        }
        if(!possible) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
