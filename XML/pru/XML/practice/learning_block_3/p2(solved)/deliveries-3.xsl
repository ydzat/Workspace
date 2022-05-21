<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
    xmlns:xs="p2"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <!-- 模板输出2 -->
    <!-- 注意点：为了简化模板引入，可以将模板设置在数据所在节点的父结点上 -->
    <xsl:template match="/">
        <html>
            <body>
                <h2>Deliveries</h2>
                <hr />
                <table border="1">
                    <tr>
                        <th>name</th>
                        <th>article</th>
                        <th>price</th>
                        <th>supplier</th>
                    </tr>
                    <xsl:apply-templates select="xs:deliveries/xs:article"/>
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
    <xsl:template match="xs:name|xs:price|xs:supplier">
        <td>
            <xsl:apply-templates/>
            <!-- 两者此处是等价的 -->
            <!-- <xsl:value-of select="."/> -->
        </td>
    </xsl:template>

</xsl:stylesheet>