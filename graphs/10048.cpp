#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int main(){
    int C,S,Q,a,b,w,i,j;
	int ca = 0;
	while(1){
		cin>>C>>S>>Q;
		if(!(C||S||Q))break;
		if(ca)cout<<endl;
		ca++;
		cout<<"Case #"<<ca<<endl;
		vector<vii> adjList(C,vii(0,ii(0,0)));
		while(S--){
			cin>>a>>b>>w;
			adjList[a-1].push_back(ii(b-1,w));
			adjList[b-1].push_back(ii(a-1,w));
		}		
		int source,target;
		while(Q--){
			cin>>source>>target;
			source--;target--;
			vi dist(C,INF);
			dist[source]=0;
			queue<ii> q;
			q.push(ii(source,0));
			while(!q.empty()){
				ii inf = q.front(); q.pop();
				int u = inf.first; int curDist = inf.second;
				if(u==target)continue;
				for(i=0;i<adjList[u].size();i++){
					ii v = adjList[u][i];
					if(max(curDist,v.second) >= dist[v.first]){
						continue;
					}
					dist[v.first] = max(curDist,v.second);
					q.push(ii(v.first,max(curDist,v.second)));
				}
			}
			if(dist[target]==INF)cout<<"no path"<<endl;
			else{cout<<dist[target]<<endl;}
		}
	}
	return 0;
}
