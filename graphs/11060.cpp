#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;


int main(){
    int drinks,i,j;
    int ca = 0;
    while(cin>>drinks){
        ca++;
        string s;
        vector<string> strs;
        unordered_map<string,int> stoint;
        vi indegree;
        vector<vi> adjList;
        vi toAdd;
        for(i=0;i<drinks;i++){
            cin>>s;
            strs.push_back(s);
            stoint[s] = i;
            indegree.push_back(0);
            adjList.push_back(toAdd);
        }
        int relations;
        cin>>relations;
        for(i=0;i<relations;i++){
            string a,b;
            cin >> a >> b;
            indegree[stoint[b]]++;
            adjList[stoint[a]].push_back(stoint[b]);
        }
        vi ret;
        priority_queue<int,vi,greater<int>> q;
        for(i=0;i<indegree.size();i++){
            if(!indegree[i])q.push(i);
        }
        while(q.size()){
            int drink = q.top(); q.pop();
            ret.push_back(drink);
            for(i=0;i<adjList[drink].size();i++){
                int next = adjList[drink][i];
                indegree[next]--;
                if(!indegree[next])
                    q.push(next);
            }
        }
        cout << "Case #" << ca << ": Dilbert should drink beverages in this order:";
        for(i=0;i<ret.size();i++) cout << " " << strs[ret[i]];
        cout << "." << endl << endl;
    }
    return 0;
}
