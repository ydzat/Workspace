<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
>

<xsl:template match="/">

<html>
    <meta http-equiv="cache-control" content="no-cache, no-store"></meta>
    <body>
        <h1>Zoo keepers in zoo "vsr zoo"</h1>

        <p>The zoo "vsr zoo" employs the following zoo keepers:</p>
        <ul>
            <xsl:for-each select="zoo/zoo_keeper" >
                <li>
                    <xsl:value-of select="@name"/>
                </li>
            </xsl:for-each>
        </ul>

        <h2>Zoo keepers and animals</h2>

        <table border="1">
            <tr>
                <th>Name</th>
                <th>Animal(s)</th>
            </tr>
            <xsl:for-each select="zoo/zoo_keeper">
                <tr>
                    <td><xsl:value-of select="@name"/></td>
                    <td>
                        <xsl:for-each select="child::*">
                            <xsl:value-of select="./../../zoo_animal[@id = current()/@animal]/name"/>
                            (<xsl:value-of select="current()/@animal"/>)
                        </xsl:for-each>
                    </td>
                </tr>
            </xsl:for-each>
        </table>

    </body>
</html>
</xsl:template>
</xsl:stylesheet>