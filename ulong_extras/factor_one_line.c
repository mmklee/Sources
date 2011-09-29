/*=============================================================================

    This file is part of FLINT.

    FLINT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    FLINT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FLINT; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA

=============================================================================*/
/******************************************************************************

    Copyright (C) 2008, 2009 William Hart
    Copyright (C) 2009 Thomas Boothby

******************************************************************************/

#include <mpir.h>
#include "flint.h"
#include "ulong_extras.h"

#define FLINT_ONE_LINE_MULTIPLIER 480

mp_limb_t n_factor_one_line(mp_limb_t n, ulong iters)
{
    mp_limb_t orig_n = n, in, square, sqrti, mod, factor, factoring = iters, iin;
    n *= FLINT_ONE_LINE_MULTIPLIER;

    iin = 0;
    in = n;
    while (factoring && (iin < in))
    {
        sqrti = n_sqrt(in);
        sqrti++;
        square = sqrti*sqrti;
        mod = square - in;
        if (n_is_square(mod)) 
        {
            factor = n_sqrt(mod);
            sqrti -= factor;
            if (orig_n >= sqrti) factor = n_gcd(orig_n, sqrti); 
            else factor = n_gcd(sqrti, orig_n);
            if (factor != 1UL) 
            { 
                return factor;
            }
        }     
        factoring--;    
        iin = in;
        in += n;
    }

    return 0;
}