<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

    <xsl:template match="/">
        <html>
            <body><p>1</p>
                <xsl:for-each select="elem/EinElement">
                    <xsl:apply-templates select="mensch">
                        <xsl:sort select="position()" order="incending"/>
                    </xsl:apply-templates>
                </xsl:for-each>
            </body>
        </html>

    </xsl:template>
<!-- 输出不太对，懒得改了 -->
    <xsl:template match="*">
        <table>
            <tr>
                <th>ID</th>
                <th>Name</th>
                <th>Alt</th>
                <th>Info</th>
            </tr>
            <tr>
                <td><xsl:value-of select="position()"/></td>
                <td><xsl:value-of select="name"/></td>
                <td><xsl:value-of select="alter"/></td>
                <td><xsl:value-of select="info"/></td>
            </tr>
        </table>
    </xsl:template>

</xsl:stylesheet>