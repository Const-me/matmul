#include "stdafx.h"
#include "Common.h"

/**********************************
* Pseudo-random number generator *
**********************************/

static uint64_t mat_rng[ 2 ] = { 11ULL, 1181783497276652981ULL };

static inline uint64_t xorshift128plus( uint64_t s[ 2 ] )
{
	uint64_t x, y;
	x = s[ 0 ], y = s[ 1 ];
	s[ 0 ] = y;
	x ^= x << 23;
	s[ 1 ] = x ^ y ^ ( x >> 17 ) ^ ( y >> 26 );
	y += s[ 1 ];
	return y;
}

double mat_drand()
{
	return ( xorshift128plus( mat_rng ) >> 11 ) * ( 1.0 / 9007199254740992.0 );
}

int printResult( int algo, int size, double time, float centralCell )
{
	fprintf( stderr, "%i\t%i\t%g\t%g\n", algo, size, time, centralCell );
	return 0;
}