<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
    xmlns="p8"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

    <xsl:template match="/">
        <html>
            <body>
                <h1>Zoo keepers in zoo
                    <xsl:text> "vsr zoo" </xsl:text>
                </h1>
                <xsl:call-template name="zoo_keeper_name"/>

                <h2>Zoo keepers and animals</h2>
                <table border="1">
                    <tr>
                        <th>Name</th>
                        <th>Animal(s)</th>
                    </tr>
                    <xsl:apply-templates select="zoo/zoo_keeper"/>
                </table>
            </body>
        </html>
    </xsl:template>

    <xsl:template name="zoo_keeper_name">
        <p>
            <xsl:text>The zoo "vsr zoo" employs the followiing zoo keepers:</xsl:text>
        </p>

        <p>
            <ul>
                <xsl:for-each select="zoo/zoo_keeper">
                    <li><xsl:value-of select="@name"/></li>
                </xsl:for-each>
            </ul>
        </p>
    </xsl:template>

    <xsl:template match="zoo/zoo_keeper">
        <tr>
            <td>
                <xsl:value-of select="@name"/>
            </td>
            <td>
                <xsl:apply-templates/>
            </td>
        </tr>
    </xsl:template>

    <xsl:template match="zoo/zoo_keeper/cares_for">
        <xsl:apply-templates select="//zoo_animal[@id=current()/@animal]" />
    </xsl:template>

    <xsl:template match="zoo/zoo_animal">
        <xsl:apply-templates select="name"/>
        <xsl:text>(</xsl:text>
        <xsl:value-of select="@id"/>
        <xsl:text>)</xsl:text>
    </xsl:template>

    <xsl:template match="zoo/zoo_animal/name">
        <xsl:apply-templates/>
    </xsl:template>


</xsl:stylesheet>
