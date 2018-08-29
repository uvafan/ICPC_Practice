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

double hypot(ii a, ii b){
	return sqrt((b.first-a.first)*(b.first-a.first)+(b.second-a.second)*(b.second-a.second));
}

int main(){
 	int N,i,j,a,b;
	cin>>N;
	while(N--){
		int S,P;
		cin>>S>>P;
		vector<pair<double,ii> > edgeList;
		vii points;
		while(P--){
			cin>>a>>b;
			points.push_back(ii(a,b));
		}
		//cout << "b" << endl;
		for(i=0;i<points.size();i++){
			for(j=i+1;j<points.size();j++){
				double w = hypot(points[i],points[j]);
				//cout << w << endl;
				edgeList.push_back(make_pair(w,ii(i,j)));
			}
		}
		//cout << "b1" << endl;
		sort(edgeList.begin(),edgeList.end());
		UnionFind UF(points.size());
		vector<double> weights;
		int numToRemove = S-1;
		for(i=0;i<edgeList.size();i++){
			pair<double,ii> front = edgeList[i];
			if(!UF.isSameSet(front.second.first,front.second.second)){
				weights.push_back(front.first);
			    if(weights.size() == points.size()-1-numToRemove)break;	
				UF.unionSet(front.second.first,front.second.second);
			}
		}
		//cout << "b2" << endl;
		sort(weights.begin(),weights.end());
		double cost = weights[weights.size()-1];
		cout<<fixed<<setprecision(2)<<cost<<endl;
	}
	return 0;
}
