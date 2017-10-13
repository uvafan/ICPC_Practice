#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int main(){
	int E,N,T,i,j,a;
	cin>>E;
	vector<vi> adjList(E,vi(0,0));
	for(i=0;i<E;i++){
		cin>>N;
		while(N--){
            cin>>a;
			adjList[i].push_back(a);
		}
	}
	cin>>T;
	while(T--){
		vi booms(E,0);
		vi dist(E,INF);
		queue<int> q;
		cin>>a;
		q.push(a);
		dist[a]=0;
		while(!q.empty()){
			int u = q.front();q.pop();
			for(i=0;i<adjList[u].size();i++){
				int v = adjList[u][i];
				if(dist[v]==INF){
					booms[dist[u]+1]++;
					dist[v] = dist[u]+1;
					q.push(v);
				}
			}
		}
		int M = 0;
		int D = 0;
		for(i=1;i<E;i++){
			if(booms[i]>M){
				D=i;
				M=booms[i];
			}
		}
		if(!M)cout<<M<<endl;
		else cout<<M<<" "<<D<<endl;
	}
    return 0;
}
