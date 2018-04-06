create table Dept
(
	dID char(2),
	dName char(20),
	dLoc char(40)
	constraint Dept_pk primary key (dID)
)

create table Employee
(
	eID char(4),
	eName char(20),
	Age int,
	eTime datetime,
	Salary int,
	Phone char(20),
	dID char(2)
	constraint Employee_pk primary key (eID),
	constraint Employee_fk foreign key (dID) references Dept(dID)
)