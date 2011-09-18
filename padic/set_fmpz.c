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

    Copyright (C) 2011 Sebastian Pancratz
 
******************************************************************************/

#include "padic.h"

void _padic_set_fmpz(padic_t rop, const fmpz_t op, const padic_ctx_t ctx)
{
    if (!fmpz_is_zero(op))
    {
        padic_val(rop) = fmpz_remove(padic_unit(rop), op, ctx->p);
    }
    else
    {
        _padic_zero(rop);
    }
}

void padic_set_fmpz(padic_t rop, const fmpz_t op, const padic_ctx_t ctx)
{
    _padic_set_fmpz(rop, op, ctx);
    padic_reduce(rop, ctx);
}
