#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

double get_random_number(const double min, const double max) {
	double temp = (double)rand() / (double)RAND_MAX;

	temp = min + (max - min) * temp;

	return temp;
}

bool is_inside_ellipse(const double x, const double y) {
	const double a = 0.1;
	const double b = 0.3;
	const double r = 0.4;

	const double f = b*b*x*x + a*a*y*y - a*a*b*b;

	if (f > 0.0) return false;
	else return true;
}
int main(void) {
	FILE *f = fopen("ellipse.txt", "w");
	srand((unsigned  int)time(NULL));

	for (int i = 0; i < 1000000; i++) {
		double x = get_random_number(-1.0, 1.0);
		double y = get_random_number(-1.0, 1.0);

		if (is_inside_ellipse(x, y) == true)
			fprintf(f, "%lf %lf\n", x, y);
	}
	fclose(f);
}