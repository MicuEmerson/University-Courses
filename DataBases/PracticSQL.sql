USE SimularePractic
GO

IF OBJECT_ID('RoutesStations', 'U') IS NOT NULL
	DROP TABLE RoutesStations

	
IF OBJECT_ID('Stations', 'U') IS NOT NULL
	DROP TABLE Stations

IF OBJECT_ID('Routes', 'U') IS NOT NULL
	DROP TABLE [Routes]

IF OBJECT_ID('Trains', 'U') IS NOT NULL
	DROP TABLE Trains

IF OBJECT_ID('TrainTypes', 'U') IS NOT NULL
	DROP TABLE TrainTypes

GO

CREATE TABLE TrainTypes
	(
	TTID TINYINT PRIMARY KEY IDENTITY(1,1),
	[Description] varchar(50)
	)

CREATE TABLE Trains
	(
	TID smallint primary key identity(1,1),
	TName varchar(50),
	TTID tinyint references TrainTypes(TTID)
	)

create TABLE [Routes]
	(
	RID smallint primary key identity(1,1),
	Rname varchar(50),
	TID smallint references Trains(TID)
	)

create TABLE Stations
	(
	[SID] smallint primary key identity(1,1),
	Sname varchar(50)
	)

create TABLE RoutesStations
	(
	RID smallint references [Routes](RID),
	[SID] smallint references Stations([SID]),
	primary key(rid, [sid]),
	[Description] varchar(50),
	Arrival TIME,
	Departure TIME
	)

go

INSERT TrainTypes VALUES('regio'), ('interregio')
INSERT Trains VALUES('t1',1), ('t2',1), ('t3', 1)
INSERT [Routes] VALUES ('r1', 1), ('r2', 2), ('r3', 3)
INSERT Stations VALUES ('s1'), ('s2'), ('s3')
INSERT RoutesStations(RID, [SID], Arrival, Departure) VALUES
	(1, 1, '6:00am', '6:10am'), 
	(1, 2, '7:00am', '7:10am'),
	(1, 3, '8:00am', '8:10am'),
	(2, 1, '5:50am', '6:00am'),
	(2, 3, '17:00', '17:10'),
	(3, 2, '7:05am', '7:15'),
	(3, 3, '18:00', '18:10')

SELECT * FROM TrainTypes
SELECT * FROM Trains
SELECT * FROM [Routes]
SELECT * FROM Stations
SELECT * FROM RoutesStations

GO
--proc
CREATE OR ALTER PROC upsStationOnRoute @RName VARCHAR(50), @Sname varchar(50), @Arrival time, @Departure time
as
	DECLARE @RID smallint = (SELECT RID FROM [Routes] WHERE RName = @RName)
	DECLARE @SID smallint = (SELECT SID FROM Stations WHERE Sname = @Sname)
	
	IF EXISTS (SELECT *FROM RoutesStations WHERE RID = @RID and [SID] = @SID)
		UPDATE RoutesStations 
	    SET Arrival = @Arrival, Departure = @Departure
		WHERE RID = @RID AND [SID] = @SID
	ELSE
		INSERT RoutesStations (RID, [SID], Arrival, Departure) 
		VALUES (@RID, @SID, @Arrival, @Departure)


GO


SELECT* FROM RoutesStations

GO
CREATE OR ALTER VIEW vRoutesWithAllStations
AS
	SELECT R.RName
	FROM [Routes] R
	WHERE NOT EXISTS
		(SELECT S.[SID]
		FROM Stations S
		EXCEPT
		SELECT RS.[SID]
		FROM RoutesStations RS
		WHERE RS.RID = R.RID)

GO

SELECT * FROM vRoutesWithAllStations

GO

CREATE OR ALTER FUNCTION ufStationsAtLeast()
RETURNS TABLE
AS 
	RETURN SELECT S.SName
	FROM Stations S
	WHERE S.[SID] IN 
				(SELECT RS1.[SID]
				FROM RoutesStations RS1 INNER JOIN RoutesStations RS2
				ON RS1.[SID] = RS2.[SID] AND 
				RS1.RID < RS2.RID AND
				 RS1.Arrival <= RS2.Departure AND
				 RS1.Departure >= RS2.Arrival 
				)
	GO

	SELECT * FROM ufStationsAtLeast()
	GO
















