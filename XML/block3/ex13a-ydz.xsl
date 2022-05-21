<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0"
    xmlns:sc3="urn:vsr:xml-werkzeuge:aufgabe2.3"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
>
    <xsl:template match="/">
        <html>
            <head></head>
            <body>
                <h1>Person</h1>
                <table border="1">
                    <xsl:for-each select="sc3:form">
                    <tr>
                        <td>First Name:</td>
                        <td><xsl:value-of select="sc3:firstName"/></td>
                    </tr>
                    <tr>
                        <td>Family Name:</td>
                        <td><xsl:value-of select="sc3:familyName"/></td>
                    </tr>
                    <tr>
                        <td>PSNR:</td>
                        <td><xsl:value-of select="sc3:psnr"/></td>
                    </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>