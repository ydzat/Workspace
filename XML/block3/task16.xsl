<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="2.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
>

    <xsl:template match="/">
        <html>
            <meta http-equiv="cache-control" content="no-cache, no-store"></meta>

            <h1><xsl:value-of select="store/@id" /></h1>
            <hr/>
            <h2>stock sorted by value</h2>

            
            <xsl:for-each-group select="//article" group-by="@value">
                <xsl:sort select="current-grouping-key()" order="ascending"/>
                <xsl:for-each select="current-group()">
                    <table>
                        <tr>
                            <th>Article number</th>
                            <th>Name</th>
                            <th>Value</th>
                            <th>Condition</th>
                            <th>Comment</th>
                            <th>House</th>
                            <th>Shelf</th>
                        </tr>
                        <tr>
                            <td><xsl:value-of select="@nr"/></td>
                            <td><xsl:value-of select="@name"/></td>
                            <td><xsl:value-of select="@value"/></td>
                            <td><xsl:value-of select="@condition"/></td>
                            <td><xsl:value-of select="."/></td>
                            <td><xsl:value-of select="./../../@id"/></td>
                            <td><xsl:value-of select="./../@id"/></td>
                        </tr>
                    
                    </table>
                </xsl:for-each>
                
            </xsl:for-each-group>
            

        </html>
    </xsl:template>


</xsl:stylesheet>