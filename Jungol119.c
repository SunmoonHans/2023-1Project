#include <stdio.h>
#include <time.h>

int main()
{
	int a=0;
	time_t now;
	struct tm tt;
	time(&now);
	tt = *localtime(&now);
	printf("%d ", a);
	a = tt.tm_year;
	printf("%d ", a);
	a += tt.tm_mon;
	a += tt.tm_mday;
	printf("%d %d %d\n", a, a, a);
	return 0;
}
