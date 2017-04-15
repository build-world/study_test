use studb;
create table temp_x
(
x char(4) not null
);
create table temp_y
(
y char(4) not null
);

insert into temp_x select sno as x from sc where sc.cno='C1';
insert into temp_y select sno as y from sc where sc.cno='C2';
