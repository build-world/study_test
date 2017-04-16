use studb;

--inner join
--select * from s inner join sc on s.sno=sc.sno inner join c on sc.cno=c.cno;

/*
select * from s,sc,c
where s.sno=sc.sno and sc.cno=c.cno;
*/

--outer join
select * from s full join sc on s.sno=sc.sno full join c on sc.cno=c.cno;
