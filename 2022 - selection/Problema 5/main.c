#include <stdio.h>
#define FLOAT_TO_INT(x) ((x) >= 0 ? (long)((x) + 0.5) : (long)((x)-0.5))

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int num_of_vertix = 0;
        int K = 0;
        scanf("%d", &num_of_vertix);
        scanf("%d", &K);
        if (num_of_vertix > K) {
            int hashMap[num_of_vertix];
            for (int c = 0; c < num_of_vertix; c++) {
                hashMap[c] = 0;
            }
            int zapping_number = num_of_vertix / K + 1;
            // printf("\nzapping number: %d\n",zapping_number);
            int scorritore = 0;
            int counter_of_vertix = 0;
            long int sumOfAllGrades = 0;
            for (int c = 0; c <= K; c++) {
                // printf("Round #%d --- K: %d---\n",c,K);
                int current_vertix = 0;
                int current_grade_of_vertix = 0;
                scanf("%d", &current_vertix);
                scanf("%d", &current_grade_of_vertix);
                if (c == 0) {
                    scorritore = current_vertix;
                }
                if (hashMap[current_vertix] == 0) {
                    // printf("\nconta vertici incrementato => %d\n",counter_of_vertix);
                    counter_of_vertix++;
                    sumOfAllGrades += current_grade_of_vertix;
                }
                hashMap[current_vertix] = current_grade_of_vertix;
                if (c == K) {
                    // Final calculations;
                    // printf("Sum of all grades: %d\n",sumOfAllGrades);
                    // printf("Sum of all grades: %d'\'",sumOfAllGrades);
                    double refinedSum = (double)sumOfAllGrades / counter_of_vertix;
                    // printf("%d = %d\n",counter_of_vertix,sumOfAllGrades);
                    // printf("Sum of all grades: %d*",sumOfAllGrades);
                    refinedSum *= num_of_vertix;
                    // printf("%d = %d\n",num_of_vertix,sumOfAllGrades);
                    // printf("Sum of all grades: %d'\'2 = ",sumOfAllGrades);
                    refinedSum /= 2;
                    // printf("%d",sumOfAllGrades);
                    // unsigned long long int sumOfAllGrades_casted = (unsigned long long int)sumOfAllGrades;
                    printf("E %ld\n", FLOAT_TO_INT(refinedSum));
                    fflush(stdout);
                } else {
                    // Calculate response;
                    scorritore += zapping_number;
                    scorritore = scorritore % num_of_vertix;
                    if (scorritore == 0) {
                        scorritore = num_of_vertix;
                    }
                    if (c % 2 == 0) {
                        printf("T %d\n", scorritore);
                        fflush(stdout);
                    } else {
                        printf("W\n");
                        fflush(stdout);
                    }
                }
            }
        } else {
            long int sum = 0;
            for (int c = 0; c < num_of_vertix; c++) {
                int current_vertix = 0;
                int current_grade_of_vertix = 0;
                scanf("%d", &current_vertix);
                scanf("%d", &current_grade_of_vertix);
                sum += current_grade_of_vertix;
                if ((current_vertix + 1) % num_of_vertix == 0) {
                    current_vertix = num_of_vertix;
                } else {
                    current_vertix = (current_vertix + 1) % num_of_vertix;
                }
                if (c != num_of_vertix - 1) {
                    printf("T %d\n", current_vertix);
                    fflush(stdout);
                }
            }
            printf("E %ld\n", sum / 2);
        }
    }

    return 0;
}