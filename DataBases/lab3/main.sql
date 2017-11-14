-- ================================================
-- Template generated from Template Explorer using:
-- Create Procedure (New Menu).SQL
--
-- Use the Specify Values for Template Parameters 
-- command (Ctrl-Shift-M) to fill in the parameter 
-- values below.
--
-- This block of comments will not be included in
-- the definition of the procedure.
-- ================================================
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- =============================================
-- Author:		<Author,,Name>
-- Create date: <Create Date,,>
-- Description:	<Description,,>
-- =============================================
CREATE PROCEDURE main
@vers INT
AS
BEGIN

    DECLARE @currVers INT
	DECLARE @proc varchar(50)

	SELECT @currVers = version
	FROM CurrentVersion

	
	WHILE @currVers < @vers
	BEGIN
	    SET  @currVers = @currVers + 1
	    SET  @proc = 'up' + cast(@currVers as varchar(50)) 
		PRINT @proc
		EXEC @proc
	END

	WHILE @currVers > @vers - 1
	BEGIN
	    SET  @currVers = @currVers - 1
	    SET  @proc = 'down' + cast(@currVers as varchar(50)) 
		PRINT @proc
		EXEC @proc
	END

	UPDATE CurrentVersion
	SET version = @vers


END
GO
