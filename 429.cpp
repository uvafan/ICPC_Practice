#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

bool con(string a, string b){
	if(a.size()!=b.size())return false;
	int dif = 0;
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]){
			dif++;
			if(dif>1)return false;
		}
	}
	return true;
}

int main(){
	int N,i,j;
	cin>>N>>ws;
	while(N--){
		string line;
		vector<string> dict;
		map<string,int> sToI;
		vector<vi> adjList;
		while(getline(cin,line)){
			if(line=="*")break;
			dict.push_back(line);
			sToI[line] = dict.size()-1;
			adjList.push_back(vi(0,0));
		}
		for(i=0;i<dict.size();i++){
			for(j=i+1;j<dict.size();j++){
				if(con(dict[i],dict[j])){
					adjList[i].push_back(j);
					adjList[j].push_back(i);
				}
			}
		}
		while(getline(cin,line)){
			if(!line.size())break;	
			for(i=0;i<line.size();i++){
				if(line[i]==' ')break;
			}
			string a = line.substr(0,i);
			string b = line.substr(i+1,line.size()-(i+1));
			int s = sToI[a]; int t = sToI[b];
			vi dist(dict.size(),INF);
			dist[s]=0;
			queue<int> q;
			q.push(s);
			while(1){
				int u = q.front(); q.pop();
				if(u==t){break;}
				for(i=0;i<adjList[u].size();i++){
					int v = adjList[u][i];
					if(dist[v]==INF){
						dist[v] = dist[u] + 1;
						q.push(v);
					}
				}
			}
			cout<<a<<" "<<b<<" "<<dist[t]<<endl;
		}
		if(N)cout<<endl;
	}
    return 0;
}
