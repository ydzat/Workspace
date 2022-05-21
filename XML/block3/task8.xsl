<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
>

<xsl:template match="/">

<html>
    <meta http-equiv="cache-control" content="no-cache, no-store"></meta>
    <body>
        <h1>Dwellings in zoo "vsr zoo"</h1>

        <p>
            <xsl:value-of select="count(zoo/zoo_animal[@id='animal1'])" />
            animals live in
            <xsl:value-of select="zoo/dwelling/houses[@animal='animal1']/../@name"/>:&#160;
            <xsl:for-each select="zoo/zoo_animal[@id='animal1']">
                <xsl:value-of select="name"/>('animal1')
            </xsl:for-each>
        </p>

        <p>
            <xsl:value-of select="count(zoo/zoo_animal[@id='animal2']) + count(zoo/zoo_animal[@id='animal3']) + count(zoo/zoo_animal[@id='animal4'])" />
            animals live in
            <xsl:value-of select="zoo/dwelling/houses[@animal='animal2']/../@name"/>:&#160;
            <xsl:for-each select="zoo/zoo_animal[@id='animal2' or @id='animal3' or @id='animal4']">
                <xsl:value-of select="name"/>(<xsl:value-of select="@id"/>)
            </xsl:for-each>
        </p>
        

    </body>
</html>

</xsl:template>
</xsl:stylesheet>