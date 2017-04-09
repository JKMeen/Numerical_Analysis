#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define	EPS      1.E-4
#define	MAXITER  50
#define	A        -3.0
#define	B        3.0

//#define	Function(x, random) (2*pow(x,3.)-rand*pow(x,2.)+2*x+random)

double Function(double x, int random){
	return (2 * pow(x, 3.) - random*pow(x, 2.) + 2 * x + random);
}

void main()
{
	int it;
	int random, egg=0, homework=0;
	double a, b, x;   // ÃÊ±â ±¸°£
	double fa, fx;    // ¹æÁ¤½Ä
	double fjudge;    //

	srand((unsigned)time(NULL));
	random = rand() % 20+10;
	a = A;
	b = B;
	printf("[iter]    [a]      [b]             [x]           [f(x)]            [Item]\n\n");
	for (it = 0; it < MAXITER; it++){
		x = .5*(a + b);

		fa = Function(a, random);
		fx = Function(x, random);
		printf("[%3d] %f\t%f\t%f\t%f", it + 1, a, b, x, fx);

		fjudge = fa*fx;
		if (fjudge>0.0){
			a = x;
			printf("\t< »îÀº °è¶õ È¹µæ! >\n");
			egg++;
		}
		else if (fjudge<0.0){
			if (fabs(b - a) < EPS){
				printf("\t< ±³¼ö´ÔÀÇ ¸¶À½ È¹µæ! >\n");
				break;
			}
			else {
				b = x;
				printf("\t< °úÁ¦ È¹µæ! >\n");
				homework++;
			}
		}
		else{
			if (fa == 0.0){
				x = a;
				printf("\t[±³¼ö´ÔÀÇ »ç¶û È¹µæ!]\n");
			}
			break;
		}
	}
	if (it < MAXITER){
		printf("\n------------ °á°ú -------------\n");
		printf("    teration    : %d\n", it + 1);
		printf("       x        = %f\n", x);
		printf("      f(x)      = %f\n", Function(x, random));
		printf("      b-a       = %f\n", b - a);
		printf("    <°úÁ¦>      = %d°³\n", homework);
		printf("  <»îÀº °è¶õ>   = %d°³\n", egg);
		printf("<±³¼ö´ÔÀÇ »ç¶û> = ¿ÀÂ÷¸¦ Çã¿ëÇÒ ¼ö ¾ø´Â ¹ÌºÐ °ª\n\n");
	}
	else printf("\nError !!\n");
}
