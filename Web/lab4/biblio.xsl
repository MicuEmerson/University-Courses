<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
  <html>
  <head>
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous">
</link> 
</head>
  <body>

 <!--
  <nav class="navbar navbar-inverse">
  <div class="container-fluid">
    <div class="navbar-header">
      <a class="navbar-brand" href="#">WebSiteName</a>
    </div>
    <ul class="nav navbar-nav">
      <li class="active"><a href="#">Home</a></li>
      <li><a href="#">Page 1</a></li>
      <li><a href="#">Page 2</a></li>
    </ul>
    <ul class="nav navbar-nav navbar-right">
      <li><a href="#"><span class="glyphicon glyphicon-user"></span> Sign Up</a></li>
      <li><a href="#"><span class="glyphicon glyphicon-log-in"></span> Login</a></li>
    </ul>
  </div>
  </nav>
  -->


  <h1>Bootstrap Tutorial</h1>      
  <p>Bootstrap is the most popular HTML, CSS, and JS framework for developing responsive, mobile-first projects on the web.</p>
  

  <h2 class="h2">My bibliography</h2>
  <div class="table-responsive-md">
    <table border="1" class="table table-bordered table-striped table-hover">
        <thead class="thead-light">
          <tr>
              <th scope="col">title</th>
              <th scope="col">author</th>
              <th scope="col">category</th>
              <th scope="col">year</th>
          </tr>
        </thead>
        <xsl:for-each select="entries/entry">
            <xsl:sort select="author"/>
            <tr scope="row">
                <td scope="col"><xsl:value-of select="title"/></td>
                <td scope="col"><xsl:value-of select="author"/></td>
                <td scope="col"><xsl:value-of select="category"/></td>
                <td scope="col"><xsl:value-of select="year"/></td>
            </tr>
        </xsl:for-each>
    </table>
  </div>
  </body>
  </html>
</xsl:template>

</xsl:stylesheet>