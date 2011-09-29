LIB "tst.lib"; tst_init();

ring R = 0, (x1, x2, x3, x4, x5), lp;
matrix w[26][11];
w =        1,  1, 1,  7, x4 , 12, x3 , 17, x2 , 22, x1,
           2,  2, 1,  8, x4 , 13, x3 , 18, x2 , 23, x1,
           3,  3, 1,  9, x4 , 14, x3 , 19, x2 , 24, x1,
           4,  4, 1, 10, x4 , 15, x3 , 20, x2 , 25, x1,
           5,  5, 1, 26, 1, 1, 0, 1, 0, 1, 0,
           6,  2, x5 ,  6, 1, 12, x3 , 17, x2 , 22, x1,
           7,  3, x5 ,  7, 1, 13, x3 , 18, x2 , 23, x1,
           8,  4, x5 ,  8, 1, 14, x3 , 19, x2 , 24, x1,
           9,  5, x5 ,  9, 1, 15, x3 , 20, x2 , 25, x1,
          10, 10, 1, 26, 1, 1, 0, 1, 0, 1, 0,
          11,  2, x5 ,  7, x4 , 11, 1, 17, x2 , 22, x1,
          12,  3, x5 ,  8, x4 , 12, 1, 18, x2 , 23, x1,
          13,  4, x5 ,  9, x4 , 13, 1, 19, x2 , 24, x1,
          14,  5, x5 , 10, x4 , 14, 1, 20, x2 , 25, x1,
          15, 15, 1, 26, 1, 1, 0, 1, 0, 1, 0,
          16,  2, x5 ,  7, x4 , 12, x3 , 16, 1, 22, x1,
          17,  3, x5 ,  8, x4 , 13, x3 , 17, 1, 23, x1,
          18,  4, x5 ,  9, x4 , 14, x3 , 18, 1, 24, x1,
          19,  5, x5 , 10, x4 , 15, x3 , 19, 1, 25, x1,
          20, 20, 1, 26, 1, 1, 0, 1, 0, 1, 0,
          21,  2, x5 ,  7, x4 , 12, x3 , 17, x2 , 21, 1,
          22,  3, x5 ,  8, x4 , 13, x3 , 18, x2 , 22, 1,
          23,  4, x5 ,  9, x4 , 14, x3 , 19, x2 , 23, 1,
          24,  5, x5 , 10, x4 , 15, x3 , 20, x2 , 24, 1,
          25, 25, 1, 26, 1, 1, 0, 1, 0, 1, 0,
          26,  1, x5 ,  6, x4 , 11, x3 , 16, x2 , 21, x1;

matrix m[26][26];
int i,j;
for (i = 1; i <= 26; i++)
   {
   for (j = 1; j <= 5; j++)
      {
        m[i, int(w[i, 2*j])] = w[i, 2*j+1];
      }
   }

tst_InitTimer();

poly result = det(m);

tst_ReportTimer("M1");

size(result);
lead(result);

map check = R, 2..nvars(R)+1;

det(check(m)) == check(result);

kill R, i, j;

tst_status(1); $

