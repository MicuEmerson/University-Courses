
/*1)Distint Tasks that are from 'Satu-Mare' city*/
SELECT DISTINCT  T.Description 
FROM EmployersTasks T
INNER JOIN Employeers E
ON T.Eid = E.Eid
INNER JOIN Address A
ON A.Aid = E.AddressId
WHERE A.City = 'Cluj'

/*2)Employeers from Cluj tasks without duplicate on the same tasks*/
SELECT DISTINCT E.FName as Name, T.Description
FROM Employeers E
INNER JOIN EmployersTasks T
ON E.Eid = T.Eid
INNER JOIN Address A
ON E.AddressId = A.Aid
WHERE A.City = 'Cluj'

/*3) Companies and their promotional products with before/after price having promotional price >= 50*/
SELECT C.Name as Company, P.Name as ProductName, P.Price as InitialPrice, PP.Price as PromotionalPrice
FROM Products P
INNER JOIN Promotions PP
ON P.Pid = PP.ProductID 
INNER JOIN Companies C
ON C.Comid = P.CompanyID
WHERE PP.Price >= 50

/*4) Order bigger then 150*/ 
SELECT C.FName as FirstName, C.SName as SecondName, P.Name as ProductName, P.Price as Price
FROM Orders O
INNER JOIN Customers C
ON O.CustomerID = C.Cid
INNER JOIN Products P
ON P.Pid = O.ProductID
WHERE P.Price > 150


/*5) Total price of the all orders a person made which is bigger then 100*/
SELECT C.FName as FirstName, C.SName as SecondName, SUM(P.Price) as TotalProductsPrice
FROM Orders O
INNER JOIN Customers C
ON O.CustomerID = C.Cid
INNER JOIN Products P
ON P.Pid = O.ProductID
Group by C.FName, C.SName
HAVING SUM(P.Price) > 100



/*6) How many products a person ordered*/
SELECT DISTINCT C.FName as FirstName, C.SName as SecondName, COUNT(O.Oid) as NrOfProductOrdered
FROM Orders O
FULL JOIN Customers C
ON O.CustomerID = C.Cid
FULL JOIN Products P
ON P.Pid = O.ProductID
Group by C.FName, C.SName
ORDER by COUNT(O.Oid) DESC



/*7) How many products were sold from a specific company and what was their price*/
SELECT COM.Name as Company, COUNT(*) as Products, SUM(P.Price) as TotalValue
FROM Orders O
INNER JOIN Customers C
ON O.CustomerID = C.Cid
INNER JOIN Products P
ON O.ProductID = P.Pid
INNER JOIN Companies COM
ON COM.Comid = P.CompanyID
GROUP BY COM.Name	

/*7) Customers who have orders bigger then 150*/
SELECT DISTINCT C.Fname as FirstName, C.Sname as SecondName
FROM Customers C
INNER JOIN Orders O
ON C.Cid = O.CustomerID
INNER JOIN Products P
ON O.ProductID = P.Pid
WHERE P.Price > 150



/* 8) Most successful company based on sales */
SELECT COM.Name,  COUNT(*) as ProductsSold
FROM Orders O
INNER JOIN Products P
ON O.ProductID = P.Pid
INNER JOIN Companies COM
ON P.CompanyID = COM.Comid
GROUP BY COM.Name
HAVING COUNT(*) = ( SELECT MAX(NumberOfProducts)
				    FROM(
						SELECT COUNT(*) as NumberOfProducts
						FROM Orders O
						INNER JOIN Products P
						ON O.ProductID = P.Pid
						GROUP BY P.CompanyID
						)t
				  )


/* OR IN THIS WAY */
SELECT TOP 1 COM.Name, COUNT(*) as ProductSold
FROM Orders O
INNER JOIN Products P
ON O.ProductID = P.Pid
INNER JOIN Companies COM
ON P.CompanyID = COM.Comid
GROUP BY COM.Name
ORDER  BY COUNT(*) DESC

/*9) How much a company sold & sponsored group by cities*/
SELECT COM.Name as Company, City, SUM(P.price) as SalesValue, SUM(CSA.Price) as SponsorshipValue
FROM Address A
INNER JOIN Customers C
ON A.Aid = C.AddressId
INNER JOIN Orders O
ON C.Cid = O.CustomerID
INNER JOIN Products P
ON O.ProductID = P.Pid
INNER JOIN Companies COM
ON P.CompanyID = COM.Comid
INNER JOIN CompaniesSponsoredAthletes CSA
ON COM.Comid = CSA.Comid
INNER JOIN SponsoredAthletes SA
ON CSA.SAid = SA.SAid
GROUP BY A.City, COM.Name

/*10) Profit that a company made in a specific city, by profit I mean totalSaleValue - totalSponsorshipValue*/
SELECT COM.Name as Company, City, SUM(P.price)-SUM(CSA.PRICE) as  Profit
FROM Address A
INNER JOIN Customers C
ON A.Aid = C.AddressId
INNER JOIN Orders O
ON C.Cid = O.CustomerID
INNER JOIN Products P
ON O.ProductID = P.Pid
INNER JOIN Companies COM
ON P.CompanyID = COM.Comid
INNER JOIN CompaniesSponsoredAthletes CSA
ON COM.Comid = CSA.Comid
INNER JOIN SponsoredAthletes SA
ON CSA.SAid = SA.SAid
GROUP BY A.City, COM.Name




/*11) For Every Company it shows total sales values and sponsorships values
 */
SELECT COM.Name as Company, Sum(P.Price) as Sales, Sum(CSA.Price) as Sponsorships
FROM Companies COM
INNER JOIN Products P
ON COM.Comid = P.CompanyID
INNER JOIN CompaniesSponsoredAthletes CSA
ON COM.Comid = CSA.Comid
INNER JOIN Orders O
ON P.Pid = O.ProductID
GROUP BY COM.Name


