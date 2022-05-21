<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
>

<xsl:template match="/">

<html>
    <meta http-equiv="cache-control" content="no-cache, no-store"></meta>
    <body>
        <h1>Animal names in zoo "vsr zoo"</h1>

        <p>The animals in zoo "vsr zoo" have the following names:</p>

        <p>
            
            <xsl:for-each select="zoo/zoo_animal">
            
                <xsl:choose>
                    <xsl:when test="position() &lt; 3">
                        <xsl:value-of select="name"/>,
                    </xsl:when>
                    <xsl:when test="position() = 3">
                        <xsl:value-of select="name"/> and
                    </xsl:when>
                    <xsl:otherwise>
                        <xsl:value-of select="name"/>
                    </xsl:otherwise>
                </xsl:choose>
            </xsl:for-each>
        </p>

    </body>
</html>
</xsl:template>
</xsl:stylesheet>