#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y;
    
    printf("두 수를 입력받아서 더하는 문제를 완성하시오. : " );
    
    scanf("%d %d", &x, &y);
    
    printf("두 수의 합은 %d 입니다.\n", x+y);
    
    system("pause");
    return 0;
}
