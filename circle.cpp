//draw circle with Monte Carlo Simulation
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

double get_random_number(const double min, const double max) {
	double temp = (double)rand() / (double)RAND_MAX;

	temp = min + (max - min) * temp;

	return temp;
}

bool is_inside_circle(const double x, const double y) {
	const double x_c = 0.5;
	const double y_c = 0.5;
	const double r = 0.5;
	
	const double f = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;

	if (f > 0.0) return false;
	else return true;
}
int main(void) {
	FILE *f = fopen("circle.txt", "w");
	srand((unsigned  int)time(NULL));

	for (int i = 0; i < 100000; i++) {
		double x = get_random_number(0.0, 1.0);
		double y = get_random_number(0.0, 1.0);

		if (is_inside_circle(x, y) == true)
			fprintf(f, "%lf %lf\n", x, y);
	}
	fclose(f);
}
