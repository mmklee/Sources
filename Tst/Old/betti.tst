ring r=32003,(a,b,c,d),(c,dp);
ideal j=bc-ad,b3-a2c,c3-bd2,ac2-b2d;
list T=mres(j,0);
print(betti(T),"betti");
ring R;
matrix A[4][1];
module M = A;
betti(nres(M,0));
betti(mres(M,0));
betti(sres(M,0));
M=0*gen(1);
betti(nres(M,0));
betti(mres(M,0));
betti(sres(M,0));
M =gen(2),A;
betti(nres(M,0));
betti(mres(M,0));
betti(sres(M,0));
matrix A[4][2]=0,0,1;
M=A;
betti(nres(M,0));
betti(mres(M,0));
betti(sres(M,0));
LIB "tst.lib";tst_status(1);$;