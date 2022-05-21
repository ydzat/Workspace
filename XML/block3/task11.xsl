<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
>

<xsl:template match="/">

<html>
    <meta http-equiv="cache-control" content="no-cache, no-store"></meta>
    <body>
        <h1>Sorted Animals</h1>

        <h2>By name:</h2>
        
        <ul>
            <xsl:apply-templates select="zoo/zoo_animal/name">
                <xsl:with-param name="q" select="'name'"/>
                <xsl:sort data-type="text/qname" order="incending"/>
            </xsl:apply-templates>
        </ul>
        
        <h2>By id:</h2>
        <ul>
            <xsl:apply-templates select="zoo/zoo_animal[@id]/name">
                <xsl:with-param name="q" select="'id'"/>
                <xsl:sort data-type="number" order="incending"/>
            </xsl:apply-templates>
        </ul>
        <h2>By age:</h2>
        <ul>
            <xsl:apply-templates select="zoo/zoo_animal/age">
                <xsl:with-param name="q" select="'age'"/>
                <xsl:sort data-type="number" order="incending"/>
            </xsl:apply-templates>
        </ul>

    </body>
</html>
</xsl:template>

<xsl:template match="*" >
    <xsl:param name="q"/>
    <xsl:if test=".!=''">
        <li>
            
            <xsl:choose>
                <xsl:when test="$q='name'">
                    <xsl:value-of select="."/>
                    
                </xsl:when>
                <xsl:when test="$q='id'">
                    <xsl:value-of select="."/>
                    (<xsl:value-of select="./../@id"/>)
                </xsl:when>
                <xsl:when test="$q='age'">
                    <xsl:value-of select="./../name"/>
                    (<xsl:value-of select="."/>)
                </xsl:when>
            </xsl:choose>
        </li>
    </xsl:if>
</xsl:template>

</xsl:stylesheet>