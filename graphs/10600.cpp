#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

class UnionFind{
	private: vi p,rank;
	public:
			 UnionFind(int N){rank.assign(N,0);
				 p.assign(N,0);for(int i=0;i<N;i++)p[i]=i;}
			 int findSet(int i){return (p[i]==i) ? i : (p[i]=findSet(p[i]));}
			 bool isSameSet(int i,int j){ return findSet(i) == findSet(j); }
			 void unionSet(int i,int j){
				 if(!isSameSet(i,j)){
					 int x = findSet(i), y = findSet(j);
					 if (rank[x] > rank[y]) p[y]=x;
					 else{ 
						 p[x]=y; 
						 if(rank[x]==rank[y])rank[y]++;
					 }
				 }
			 }
};

int main(){
	int N,i,j,a,b,w;
	cin>>N;
	while(N--){
		int E,V;
		cin>>V>>E;
		vector<pair<int,ii> > edgeList;
		for(i=0;i<E;i++){
			cin>>a>>b>>w;
			edgeList.push_back(make_pair(w,ii(a-1,b-1)));
		}
		sort(edgeList.begin(),edgeList.end());
		UnionFind UF(V);
		int cost = 0;
		vi flags;
		for(i=0;i<edgeList.size();i++){
			pair<int,ii> front = edgeList[i];
			if(!UF.isSameSet(front.second.first,front.second.second)){
				flags.push_back(i);
				cost += front.first;
				UF.unionSet(front.second.first,front.second.second);
			}
		}
		int cost2 = INF;
		for(j=0;j<flags.size();j++){
			UnionFind myUF(V);
			int c = 0;
			int count = 0;
			for(i=0;i<edgeList.size();i++){
				if(i==flags[j])continue;
				pair<int,ii> front = edgeList[i];
				if(!myUF.isSameSet(front.second.first,front.second.second)){
					c += front.first;
					count++;
					myUF.unionSet(front.second.first,front.second.second);
				}
			}
			//cout<<count<<endl;
			if(count==V-1 && c<cost2){
				cost2=c;
			}
		}
		cout<<cost<<" "<<cost2<<endl;
	}
	return 0;
}
