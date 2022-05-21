<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
    xmlns:xs="p3"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <html>
            <body>
                <h2>deliveries are sorted by price</h2>
                <hr />
                <table border="1">
                    <tr>
                        <th>name</th>
                        <th>article</th>
                        <th>price</th>
                        <th>supplier</th>
                    </tr>
                    <xsl:apply-templates select="xs:deliveries/xs:article">
                        <xsl:sort select="xs:price" data-type="number" order="descending" />
                    </xsl:apply-templates>
                </table>
            </body>
        </html>
    </xsl:template>

    <xsl:template match="xs:article">
        <tr>
            <td><xsl:value-of select="@id"/></td>
            <xsl:apply-templates/>
            <!-- 此处注意 -->
        </tr>
    </xsl:template>

    <xsl:template match="xs:price|xs:name|xs:supplier">
        <td>
            <xsl:apply-templates/>
            <!-- 此处两者等价 -->
            <!-- <xsl:value-of select="."/> -->
        </td>
    </xsl:template>

</xsl:stylesheet>