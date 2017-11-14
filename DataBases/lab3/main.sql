USE [AthletesSupplements2]
GO
/****** Object:  StoredProcedure [dbo].[main]    Script Date: 11/14/2017 2:09:06 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- =============================================
-- Author:		<Author,,Name>
-- Create date: <Create Date,,>
-- Description:	<Description,,>
-- =============================================
ALTER PROCEDURE [dbo].[main]
@vers INT
AS
BEGIN

    DECLARE @currVers INT
	DECLARE @proc varchar(50)

	SELECT @currVers = version
	FROM CurrentVersion



	IF @currVers = @vers
	BEGIN
	    Print 'Already this version'
	END

	
	WHILE @currVers < @vers
	BEGIN
		SET  @currVers = @currVers + 1
		SET  @proc = 'up' + cast(@currVers as varchar(50)) 
		PRINT @proc
		EXEC @proc
	END
	
	
	WHILE @currVers > @vers
	BEGIN
		SET  @proc = 'down' + cast(@currVers as varchar(50)) 
		PRINT @proc
		EXEC @proc
		SET  @currVers = @currVers - 1
	END
	

	UPDATE CurrentVersion
	SET version = @vers

	


END
