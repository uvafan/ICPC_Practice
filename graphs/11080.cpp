#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int main(){
    int N,i,j,e,v;
    cin >> N;
    while(N--){
        cin >> v >> e;
        vector<vi> adjList (v,vi(0,0));
        int a,b;
        while(e--){
            cin >> a >> b;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        vi group(v,INF);
        queue<int> q;
        bool possible = true;
        int count = 0;
        vi indivcounts(2,0);
        vi visited;
        while(visited.size()<v && possible){
            indivcounts.assign(2,0);
            sort(visited.begin(),visited.end());
            for(i=0;i<visited.size();i++){
                if(visited[i]!=i)
                    break;
            }
            q.push(i);
            group[i] = 0;
            indivcounts[0]++;
            while(!q.empty()){
                int u = q.front();q.pop();
                visited.push_back(u);
                for(i=0;i<adjList[u].size();i++){
                    int nextu = adjList[u][i];
                    if(group[nextu]==INF){
                        q.push(nextu);
                        group[nextu] = 1 - group[u];
                        indivcounts[1-group[u]]++;
                    }
                    else if(group[nextu] == group[u]){
                        possible = false;
                        break;
                    }
                }
            }
            if(indivcounts[1])
                sort(indivcounts.begin(),indivcounts.end());
            count+=indivcounts[0];
        }
        if(!possible) cout << "-1" << endl;
        else{
            cout << count << endl;
        }
    }
    return 0;
}
