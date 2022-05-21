<?xml version="1.0" encoding="UTF-8"?>
<!-- 模板输出 -->
<!-- 知识点：
            当非要使用模板而不能使用循环进行归类输出时，
                可以使用xsl:apply-templates明确需求的路径，
                xsl:with-param创建参数作为模板的标记以供模板输出时进行选择判断，
                xsl:param引入参数，xsl:choose/when/otherwise组合进行判断 
                .和..进行值输出的路径定位-->
<xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <html>
            <meta http-equiv="cache-control" content="no-cache, no-store"></meta>
            <body>
                <h1>Sorted Animals</h1>
                <h2>By name:</h2>
                <ul>
                    <xsl:apply-templates select="zoo/zoo_animal/name">
                        <xsl:with-param name="attr" select="'name'"/>
                        <xsl:sort data-type="text" order="ascending"/>
                    </xsl:apply-templates>
                </ul>
                <h2>By id:</h2>
                <ul>
                    <xsl:apply-templates select="zoo/zoo_animal[@id]/name">
                        <xsl:with-param name="attr" select="'id'"/>
                        <xsl:sort data-type="number" order="ascending"/>
                    </xsl:apply-templates>
                </ul>
                <h2>By age:</h2>
                <ul>
                    <xsl:apply-templates select="zoo/zoo_animal/age">
                        <xsl:with-param name="attr" select="'age'"/>
                        <xsl:sort data-type="number" order="ascending"/>
                    </xsl:apply-templates>
                </ul>
            </body>
        </html>
    </xsl:template>
    <xsl:template match="*" >
        <xsl:param name="attr"/>
        <li>
            <xsl:choose>
                <xsl:when test="$attr='name'">
                    <xsl:value-of select="."/>
                </xsl:when>
                <xsl:when test="$attr='id'">
                    <xsl:value-of select="."/>
                    (<xsl:value-of select="./../@id"/>)
                </xsl:when>
                <xsl:when test="$attr='age'">
                    <xsl:value-of select="./../name"/>
                    (<xsl:value-of select="."/>)
                </xsl:when>
            </xsl:choose>
        </li>      
    </xsl:template>
</xsl:stylesheet>