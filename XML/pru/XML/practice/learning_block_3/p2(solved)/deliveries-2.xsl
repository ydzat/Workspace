<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
    xmlns:xs="p2"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <!-- 使用模板输出 -->
    <!-- 知识点：1. 模板可以多重条件匹配（使用”|“表达同级或处理）避免重复定义模板 -->
    <!-- 注意点：1. <xsl:value-of select="." />和<xsl:apply-templates/>要理解后者的用法，不是简单的等价，
                   如果遇到属性就不能使用 -->
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
                    <xsl:for-each select="xs:deliveries/xs:article">
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
        </td>
    </xsl:template>
    <xsl:template match="xs:name|xs:price|xs:supplier">
        <td>
            <!-- <xsl:apply-templates/> -->
            <!-- 此处两者等价 -->
            <xsl:value-of select="." />
        </td>
    </xsl:template>
    <!-- 或者 -->
    <!-- <xsl:template match="@id|xs:name|xs:price|xs:supplier"> -->
        <!-- <td> -->
            <!-- <xsl:value-of select="." /> -->
            <!-- <xsl:apply-templates/> 此处是不对的-->
        <!-- </td> -->
    <!-- </xsl:template> -->
</xsl:stylesheet>