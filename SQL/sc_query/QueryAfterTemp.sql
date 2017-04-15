use studb;
select sn from s,temp_x,temp_y
where temp_x.x=temp_y.y and s.sno=temp_x.x;