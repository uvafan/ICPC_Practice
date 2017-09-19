#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
int main(){
    int N, B, H, W, lc, r, cost;
    while(cin >> N >> B >> H >> W){
        lc = -1;
        while(H--){
            scanf("%d\n",&cost);
            for(int i = 0; i<W;i++){
                scanf("%d",&r);
                if(r>=N && (cost*N<lc || lc==-1) && cost*N<=B){
                    lc = cost*N;
                }   
            }
        }
        if(lc==-1)
            printf("stay home\n");
        else
            printf("%d\n",lc);
    }
    return 0;
}
