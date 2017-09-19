#include <stdio.h>
#include <stdlib.h>
int main(){
    int k, a, b;
    scanf("%d", &k);
    while(k--){
        scanf("%d %d", &a, &b);
        if(a<b)
            printf("<\n");
        else if(a>b)
            printf(">\n");
        else
            printf("=\n");
    }
    return 0;
}
