create database AthletesSupplements2


create table Products(

    Pid int primary key,
	Name varchar(30) DEFAULT'To be Complete',
	Price int DEFAULT 'To be set',
	Description varchar(30) DEFAULT'To be Complete',
	Quantity int,

)

create table Customers(

    Cid int primary key,
	FName varchar(30) not null,
	SName varchar(30) not null,
	Gender char(1) check (Gender = 'F' or Gender = 'M'),
	Age int check( Age > 0 and Age < 130 ),
	CardNumber char(16) not null,
	AddressId int
)


create table Orders(

      Oid int primary key,
	  Description varchar(200),
	  CustomerID int foreign key references Customers(Cid),
	  ProductID int foreign key references Products(Pid)
    
)

create table Companies(

    Comid int primary key,
	Description varchar(200),
	Phone char(10),
	Email varchar(30) 
)

create table SponsoredAthletes(

    SAid int primary key,
	FName varchar(30),
	SName varchar(30),
	
)


create table CompaniesSponsoredAthletes(
    
	Comid int foreign key references Companies(Comid),
	SAid int foreign key references SponsoredAthletes(SAid),
	Description varchar(30),
	CONSTRAINT PK_CompaniesSponsoredAthletes primary key(Comid, SAid)
	
)


alter table Products add constraint FK_Companie_Products foreign key (CompanyID) references Companies(Comid)

create table Promotions(

    Promid int primary key,
	Description varchar(300),
	Data datetime,
    ProductID int foreign key references Products(Pid)
)

create table Address(
   
     Aid int primary key,
	 City varchar(20),
	 Street varchar(20)

)

create table Employeers(

     Eid int primary key,
	 Fname varchar(20),
	 Sname varchar(20),
	 AddressId int foreign key references Address(Aid)

)

alter table Customers add constraint FK_Customers_Address foreign key (AddressId) references Address(Aid)

create table EmployersTasks(
   
    ETid int primary key,
	Description varchar(300)

)


alter table EmployersTasks add Eid int

alter table EmployersTasks add constraint FK_EmployersTask_Employers foreign key (Eid) references Employeers(Eid)