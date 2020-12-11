#include<iostream>
#include<cmath>
float _1_fxnFunction(float, size_t);
int _2_modabFunction(int, int);
int _3_degree5NFunction(int);
int _4_maxDigN(int);
int _5_negElements(int[], size_t size = 100);
int findNumOfDigits(int);
int _6_head3N(int);
bool _7_equalNS(int, int);
int _8_countDivs(int);

int _10_revPrint(int);
int main()
{
	float x = 5;
	size_t n = 5;
	int a = 47;
	int b = 10;
	int N = 18;
	int n7 = 12345, s7 = 15;
	const size_t size = 100;
	int A[size];
	// 1. Find x^n / n! with any double x and any positive integer n.
	std::cout << _1_fxnFunction(x, n) << std::endl;

	// 2. Not using * or /, create function Mod(a, b) (a≥0, b > 0) calculating remainder of a/b
	std::cout << _2_modabFunction(a, b) << std::endl;

	// 3. 5 to the power of x is N, find x. If N is not a power of 5 - return -1.
	std::cout << _3_degree5NFunction(N) << std::endl;

	// 4. Find max digit in N, for example maxdig(27306) = 7.
	std::cout << _4_maxDigN(N) << std::endl;

	// 5. Given const int n = 100; float array[n]. Function prints negative elements.
	std::cout << _5_negElements(A);

	// 6. Example Head3(1592)=31592.
	std::cout << _6_head3N(N) << std::endl;

	// 7. Function checks if sum of digits of n is equal to s. For example equal(12345, 15) = true, equal(24, 7) = false.
	std::cout << _7_equalNS(n7, s7) << std::endl;

	// 8. Count all divisors of n (n>1) except 1 and n. For example divs(5)=0, divs(18)=4.
	std::cout << _8_countDivs(N) << std::endl;

	// 10. Prints digits reverse. For example RevPrint(12345) returns 54321.
	_10_revPrint(N);
	std::cout << std::endl;
	system("pause");
	return 0;
}
float _1_fxnFunction(float x, size_t n)
{
	if (n == 0) return 1;
	else return _1_fxnFunction(x, n - 1) * x / n;
}
int _2_modabFunction(int a, int b)
{
	if (a < b) return a;
	else return _2_modabFunction(a - b, b);
}
int _3_degree5NFunction(int N)
{
	int count = 0;
	if (N == 1) return 0;
	else if (N % 5 != 0) return -1;
	else
	{
		count = _3_degree5NFunction(N / 5);
		if (count == -1)
			return count;
		else return count + 1;
	}
}
int _4_maxDigN(int N)
{
	int temp;
	if (N < 10) return N;
	else
	{
		temp = _4_maxDigN(N / 10);
		if (temp > N % 10)
			return temp;
		else return N % 10;
	}
}
int _5_negElements(int A[], size_t size)
{
	int i;
	if (size == 0) return 0;
	else
		i = _5_negElements(A, size - 1);
	if (A[i] < 0)
	{
		std::cout << A[i] << " ";
		return i + 1;
	}
	else return i + 1;
}
int findNumOfDigits(int N)
{
	if (N == 0) return 1;
	else
	{
		N /= 10;
		return 1 + findNumOfDigits(N);
	}
}
int _6_head3N(int N)
{
	return 3 * pow(10, findNumOfDigits(N) - 1) + N;
}
bool _7_equalNS(int n, int s)
{
	if (n == 0 && s == 0) return true;
	else if (n != s && n <= 0 || s <= 0) return false;
	else
	{
		return _7_equalNS(n / 10, s - n % 10);
	}
}
int _8_countDivs(int N)
{
	int count = 0;
	int div = N / 2;
	if (div <= 2) return N;
	else
	{
		div -= 1;
		if (N % div == 0)
		{
			count += 1;
			return _8_countDivs(N);
		}
		else return _8_countDivs(N);
		return count;

	}
}
int _10_revPrint(int N)
{
	if (N == 0) return N;
	else
	{
		std::cout << N % 10;
		return _10_revPrint(N / 10);
	}
}
