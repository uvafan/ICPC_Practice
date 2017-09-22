#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main(){
    int relations, tasks, i, j;
    while(1){
        cin >> tasks >> relations;
        if(!(tasks || relations)) break;
        vi indegree (tasks,0);
        vi toAdd;
        vector<vi> adjList;
        for(i=0;i<tasks;i++)adjList.push_back(toAdd);
        queue<int> q;
        for(i=0;i<relations;i++){
            int a, b;
            cin >> a >> b;
            adjList[a-1].push_back(b-1);
            indegree[b-1]++;
        }
        for(i=0;i<tasks;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vi ret;
        while(q.size()){
            int u = q.front(); q.pop();
            ret.push_back(u);
            for(i=0;i<adjList[u].size();i++){
                indegree[adjList[u][i]]--;
                if(!indegree[adjList[u][i]])
                    q.push(adjList[u][i]);
            }
        }
        cout << ret[0]+1;
        for(i=1;i<ret.size();i++)cout << " " << ret[i]+1;
        cout << endl;
    }
    return 0;
}
