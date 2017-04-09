#include <stdio.h>
#include <math.h>

#define scanf scanf_s
double F(double);

void main()
{
	int	   N = 1000, i = 0; // �ִ� Ž�� Ƚ��
	double X, X0;           // �ٻ���
	double A, B;            // ���� ���� ����
	double FX, FA, FB;      // �Լ�
	double EPS = 0.0001;    // ��� ����

	printf("���� �ʱⰪ   >>> ");
	scanf("%lf", &A);

	printf("������ �ʱⰪ >>> ");
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

	printf("\n<System> ���� ���� X : %lf\n\n", X);
	if (X < 0) printf("<System> ���� �������� ��￴���ϴ�.\n");
	else if (X > 0) printf("<System> ���� ���������� ��￴���ϴ�.\n");
	else printf("<System> ���� �Ϻ��մϴ�.\n");
}

double F(double x)
{
	double Fx;
	/* F(x) = 1 * x^3 + 3 * x^2 + 3 * x + 1  */
	Fx = 1 * x * x * x + 3 * x * x + 3 * x + 1;
	return Fx;
}



