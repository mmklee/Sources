//
// test script for find command
//
ring r1 = 32003,(x,y,z),(c,dp);
r1;
"-------------------------------";
find("ABab","a");
"-----------------------------";
find("ABCaaB""a");
"------------------------------";
find("6,523",","+"5");
"------------------------------";
find("012","yxc");
"-----------------------------";
find("1231231231234","2",2);
find("1231231231234","2",3);
find("1231231231234","2",4);
find("1231231231234","2",5);
find("1231231231234","2",6);
find("1231231231234","2",12);
find("1231231231234","2",20);
listvar(all);
kill r1;
LIB "tst.lib";tst_status(1);$;