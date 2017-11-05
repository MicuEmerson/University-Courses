insert into Products(pid, name, price, description, quantity, companyID)
values
(1, 'Proteine', 100, null, 3, null),
(2, 'Creatina', 200, null, 2, null),
(3, 'Oxid Nitric', 300, null, 1, null),
(4, 'EnergyDrink', 100, null, 3, null),
(5, 'Aminoacizi', 250, null, 9, null)

insert into Employeers(Eid, Fname, Sname, AddressId)
values
(1, 'Maxwell', 'John', null),
(2, 'Constantin', 'Mihai', null),
(3, 'Pomian', 'Sebastian', null),
(4, 'Nechita', 'Florin', null),
(5, 'Avram', 'Carmen', null)

insert into EmployersTasks(ETid, description, Eid)
values
(1, 'Curatenie', 2),
(2, 'Descarca marfa', 3),
(3, 'Verifica produse expirate', 5),
(4, 'Incheie contracte', 1),
(5, 'Plateste salariile', 1),
(6, 'Comanda produse noi', 1)


insert into Promotions(Promid, Price, Data, ProductID)
values
(1, 50, '2017-11-20', 2),
(2, 75, '2017-11-22', 3),
(3, 80, '2017-11-21', 5)

insert into Address(Aid, City, Street)
values
(1, 'Satu-Mare', 'Cibinului'),
(2, 'Cluj', 'Dorobantilor'),
(3, 'Cluj', 'Teodor Mihali'),
(4, 'Satu-Mare', 'Fantanele'),
(5, 'Cluj', 'Cipariu'),
(6, 'Satu-Mare', 'Alea Postavaru'),
(7, 'Satu-Mare', 'Ipotesti'),
(8, 'Cluj', 'Piezisa')

insert into SponsoredAthletes(SAid, FName, Sname)
values
(1, 'Ciugureanu', 'Calin'),
(2, 'Macarie', 'Cristian'),
(3, 'Coleman', 'Ronnie'),
(4, 'Halep', 'Simona'),
(5, 'Stoica', 'Andrei'),
(6, 'Adegbuyi', 'Benny')

insert into Customers(Cid, Fname, Sname, Gender, Age, CardNumber, AddressId)
values
(1, 'Busteaga', 'Mihai', 'M', 29, 1423123421239765, 1),
(2, 'Busteaga', 'Sergiu', 'M', 27, 1423123421239766, 1),
(3, 'Chircu', 'George', 'M', 30, 1423123421239767, 4),
(4, 'Morariu', 'Dorel', 'M', 22, 1423123421239768, 2),
(5, 'Radu', 'Marian', 'M', 25, 1423123421239761, 3),
(6, 'Morariu', 'Mirela', 'F', 21, 1423123421239762, 2),
(7, 'Prigoana', 'Daniel', 'M', 29, 1423123421239763, 5),
(8, 'Muresan', 'Alexandru', 'M', 28, 1423123421239764, 6),
(9, 'Sandor', 'Karina', 'F', 19, 1423123421239760, 7),
(10, 'Prigoana', 'Daniel', 'M', 21, 1423123421239769, 8)

insert into Companies(Comid, Name, Phone, Email)
values
(1, 'Mega Proteine.SA', 0745819449, 'office@megaproteine.ro'),
(2, 'MassUP.SRL', 0747819419, 'office@massup.ro'),
(3, 'Redis.SA', 0744119449, 'office@redis.ro'),
(4, 'ProNutrition', 07128349889, 'office@pronutrition.ro'),
(5, 'GetFitShop', 0778962819, 'office@getfitshop.ro')

insert into CompaniesSponsoredAthletes(Comid, SAid, Date)
values
(1, 1, '2017-11-20'),
(1, 2, null),
(2, 3, '2017-12-18'),
(3, 4, null),
(4, 6, null),
(1, 6, null),
(5, 5, '2017-10-28')


insert into Orders(Oid, Date, CustomerID, ProductID, Price)
values 
(1, '2017-11-20', 1, 1),
(2, '2017-11-20', 1, 2),
(3, '2017-11-21', 1, 3),
(4, '2017-11-22', 3, 4),
(5, '2017-12-23', 5, 2),
(6, '2017-11-24', 2, 5)