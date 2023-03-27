#include <stdio.h>

int mcd(int x, int y)
{
	if (y == 0) return x;
	return mcd(y, x%y);
}

int main()
{
	int x, y;
	
	scanf("%d%d",&x,&y);
	
	printf("%d\n", mcd(x,y));
}
