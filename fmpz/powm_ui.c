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

    Copyright (C) 2009 William Hart
    Copyright (C) 2011 Sebastian Pancratz

******************************************************************************/

#include <mpir.h>
#include <limits.h>
#include "flint.h"
#include "fmpz.h"
#include "ulong_extras.h"

void fmpz_powm_ui(fmpz_t f, const fmpz_t g, ulong e, const fmpz_t m)
{
    if (fmpz_sgn(m) <= 0)
    {
        printf("Exception (fmpz_powm_ui).  Modulus is less than 1.\n");
        abort();
    }

    if (fmpz_is_one(m))
    {
        fmpz_zero(f);
    }
    else if (e == 0)
    {
        fmpz_set_ui(f, 1);
    }
    else  /* e != 0, m > 0 */
    {
        fmpz g2 = *g;
        fmpz m2 = *m;

        if (!COEFF_IS_MPZ(m2))  /* m is small */
        {
            if (!COEFF_IS_MPZ(g2))  /* g is small */
            {
                int sgn = (g2 >= 0) ? 1 : -1;

                fmpz_set_ui(f, 
                    n_powmod(sgn * g2, (e <= (ulong) LONG_MAX) ? 
                    e : (e = e % n_euler_phi(m2)), m2));
                if (sgn < 0 && e % 2UL)
                    *f = n_negmod(*f, m2);
            }
            else  /* g is large */
            {
                __mpz_struct *ptr = _fmpz_promote(f);
                mpz_t m3;

                mpz_init_set_ui(m3, m2);
                mpz_powm_ui(ptr, COEFF_TO_PTR(g2), e, m3);
                mpz_clear(m3);

                _fmpz_demote_val(f);
            }
        }
        else  /* m is large */
        {
            if (!COEFF_IS_MPZ(g2))  /* g is small */
            {
                __mpz_struct *ptr = _fmpz_promote(f);
                mpz_t g3;

                mpz_init_set_si(g3, g2);
                mpz_powm_ui(ptr, g3, e, COEFF_TO_PTR(m2));
                mpz_clear(g3);

                _fmpz_demote_val(f);
            }
            else  /* g is large */
            {
               __mpz_struct * ptr = _fmpz_promote(f);

                mpz_powm_ui(ptr, COEFF_TO_PTR(g2), e, COEFF_TO_PTR(m2));

                _fmpz_demote_val(f);
            }
        }
    }
}
