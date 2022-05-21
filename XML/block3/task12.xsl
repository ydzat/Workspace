<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
>

<xsl:template match="/">
    <html>
        <meta http-equiv="cache-control" content="no-cache, no-store"></meta>
        <body>
            <h1>Numbers</h1>
            <hr/>
            <xsl:for-each select="numbers/number">
                <p>
                    <xsl:call-template name="recv">
                        <xsl:with-param name="v" select="@value"/>
                        <xsl:with-param name="i" select="1"/>
                    </xsl:call-template>
                </p>
            </xsl:for-each>
        </body>
    </html>
</xsl:template>

<xsl:template name="recv">
    <xsl:param name="v"/>
    <xsl:param name="i"/>
    
    <xsl:if test="$i &lt;= $v">
        <xsl:value-of select="$v"/>
        <xsl:text> </xsl:text>
        <xsl:call-template name="recv">
            <xsl:with-param name="v" select="$v"/>
            <xsl:with-param name="i" select="$i + 1"/>
        </xsl:call-template>
    </xsl:if>
    
</xsl:template>

</xsl:stylesheet>