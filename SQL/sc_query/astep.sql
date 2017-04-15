use studb;

/*
select x.sno,x.cno,y.sno,y.cno from sc as x,sc as y
--where x.sno=y.sno and ((x.cno='C1' and y.cno='C2') or (x.cno='C2' and y.cno='C1'))
where x.sno=y.sno and x.cno='C1' and y.cno='C2';
*/

--select x.sno,x.cno,y.sno,y.cno,s.sno,s.sn from sc as x,sc as y,s
select s.sn from sc as x,sc as y,s
where x.sno=y.sno and x.cno='C1' and y.cno='C2' and x.sno=s.sno;
