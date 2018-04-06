select Dept.dName, count(Employee.dID) as num from Dept inner join Employee on Dept.dID = Employee.dID
group by Dept.dName
having count(Employee.dID) > 1

select Dept.dName, count(*) as num from Dept inner join Employee on Dept.dID = Employee.dID
group by Dept.dName
having count(*) > 1
