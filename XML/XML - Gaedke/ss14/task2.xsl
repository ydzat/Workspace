<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

    <xsl:template match="/">
        <html>
            <meta http-equiv="cache-control" content="no-cache, no-store"></meta>
            <body>
               <xsl:call-template name="a" />
            </body>
        </html>
    </xsl:template>

    <xsl:template name="a" match="*//product">
        <p><xsl:value-of select="@name"/></p>
        <p><xsl:value-of select="harvest"/></p>
    </xsl:template>

    <!-- <xsl:template name="tdLab">
        <xsl:param name="v"/>
        <xsl:element name="td">
            <xsl:value-of select="$v"/>
        </xsl:element>
    </xsl:template> -->

</xsl:stylesheet>