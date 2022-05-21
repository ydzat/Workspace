<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
    xmlns:xs="p3"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <!-- 使用模板输出，模板非简化版 -->
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
                    <xsl:for-each select="xs:deliveries/xs:article">
                        <xsl:sort select="xs:price" data-type="number" order="descending" />
                        <tr>
                            <xsl:apply-templates select="@id" />
                            <xsl:apply-templates select="xs:name" />
                            <xsl:apply-templates select="xs:price" />
                            <xsl:apply-templates select="xs:supplier" />
                        </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>
    <xsl:template match="@id">
        <td>
            <xsl:value-of select="." />
            <!-- 此处注意 -->
        </td>
    </xsl:template>
    <xsl:template match="xs:name|xs:supplier">
        <td>
            <!-- <xsl:value-of select="." /> -->
            <xsl:apply-templates />
        </td>
    </xsl:template>
    <xsl:template match="xs:price">
        <td>
            <xsl:apply-templates />
            <!-- 此处两者等价 -->
            <!-- <xsl:value-of select="."/> -->
            <xsl:choose>
                <xsl:when test="@unitprice='true'">(per p)</xsl:when>
                <xsl:when test="@unitprice='false'">(per kg)</xsl:when>
                <xsl:otherwise>(N/A)</xsl:otherwise>
            </xsl:choose>
        </td>
    </xsl:template>
</xsl:stylesheet>