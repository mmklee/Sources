LIB "tst.lib"; tst_init(); option(prot);

ring w6=32003,(x(1..16)),dp;
ideal i0=
x(1)+x(2)+x(3)+x(4),
x(1)^2*x(2)^2+x(2)*x(3)*x(5)*x(6)+x(3)*x(4)*x(9)*x(10)+x(4)*x(5)*x(13)*x(14),
x(1)*x(2)^2*x(3)+x(2)*x(3)*x(6)*x(7),
x(3)*x(4)*x(10)*x(11)+x(4)*x(5)*x(14)*x(15),
x(1)*x(2)*x(3)*x(4)+x(2)*x(3)*x(7)*x(8),
x(3)*x(4)*x(11)*x(12)+x(4)*x(5)*x(15)*x(16),
x(1)*x(2)*x(4)*x(5)+x(2)*x(3)*x(8)*x(9),
x(3)*x(4)*x(12)*x(13)+x(1)*x(4)*x(5)*x(16),
x(1)*x(2)*x(5)*x(6)+x(5)*x(6)^2*x(7),
x(7)*x(8)*x(9)*x(10)+x(8)*x(9)*x(13)*x(14),
x(2)*x(3)*x(5)*x(6)+x(6)^2*x(7)^2+x(7)*x(8)*x(10)*x(11)+x(8)*x(9)*x(14)*x(15),
x(3)*x(4)*x(5)*x(6)+x(6)*x(7)^2*x(8),
x(7)*x(8)*x(11)*x(12)+x(8)*x(9)*x(15)*x(16),
x(4)*x(5)^2*x(6)+x(6)*x(7)*x(8)*x(9),
x(7)*x(8)*x(12)*x(13)+x(1)*x(8)*x(9)*x(16),
x(1)*x(2)*x(9)*x(10)+x(5)*x(6)*x(10)*x(11),
x(9)*x(10)*x(11)*x(12)+x(12)*x(13)^2*x(14),
x(2)*x(3)*x(9)*x(10)+x(6)*x(7)*x(10)*x(11),
x(10)*x(11)^2*x(12)+x(12)*x(13)*x(14)*x(15),
x(3)*x(4)*x(9)*x(10)+x(7)*x(8)*x(10)*x(11)+x(11)^2*x(12)^2+
x(12)*x(13)*x(15)*x(16),
x(4)*x(5)*x(9)*x(10)+x(8)*x(9)*x(10)*x(11),
x(11)*x(12)^2*x(13)+x(1)*x(12)*x(13)*x(16),
x(1)*x(2)*x(13)*x(14)+x(5)*x(6)*x(14)*x(15),
x(1)*x(13)*x(14)*x(16)+x(9)*x(10)*x(15)*x(16),
x(2)*x(3)*x(13)*x(14)+x(6)*x(7)*x(14)*x(15),
x(10)*x(11)*x(15)*x(16)+x(1)*x(14)*x(15)*x(16),
x(3)*x(4)*x(13)*x(14)+x(7)*x(8)*x(14)*x(15),
x(11)*x(12)*x(15)*x(16)+x(1)*x(15)*x(16)^2,
x(4)*x(5)*x(13)*x(14)+x(8)*x(9)*x(14)*x(15)+x(12)*x(13)*x(15)*x(16)+
x(1)^2*x(16)^2;

eliminate(i0,x(1)*x(2));

tst_status(1);$