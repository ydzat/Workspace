<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
>

<xsl:template match="/">
    <html>
        <meta http-equiv="cache-control" content="no-cache, no-store"></meta>
        <body>
            <h1>Candidates and their points</h1>
            <hr/>
            
            <xsl:for-each select="//candidate">
                <p >
                    <div class="lab"><xsl:value-of select="name"/></div>
                    <div class="lab1" align="left">
                        <xsl:attribute name="style">
                            <xsl:text>width:</xsl:text>
                            <xsl:value-of select="points"/>
                            <xsl:text>px;background-color:blue;color:white;text-align:center;</xsl:text>
                        </xsl:attribute>
                        <xsl:value-of select="points"/>
                    </div>
                </p>
            </xsl:for-each>
            
        </body>
        <style>
            .lab{
                display: inline-block;
                width:60px;
            }
            .lab1{
                display: inline-block;
            }
        </style>
    </html>
</xsl:template>

</xsl:stylesheet>