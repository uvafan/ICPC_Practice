#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int k, a, b, c, co;
    co = 0;
    scanf("%d", &k);
    vector<int> v;
    while(k--){
        co++;
        scanf("%d %d %d", &a, &b, &c);
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(), v.end());
        printf("Case %d: %d\n", co, v[1]);
        v.clear();
    }
    return 0;
}
