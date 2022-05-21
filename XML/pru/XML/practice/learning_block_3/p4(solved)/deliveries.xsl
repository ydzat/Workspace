<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
  xmlns:xs="p4"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <!-- 直接输出 -->
    <!-- 知识点：
                1. xsl:choose, xsl:when, xsl:otherwise的组合使用；
                2. 字符串的拼接使用内置函数concat()
                3. XPath的函数current() -->
    <!-- <xsl:variable name="delivery">
        <html>
            <body>
                <xsl:call-template name="show_more_information"/>
            </body>
        </html>
    </xsl:variable> -->
    <xsl:template name="show_more_information" match="/">
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
                <tr>
                    <td>
                        <xsl:value-of select="@id" />
                    </td>
                    <td>
                        <xsl:value-of select="xs:name" />
                    </td>
                    <xsl:choose>
                        <xsl:when test="xs:price/@unitprice='true'">
                            <td>
                                <xsl:value-of select="concat(current()/xs:price, '(per p)')" />
                            </td>
                        </xsl:when>
                        <xsl:when test="xs:price/@unitprice='false'">
                            <td>
                                <xsl:value-of select="concat(current()/xs:price, '(per kg)')" />
                            </td>
                        </xsl:when>
                        <xsl:otherwise>
                            <td>
                                <xsl:value-of select="concat(current()/xs:price, '(N/A)')" />
                            </td>
                        </xsl:otherwise>
                    </xsl:choose>
                    <td>
                        <xsl:value-of select="xs:supplier" />
                    </td>
                </tr>
            </xsl:for-each>
        </table>
    </xsl:template>
</xsl:stylesheet>