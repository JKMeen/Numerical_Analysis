#include <stdio.h>
#include <math.h>

#define scanf scanf_s
double F(double);

void main()
{
	int	   N = 1000, i = 0; // 최대 탐색 횟수
	double X, X0;           // 근사해
	double A, B;            // 근의 존재 구간
	double FX, FA, FB;      // 함수
	double EPS = 0.0001;    // 허용 오차

	printf("왼쪽 초기값   >>> ");
	scanf("%lf", &A);

	printf("오른쪽 초기값 >>> ");
	scanf("%lf", &B);

	do
	{
		i++;
		FA = F(A);
		FB = F(B);
		X = (A*FB - B*FA) / (FB - FA);
		FX = F(X);
		if (FA * FX > 0)
		{
			X0 = A;
			A = X;
		}
		else if (FA * FX < 0)
		{
			X0 = B;
			B = X;
		}
		else if (FA * FX == 0)
		{
			if (FA == 0)
			{
				X = A;
				break;
			}
			else if (FB == 0)
			{
				X = B;
				break;
			}
			else if (FX == 0)
			{
				break;
			}
		}
	} while (fabs(X - X0) > EPS || i <= N);

	printf("\n<System> 몸의 균형 X : %lf\n\n", X);
	if (X < 0) printf("<System> 몸이 왼쪽으로 기울였습니다.\n");
	else if (X > 0) printf("<System> 몸이 오른쪽으로 기울였습니다.\n");
	else printf("<System> 몸이 완벽합니다.\n");
}

double F(double x)
{
	double Fx;
	/* F(x) = 1 * x^3 + 3 * x^2 + 3 * x + 1  */
	Fx = 1 * x * x * x + 3 * x * x + 3 * x + 1;
	return Fx;
}



