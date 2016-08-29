#include <stdafx.h>
#include "Common.h"

#include <Eigen/Dense>
using namespace Eigen;

void mat_gen_random_ublas( MatrixXf &m )
{
	ptrdiff_t i, j;
	for( i = 0; i < m.rows(); ++i )
		for( j = 0; j < m.cols(); ++j )
			m( i, j ) = (float)mat_drand();
}

int testEigen( int n )
{
	MatrixXf a( n, n ), b( n, n ), m( n, n );
	mat_gen_random_ublas( a );
	mat_gen_random_ublas( b );

	clock_t t = clock();
	m = a * b;

	printResult( 8, n, (double)( clock() - t ) / CLOCKS_PER_SEC, m( n / 2, n / 2 ) );

	return 0;
}