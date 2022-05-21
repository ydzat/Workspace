<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
>

<xsl:template match="/">
    <html>
        <meta http-equiv="cache-control" content="no-cache, no-store"></meta>
        <xsl:for-each select="article/text">
            <xsl:apply-templates select=".">
                <xsl:with-param name="sty" select="@style"/>
            </xsl:apply-templates>

            <br/>
        </xsl:for-each>
    </html>
</xsl:template>

<xsl:template match="//text">
    <xsl:param name="sty"/>
    <xsl:element name="{$sty}">
        <xsl:value-of select="."/>
    </xsl:element>
</xsl:template>


</xsl:stylesheet>