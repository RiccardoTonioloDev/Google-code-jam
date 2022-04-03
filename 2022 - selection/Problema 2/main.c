#include <stdio.h>
/*
3
300000 200000 300000 500000
300000 200000 500000 300000
300000 500000 300000 200000 possibile

1000000 1000000 0 0
0 1000000 1000000 1000000
999999 999999 999999 999999 impossibile

768763 148041 178147 984173
699508 515362 534729 714381
949704 625054 946212 951187 varie possibilità
*/
// cyan magenta yellow black

int isPossible(int colors[],int *limit){
    int sum = 0;
    for(int i=0;i<4;i++){
        sum+=colors[i];
    }
    return sum>=*limit?1:0;
}

void calculateColor(int colors[],int *limit){
    for(int i=0;i<4;i++){
        if(*limit-colors[i]<0 && *limit>0){
            printf(" %d", *limit);
            *limit = 0;
        }else if(*limit-colors[i]<0 && *limit<=0){
            printf(" 0");
        }else{
            *limit-=colors[i];
            printf(" %d",colors[i]);
        }
    }
}

int main(){
    int test_cases = 0;
    scanf("%d", &test_cases);
    int variousTestCases[test_cases*4];
    for(int i=0;i<test_cases;i++){
        int isPrimoCiclo = 1;
        for(int printer = 0;printer<3;printer++){
            for(int color= 0;color<4;color++){
                int verificaQColore = 0;
                scanf("%d",&verificaQColore);
                if(isPrimoCiclo == 1){
                    variousTestCases[i*4+color] = verificaQColore;
                }else{
                    if(verificaQColore<variousTestCases[i*4+color]){
                        variousTestCases[i*4+color] = verificaQColore;
                    }
                }
            }
            isPrimoCiclo = 0;
        }
    }
    for(int i=0;i<test_cases;i++){
        int limit = 1000000;
        printf("Case #%d:",i+1);
        if(isPossible(&variousTestCases[i*4],&limit)){
            calculateColor(&variousTestCases[i*4],&limit);
        }else{
            printf(" IMPOSSIBLE");
        }
        printf("\n");
    }
    return 0;
}

/*
3
300000 200000 300000 500000
300000 200000 500000 300000
300000 500000 300000 200000
1000000 1000000 0 0
0 1000000 1000000 1000000
999999 999999 999999 999999
768763 148041 178147 984173
699508 515362 534729 714381
949704 625054 946212 951187

*/