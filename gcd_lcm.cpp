#include "gcd_lcm.h"

namespace dima {
	unsigned gcd(unsigned u, unsigned v) {
		unsigned shift;
		
		//gcd(u,v) for u = 0 or v = 0
		if (u == 0) return v;
		if (v == 0) return u;
		
		//divide u and v by 2^{K} with K maximal and set shift := K
		for (shift = 0; ((u | v) & 1) == 0; ++shift) {
			u >>= 1;
			v >>= 1;
		}
		
		//make u odd, there are no common powers of 2 remaining. This will terminate since u is nonzero.
		while ((u & 1) == 0) u >>= 1;
		
		do {
			//make v odd, there are no common powers of 2 remaining. This will terminate since v is nonzero.
			while ((v & 1) == 0) v >>= 1;
				
			//eventually swap u and v, because we need u <=v
			if (u > v) {
				unsigned t = v; v = u; u = t;
			}
			v -= u; // this is even
		} while (v != 0);
		
		//2^ {K}
		return u << shift;
	}
	
	unsigned lcm(unsigned u, unsigned v) {
		if (u == 0 || v == 0) return 0;
		return (u*v)/gcd(u,v);
	}
}