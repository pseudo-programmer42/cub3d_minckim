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
	clock_t	t0;
	clock_t	t1;

	a = vec_new(3, 4, 5);
	b = vec_new(9, 12, 15);

	t_mat	m1 = {13, 12, 12, 64, 12, 55, 11, 75, 23};
	t_mat	m2 = {33, 51, 43, 11, 65, 21, 45, 42, 83};
	t0 = clock();
	for (long long i = 0; i < 1000000 ; i++)
	{
		vec_add(&a, &a);
		vec_add(&a, &a);
		vec_add(&a, &a);
		vec_add(&a, &a);
		vec_add(&a, &a);
		vec_add(&a, &a);
		vec_add(&a, &a);
		vec_add(&a, &a);
		mat_vec(&m1, &a);
		mat_vec(&m1, &a);
		mat_vec(&m1, &a);
	}
	t1 = clock();
	printf("time: %.6f s\n", (double)(t1-t0) / CLOCKS_PER_SEC);

	t0 = clock();
	for (long long i = 0; i < 1000000 ; i++)
	{
		vec_add(&a, &a);
		vec_add(&a, &a);
		vec_add(&a, &a);
		vec_add(&a, &a);
		vec_add(&a, &a);
		vec_add(&a, &a);
		mat_vec(&m1, &a);
		mat_vec(&m1, &a);
		mat_vec(&m1, &a);
		mat_vec(&m1, &a);
	}
	t1 = clock();
	printf("time: %.6f s\n", (double)(t1-t0) / CLOCKS_PER_SEC);

}