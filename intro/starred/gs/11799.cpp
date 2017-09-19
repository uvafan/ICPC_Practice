#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
int main(){
    int N, k, s;
    cin >> N;
    for(int i = 1; i<=N;i++){
        cin >> k; 
        int max = -1;
        while(k--){
            cin >> s;
            if(s>max)
                max = s;
        }
        printf("Case %d: %d\n",i,max);
    }
    return 0;
}
