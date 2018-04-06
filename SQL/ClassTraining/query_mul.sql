select x.dName, count(y.dID) from Dept as x, Employee as y
where y.dID = x.dID
group by x.dName
having count(y.dID) > 1

select x.dName, count(*) from Dept as x, Employee as y
where y.dID = x.dID
group by x.dName
having count(*) > 1
