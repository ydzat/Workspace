<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0"
    xmlns:xs="urn:myspace:deliveries"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
>

    <xsl:template match="/">
        <html>
            <body>
                <h1>Deliveries</h1>
                <table border="1">
                    <tr>
                        <th>Number</th>
                        <th>article</th>
                        <th>price</th>
                        <th>supplier</th>
                    </tr>
                    <xsl:for-each select="xs:deliveries/xs:article">
                        
                        <tr>
                            <td><xsl:value-of select="@id"/></td>
                            <td><xsl:value-of select="xs:name" /></td>
                            
                            <td>
                            <xsl:choose>
                                <xsl:when test="xs:price/@unitprice='true'">
                                    <xsl:value-of select="xs:price" /> (per p)
                                </xsl:when>
                                <xsl:when test="xs:price/@unitprice='false'">
                                    <xsl:value-of select="xs:price" /> (per kg)
                                </xsl:when>
                                    
                                <xsl:otherwise>
                                   <xsl:value-of select="xs:price" /> (N/A)
                                </xsl:otherwise>
                            </xsl:choose>
                            <!-- <xsl:if test="xs:price/@unitprice='true'">
                                <xsl:value-of select="xs:price" /> (per p)
                            </xsl:if>
                            <xsl:if test="xs:price/@unitprice='false'">
                                <xsl:value-of select="xs:price" /> (per kg)
                            </xsl:if>
                            <xsl:if test="xs:price/@unitprice=''">
                                <xsl:value-of select="xs:price" /> (N/A)
                            </xsl:if>-->
                            </td>
                            
                            
                            <td><xsl:value-of select="xs:supplier" /></td>
                        </tr>
                        
                    </xsl:for-each>
                </table>
            </body>
        </html>

    </xsl:template>


</xsl:stylesheet>