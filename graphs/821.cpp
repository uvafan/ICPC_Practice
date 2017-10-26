#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int main(){
    int a,b,i,j,k;
    int coun = 0;
    while(1){
        coun++;
        cin>>a>>b;
        if(!a&&!b)break;
        vector<vi> adjMat(100,vi(100,INF));
        for(i=0;i<100;i++){
            adjMat[i][i]=0;
        }
        while(a&&b){
            adjMat[a-1][b-1] = 1;
            cin>>a>>b;
        }
        for(k=0;k<100;k++)
            for(i=0;i<100;i++)
                for(j=0;j<100;j++)
                    adjMat[i][j] = min(adjMat[i][j],adjMat[i][k]+adjMat[k][j]);
        int sum = 0;
        int count = 0;
        for(i=0;i<100;i++){
            for(j=0;j<100;j++){
                if(i!=j&&adjMat[i][j]<INF){
                    sum+=adjMat[i][j];
                    count++;
                }
            }
        }
        double ans = double(sum)/count;
        cout<<"Case "<<coun<<": average length between pages = "<<fixed<<setprecision(3)<<ans<<" clicks"<<endl;
    }
    return 0;
}
