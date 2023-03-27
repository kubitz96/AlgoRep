int sumDigit(int n)
{
	if (n % 10 == n) return n;
	return n%10 +  sumDigit(n/10);
}


int digitalRoot(int n)
{
	int x = sumDigit(n);
	
	if (x<10) return x;
	return digitalRoot(x);
}

