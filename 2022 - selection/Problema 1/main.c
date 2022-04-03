#include <stdio.h>

void printSeparator(int isFirstPrint, int columns, int lastLine) {
    int i = 0;
    if (isFirstPrint) {
        printf("..+");
        i = 1;
    }else{
        printf("+");
    }
    for (; i < columns; i++) {
        printf("-+");
    }
    if(lastLine==0){
        printf("\n");
    }
}

void printRow(int isFirstPrint, int columns) {
    int i = 0;
    if (isFirstPrint) {
        printf("..|");
        i = 1;
    }else{
        printf("|");
    }
    for (; i < columns; i++) {
        printf(".|");
    }
    printf("\n");
}

int main() {
    int test_cases = 0;
    scanf("%d", &test_cases);
    for (int i = 0; i < test_cases; i++) {
        int rows = 0;
        int columns = 0;
        scanf("%d", &rows);
        scanf("%d", &columns);
        printf("Case #%d:\n",i+1);
        printSeparator(1,columns,0);
        printRow(1,columns);
        for (int r = 1; r<rows; r++) {
            printSeparator(0,columns,0);
            printRow(0,columns);
        }
        int lastLine = 0;
        if(i==test_cases-1){
            lastLine = 1;
        }
        printSeparator(0,columns,lastLine);
    }

    return 0;
}