#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int main(){
    int N;
    cin>>N;
    string line;
    getline(cin,line);
    getline(cin,line);

    while(N--){
        vi exists(26,0);
        vi weight(26,0);
        vector<vi> adjList(26,vi(0,0));
        vi indegree(26,0);
        vi dist(26,0);
        while(getline(cin,line)){
            if(line.empty())
                break;
            istringstream iss(line);
            char a;
            int w;
            string neighbors = "";
            iss>>a;
            iss >> w;
            int vNum = int(a) - int('A');
            exists[vNum] = 1;
            weight[vNum] = w;
            if(iss>>neighbors){
                for(int i=0;i<neighbors.size();i++){
                    int uNum = int(neighbors[i]) - int('A');
                    adjList[uNum].push_back(vNum);
                    indegree[vNum]++;
                }
            }
        }
        queue<int> q;
        for(int i=0;i<26;i++){
            if(exists[i]&&!indegree[i]){
                dist[i] = weight[i];
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int j=0;j<adjList[u].size();j++){
                int v = adjList[u][j];
                indegree[v]--;
                if(!indegree[v])
                    q.push(v);
                if(dist[u]+weight[v]>dist[v]){
                    dist[v] = dist[u]+weight[v];
                }
            }
        }
        int ret = -1;
        for(int i=0;i<26;i++){
            ret = max(ret,dist[i]);
        }
        cout<<ret<<endl;
        if(N)
            cout<<endl;
    }
    return 0;
}
