#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, arr[10000], most = 0;
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++) {

        int ai = 0, a = 0, big = 0, icol = 0;
        for (int m = 0; m < 3; m++) {
            scanf("%d", &arr[m]);
        }
        for (int j = 0; j < 3; j++) {
            for (int k = j + 1; k < 3; k++) {
                if (arr[j] == arr[k]) {
                    a++;
                    icol = arr[j];
                }
                if (arr[j] >= arr[k]) {
                    big = arr[j];
                }
            }
        }
        if (a == 0) {
            ai = 100 * big;
        }
        else if (a == 3) {

            ai = 10000 + icol * 1000;
        }
        else {
            ai = 100 * icol + 1000;
        }
        if (ai >= most) {
            most = ai;
        }
    }
    printf("%d", most);
    system("pause");
    return 0;
}
