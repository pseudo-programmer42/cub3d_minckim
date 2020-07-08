#include "linear_algebra.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PI 3.14159265358979

int		main(void)
{
	t_vec	a;
	t_vec	b;
	time_t	time0;
	time_t	time1;
	clock_t	t0;
	clock_t	t1;

		a = vec_new(3, 4, 5);
		b = vec_new(9, 12, 15);
		vec_print(vec_add(a, b));
		vec_print(vec_sub(a, b));
		vec_print(vec_inv(a));
		vec_print(vec_cross(a, b));
		printf("%f\n", vec_dot(a, b));
		vec_print(vec_rot(vec_rot(vec_rot(a, PI/6, PI/2), -PI/6, 0), 0, -PI/2));

		t_mat	m1 = {13, 12, 12, 64, 12, 55, 11, 75, 23};
		t_mat	m2 = {33, 51, 43, 11, 65, 21, 45, 42, 83};

		mat_print(mat_add(m1, m2));
		t_mat	m3 = mat_inverse(m1);
		mat_print(mat_mul(m1, m3));
		mat_print(m1);
		mat_print(mat_transpose(m1));

	time0 = time(NULL);
	t0 = clock();
	for (long i = 0; i < 240000000 ; i++)
	{
		mat_inverse(m1);
		vec_mat(m1, a);


	}
	t1 = clock();


	time1 = time(NULL);
	printf("time: %.2f s\n", difftime(time1, time0));
	printf("time: %.6f s\n", (double)(t1-t0) / CLOCKS_PER_SEC);


}