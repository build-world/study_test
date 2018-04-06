select Dept.dID, Dept.dName, temp.num from Dept
inner join
(
	select dID, count(dID) as num from Employee
	group by dID
	having count (dID) > 1
)
as temp
on Dept.dID = temp.dID

select Dept.dID, Dept.dName, temp.num from Dept
inner join
(
	select dID, count(*) as num from Employee
	group by dID
	having count (*) > 1
)
as temp
on Dept.dID = temp.dID
