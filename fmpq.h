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

    Copyright (C) 2011 Fredrik Johansson

******************************************************************************/

#ifndef FMPQ_H
#define FMPQ_H

#undef ulong /* interferes with system includes */
#include <stdio.h>
#define ulong unsigned long

#include <mpir.h>
#include "flint.h"
#include "fmpz.h"

typedef struct
{
    fmpz num;
    fmpz den;
}
fmpq;

typedef fmpq fmpq_t[1];

#define fmpq_numref(__x) (&(__x)->num)
#define fmpq_denref(__y) (&(__y)->den)


static __inline__ void fmpq_init(fmpq_t x)
{
    x->num = 0L;
    x->den = 1L;
}

static __inline__ void fmpq_clear(fmpq_t x)
{
    fmpz_clear(fmpq_numref(x));
    fmpz_clear(fmpq_denref(x));
}

static __inline__ void fmpq_zero(fmpq_t res)
{
    fmpz_zero(fmpq_numref(res));
    fmpz_set_ui(fmpq_denref(res), 1UL);
}

static __inline__ void fmpq_one(fmpq_t res)
{
    fmpz_set_ui(fmpq_numref(res), 1);
    fmpz_set_ui(fmpq_denref(res), 1);
}

static __inline__ int fmpq_equal(const fmpq_t x, const fmpq_t y)
{
    return fmpz_equal(fmpq_numref(x), fmpq_numref(y)) &&
           fmpz_equal(fmpq_denref(x), fmpq_denref(y));
}

static __inline__ int fmpq_sgn(const fmpq_t x)
{
    return fmpz_sgn(fmpq_numref(x));
}

static __inline__ int fmpq_is_zero(const fmpq_t x)
{
    return fmpz_is_zero(fmpq_numref(x));
}

static __inline__ int fmpq_is_one(const fmpq_t x)
{
    return fmpz_is_one(fmpq_numref(x)) && fmpz_is_one(fmpq_denref(x));
}

static __inline__ void fmpq_set(fmpq_t dest, const fmpq_t src)
{
    fmpz_set(fmpq_numref(dest), fmpq_numref(src));
    fmpz_set(fmpq_denref(dest), fmpq_denref(src));
}

static __inline__ void fmpq_swap(fmpq_t op1, fmpq_t op2)
{
    fmpz_swap(fmpq_numref(op1), fmpq_numref(op2));
    fmpz_swap(fmpq_denref(op1), fmpq_denref(op2));
}

static __inline__ void fmpq_neg(fmpq_t dest, const fmpq_t src)
{
    fmpz_neg(fmpq_numref(dest), fmpq_numref(src));
    fmpz_set(fmpq_denref(dest), fmpq_denref(src));
}

void _fmpq_canonicalise(fmpz_t num, fmpz_t den);

void fmpq_canonicalise(fmpq_t res);

int _fmpq_is_canonical(const fmpz_t num, const fmpz_t den);

int fmpq_is_canonical(const fmpq_t x);


void _fmpq_set_si(fmpz_t rnum, fmpz_t rden, long p, ulong q);

void fmpq_set_si(fmpq_t res, long p, ulong q);


static __inline__ void fmpq_set_mpq(fmpq_t dest, const mpq_t src)
{
    fmpz_set_mpz(fmpq_numref(dest), mpq_numref(src));
    fmpz_set_mpz(fmpq_denref(dest), mpq_denref(src));
}

static __inline__ void fmpq_get_mpq(mpq_t dest, const fmpq_t src)
{
    fmpz_get_mpz(mpq_numref(dest), fmpq_numref(src));
    fmpz_get_mpz(mpq_denref(dest), fmpq_denref(src));
}

char * _fmpq_get_str(char * str, int b, const fmpz_t num, const fmpz_t den);

char * fmpq_get_str(char * str, int b, const fmpq_t x);

void _fmpq_fprint(FILE * file, const fmpz_t num, const fmpz_t den);

void fmpq_fprint(FILE * file, const fmpq_t x);

static __inline__ void _fmpq_print(const fmpz_t num, const fmpz_t den)
{
    _fmpq_fprint(stdout, num, den);
}

static __inline__ void fmpq_print(const fmpq_t x)
{
    fmpq_fprint(stdout, x);
}

void _fmpq_randtest(fmpz_t num, fmpz_t den, flint_rand_t state, mp_bitcnt_t bits);

void fmpq_randtest(fmpq_t res, flint_rand_t state, mp_bitcnt_t bits);

void _fmpq_randbits(fmpz_t num, fmpz_t den, flint_rand_t state, mp_bitcnt_t bits);

void fmpq_randbits(fmpq_t res, flint_rand_t state, mp_bitcnt_t bits);



void _fmpq_add(fmpz_t rnum, fmpz_t rden, const fmpz_t op1num,
    const fmpz_t op1den, const fmpz_t op2num, const fmpz_t op2den);

void fmpq_add(fmpq_t res, const fmpq_t op1, const fmpq_t op2);


void _fmpq_sub(fmpz_t rnum, fmpz_t rden, const fmpz_t op1num,
    const fmpz_t op1den, const fmpz_t op2num, const fmpz_t op2den);

void fmpq_sub(fmpq_t res, const fmpq_t op1, const fmpq_t op2);


void _fmpq_mul(fmpz_t rnum, fmpz_t rden, const fmpz_t op1num,
    const fmpz_t op1den, const fmpz_t op2num, const fmpz_t op2den);

void fmpq_mul(fmpq_t res, const fmpq_t op1, const fmpq_t op2);


void fmpq_mul_fmpz(fmpq_t res, const fmpq_t op, const fmpz_t x);


void _fmpq_addmul(fmpz_t rnum, fmpz_t rden, const fmpz_t op1num,
    const fmpz_t op1den, const fmpz_t op2num, const fmpz_t op2den);

void fmpq_addmul(fmpq_t res, const fmpq_t op1, const fmpq_t op2);


void _fmpq_submul(fmpz_t rnum, fmpz_t rden, const fmpz_t op1num,
    const fmpz_t op1den, const fmpz_t op2num, const fmpz_t op2den);

void fmpq_submul(fmpq_t res, const fmpq_t op1, const fmpq_t op2);


void fmpq_inv(fmpq_t dest, const fmpq_t src);

void fmpq_div(fmpq_t res, const fmpq_t op1, const fmpq_t op2);

void fmpq_div_fmpz(fmpq_t res, const fmpq_t op, const fmpz_t x);


void fmpq_mul_2exp(fmpq_t res, const fmpq_t x, mp_bitcnt_t exp);

void fmpq_div_2exp(fmpq_t res, const fmpq_t x, mp_bitcnt_t exp);


int _fmpq_mod_fmpz(fmpz_t res, const fmpz_t num, const fmpz_t den, const fmpz_t mod);

int fmpq_mod_fmpz(fmpz_t res, const fmpq_t x, const fmpz_t mod);

int _fmpq_reconstruct_fmpz(fmpz_t num, fmpz_t den, const fmpz_t a, const fmpz_t m);

int fmpq_reconstruct_fmpz(fmpq_t res, const fmpz_t a, const fmpz_t m);

int
_fmpq_reconstruct_fmpz_2(fmpz_t n, fmpz_t d,
    const fmpz_t a, const fmpz_t m, const fmpz_t N, const fmpz_t D);

int
fmpq_reconstruct_fmpz_2(fmpq_t res, const fmpz_t a, const fmpz_t m,
                                        const fmpz_t N, const fmpz_t D);

mp_bitcnt_t fmpq_height_bits(const fmpq_t x);

void fmpq_height(fmpz_t height, const fmpq_t x);

void
_fmpq_next_calkin_wilf(fmpz_t rnum, fmpz_t rden,
    const fmpz_t num, const fmpz_t den);

void fmpq_next_calkin_wilf(fmpq_t res, const fmpq_t x);

void
_fmpq_next_signed_calkin_wilf(fmpz_t rnum, fmpz_t rden,
    const fmpz_t num, const fmpz_t den);

void
fmpq_next_signed_calkin_wilf(fmpq_t res, const fmpq_t x);

void
_fmpq_next_minimal(fmpz_t rnum, fmpz_t rden,
    const fmpz_t num, const fmpz_t den);

void fmpq_next_minimal(fmpq_t res, const fmpq_t x);

void
_fmpq_next_signed_minimal(fmpz_t rnum, fmpz_t rden,
    const fmpz_t num, const fmpz_t den);

void
fmpq_next_signed_minimal(fmpq_t res, const fmpq_t x);

long fmpq_get_cfrac(fmpz * c, fmpq_t rem, const fmpq_t x, long n);

void fmpq_set_cfrac(fmpq_t x, const fmpz * c, long n);

long fmpq_cfrac_bound(const fmpq_t x);


#endif