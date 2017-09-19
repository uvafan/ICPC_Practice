#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int mm, k, mnum, sd, ed;
    float p, dp, cval, depr, ltp, ndepr;
    while(1){
        scanf("%d %f %f %d", &mm, &dp, &ltp, &k);
        cval = ltp + dp;
        if(mm<0)
            break;
        mnum = 0;
        k--;
        scanf("%d %f", &sd, &depr);
        p = ltp/mm;
        while(k--){
            scanf("%d %f", &ed, &ndepr);
            for(mnum; mnum < ed; mnum++){
                //printf("mnum = %d, depr = %f, cval = %f, ltp = %f\n",mnum,depr,cval,ltp);
                if(mnum > 0) ltp -= p;
                cval *= (1-depr);
                if(cval > ltp)
                    break;
            }
            if(cval > ltp)
                break;    
            sd = ed;
            depr = ndepr;
        }
        if(cval <= ltp){
            for(mnum; mnum <= mm; mnum++){
                //printf("mnum = %d, depr = %f, cval = %f, ltp = %f\n",mnum,depr,cval,ltp);
                ltp -= p;
                cval *= (1-depr);
                if(cval > ltp)
                    break;
            }
        }
        if(mnum==1)
            printf("1 month\n");
        else
            printf("%d months\n", mnum);
        if(k>0)
            while(k--)
                scanf("%d %f", &ed, &depr);
    }
    return 0;
}
