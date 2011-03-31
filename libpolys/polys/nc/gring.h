#ifndef GRING_H
#define GRING_H
/****************************************
*  Computer Algebra System SINGULAR     *
****************************************/
/* $Id$ */
/*
* ABSTRACT additional defines etc for --with-plural
*/

#ifdef HAVE_PLURAL


#include <kernel/structs.h>
#include <kernel/ring.h>
#include <kernel/matpol.h>

// BOOLEAN nc_CheckOrdCondition(matrix D, ring r);
// BOOLEAN nc_CheckOrdCondition(ring r); // with D == r->GetNC()->D

BOOLEAN nc_CheckSubalgebra(poly PolyVar, ring r);

// BOOLEAN nc_InitMultiplication(ring r); // should call nc_p_ProcsSet!
// NOTE: instead of constructing nc_struct and calling nc_InitMultiplication yourself - just create C, D and call nc_CallPlural!!!


BOOLEAN rIsLikeOpposite(ring rBase, ring rCandidate);


// set pProcs table for rGR and global variable p_Procs
// this should be used by p_ProcsSet in p_Procs_Set.h
void nc_p_ProcsSet(ring rGR, p_Procs_s* p_Procs);


// used by "rSum" from ring.cc only! 
// purpose init nc structure for initially commutative ring:
// "creates a commutative nc extension; "converts" comm.ring to a Plural ring"
ring nc_rCreateNCcomm(ring r); 


// poly _gnc_p_Mult_q(poly p, poly q, const int copy, const ring r);

// general multiplication:
poly _nc_p_Mult_q(poly p, poly q, const ring r);
poly _nc_pp_Mult_qq(const poly p, const poly q, const ring r);


/* copy : */
poly nc_p_CopyGet(poly a, const ring r);
poly nc_p_CopyPut(poly a, const ring r);

void nc_PolyPolyRed(poly &b, poly p, number *c);



poly nc_CreateShortSpoly(poly p1, poly p2, const ring r=currRing);


/* brackets: p will be destroyed... */
poly nc_p_Bracket_qq(poly p, const poly q);

/* twostd: */
ideal twostd(ideal I);
/* Ann: */
ideal Approx_Step(ideal L);

/* complete reduction routines */

matrix nc_PrintMat(int a, int b, ring r, int metric);

poly p_CopyEmbed(poly p, ring srcRing, int shift, int par_shift);


// const int GRMASK = 1 << 1;
const int SCAMASK = 1; // For backward compatibility
const int TESTSYZSCAMASK = 0x0100 | SCAMASK; //

// NCExtensions Mask Property 
int& getNCExtensions();
int  setNCExtensions(int iMask);

// Test
bool ncExtensions(int iMask); //  = 0x0FFFF


// returns the LCM of the head terms of a and b with the given component 
// NOTE: coeff will be created but remains undefined(zero?) 
poly p_Lcm(const poly a, const poly b, const long lCompM, const ring r);

// returns the LCM of the head terms of a and b with component = max comp. of a & b
// NOTE: coeff will be created but remains undefined(zero?) 
poly p_Lcm(const poly a, const poly b, const ring r);



// //////////////////////////////////////////////////////////////////////// //
// NC inlines

inline nc_struct*& GetNC(ring r)
{
  return r->GetNC();
} 

inline nc_type& ncRingType(nc_struct* p)
{
  assume(p!=NULL);
  return (p->ncRingType());
}

inline nc_type ncRingType(ring r) // Get
{
  if(rIsPluralRing(r))
    return (ncRingType(r->GetNC()));
  else
    return (nc_error);
}

inline void ncRingType(ring r, nc_type t) // Set
{
  assume((r != NULL) && (r->GetNC() != NULL));
  ncRingType(r->GetNC()) = t;
}

inline void ncRingType(nc_struct* p, nc_type t) // Set
{
  assume(p!=NULL);
  ncRingType(p) = t;
}


// //////////////////////////////////////////////////////

// returns m*p, does neither destroy p nor m
inline poly nc_mm_Mult_pp(const poly m, const poly p, const ring r)
{
  assume(rIsPluralRing(r));
  assume(r->GetNC()->p_Procs.mm_Mult_pp!=NULL);
  return r->GetNC()->p_Procs.mm_Mult_pp(m, p, r);
//  return pp_Mult_mm( p, m, r);
}


// returns m*p, does destroy p, preserves m
inline poly nc_mm_Mult_p(const poly m, poly p, const ring r)
{
  assume(rIsPluralRing(r));
  assume(r->GetNC()->p_Procs.mm_Mult_p!=NULL);
  return r->GetNC()->p_Procs.mm_Mult_p(m, p, r);
//   return p_Mult_mm( p, m, r);
}

inline poly nc_CreateSpoly(const poly p1, const poly p2, const ring r)
{
  assume(rIsPluralRing(r));
  assume(r->GetNC()->p_Procs.SPoly!=NULL);
  return r->GetNC()->p_Procs.SPoly(p1, p2, r);
}

inline poly nc_ReduceSpoly(const poly p1, poly p2, const ring r)
{
  assume(rIsPluralRing(r));
  assume(r->GetNC()->p_Procs.ReduceSPoly!=NULL);
#ifdef PDEBUG
//  assume(p_LmDivisibleBy(p1, p2, r));
#endif
  return r->GetNC()->p_Procs.ReduceSPoly(p1, p2, r);
}

/*
inline void nc_PolyReduce(poly &b, const poly p, number *c, const ring r) // nc_PolyPolyRed
{
  assume(rIsPluralRing(r));
//  assume(r->GetNC()->p_Procs.PolyReduce!=NULL);
//  r->GetNC()->p_Procs.PolyReduce(b, p, c, r);
}
*/

inline void nc_kBucketPolyRed(kBucket_pt b, poly p, number *c)
{
  assume(rIsPluralRing(currRing));

//   return gnc_kBucketPolyRedNew(b, p, c);

  assume(currRing->GetNC()->p_Procs.BucketPolyRed!=NULL);
  return currRing->GetNC()->p_Procs.BucketPolyRed(b, p, c);
}

inline void nc_BucketPolyRed_Z(kBucket_pt b, poly p, number *c)
{
  assume(rIsPluralRing(currRing));

//   return gnc_kBucketPolyRed_ZNew(b, p, c);

  assume(currRing->GetNC()->p_Procs.BucketPolyRed_Z!=NULL);
  return currRing->GetNC()->p_Procs.BucketPolyRed_Z(b, p, c);

}

inline ideal nc_GB(const ideal F, const ideal Q, const intvec *w, const intvec *hilb, kStrategy strat)
{
  assume(rIsPluralRing(currRing));

  assume(currRing->GetNC()->p_Procs.GB!=NULL);
  return currRing->GetNC()->p_Procs.GB(F, Q, w, hilb, strat);

/*
  if (rHasLocalOrMixedOrder(currRing))
  {
    assume(currRing->GetNC()->p_Procs.LocalGB!=NULL);
    return currRing->GetNC()->p_Procs.LocalGB(F, Q, w, hilb, strat);
  } else
  {
    assume(currRing->GetNC()->p_Procs.GlobalGB!=NULL);
    return currRing->GetNC()->p_Procs.GlobalGB(F, Q, w, hilb, strat);
  }
*/
}




// inline const nc_struct* GetNC() const { return GetBasering()->GetNC(); } 


// read only access to NC matrices C/D:
// get C_{i,j}, 1 <= row = i < j = col <= N
inline poly GetC( const ring r, int i, int j ) 
{
  assume(r!= NULL && rIsPluralRing(r));
  const matrix C = GetNC(r)->C;
  assume(C != NULL);
  const int ncols = C->ncols;
  assume( (i > 0) && (i < j) && (j <= ncols) );
  return ( C->m[ncols * ((i)-1) + (j)-1] );
}

// get D_{i,j}, 1 <= row = i < j = col <= N
inline poly GetD( const ring r, int i, int j ) 
{
  assume(r!= NULL && rIsPluralRing(r));
  const matrix D = GetNC(r)->D;
  assume(D != NULL);
  const int ncols = D->ncols;
  assume( (i > 0) && (i < j) && (j <= ncols) );
  return ( D->m[ncols * ((i)-1) + (j)-1] );
}


#ifdef PLURAL_INTERNAL_DECLARATIONS

// we need nc_gr_initBba for sca_gr_bba and gr_bba.
void nc_gr_initBba(ideal F,kStrategy strat); 
BOOLEAN gnc_InitMultiplication(ring r, bool bSetupQuotient = false); // just for a moment

#endif // PLURAL_INTERNAL_DECLARATIONS

#endif // HAVE_PLURAL :(
#endif // 
