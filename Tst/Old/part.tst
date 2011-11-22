//
// test script for diff command
//
ring r1 = 32003,(x,y,z),(c,dp);
r1;
poly s1=3x2y4-5xyz3;
s1;
"==============================";
diff(s1,x);
diff(s1,y);
diff(s1,z);
"------------------------------";
poly s2=5/3x4y2z6+1/5x2zy3-6xzy12;
s2;
"==============================";
diff(s2,x);
diff(s2,y);
diff(s2,z);
"--------------------------------";
vector v1=[s1,x2+z4];
v1;
"=================================";
diff(v1,x);
diff(v1,y);
diff(v1,z);
"--------------------------------";
vector v2=[s2,x2z2,s1,y2z];
v2;
"==================================";
diff(v2,x);
diff(v2,y);
diff(v2,z);
"---------------------------------";
module m1=v1,v2;
diff(m1,z);
"--------------------------------";
ideal i=s1,s2,s1+s2;
diff(i,y);
"------------------------------";
matrix m[2][2]=x2,x+y3,0,12;
diff(m,x);
diff(m,y);
diff(m,z);
"-----------------------------";
listvar(all);
kill r1;
LIB "tst.lib";tst_status(1);$;