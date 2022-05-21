<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
    xmlns:xs="p5"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <!-- //xs:article：从匹配条件的当节点选择文档中的节点，而不考虑位置。获取article节点。该键被应用到article节点 -->
    <!-- ./xs:supplier：article下的supplier作为键值 -->
    <xsl:key name="supplierlist" match="//xs:article" use="./xs:supplier" />
    <xsl:template match="/">
        <html>
            <head>
                <title>Deliveries</title>
            </head>
            <body bgcolor="#ffffff">
                <h1>Deliveries</h1>
                <hr />
                <!-- generate-id() = generate-id(key('supplierlist', ./xs:supplier))：以supplier进行归类 -->
                <xsl:for-each select="//xs:article[generate-id() = generate-id(key('supplierlist', ./xs:supplier))]">
                    <xsl:sort select="./xs:supplier" order="ascending" />
                    <!-- 将模板应用于supplier节点 -->
                    <xsl:apply-templates select="xs:supplier" />
                </xsl:for-each>
            </body>
        </html>
    </xsl:template>
    <!-- 为supplier创建模板 -->
    <xsl:template match="xs:supplier">
        <!-- 选取supplier节点，创建变量 -->
        <xsl:variable name="supplier_name" select="./text()" />
        <p>
            <xsl:value-of select="."/>
            <xsl:text> supplies: </xsl:text>
            <!-- 循环所有商品 -->
            <xsl:for-each select="//xs:article">
                <xsl:if test="xs:supplier/text() = $supplier_name">
                    <!-- 在效果上1和2基本无差别 -->
                    <!-- 1. 第一种存在的问题：语法上看着没有错
                                            针对name在xml文件从尾部插入重名元素时不去重，但是从xml文件的第二个位置插入重名元素可以去重  -->
                    <xsl:choose>
                        <!-- 从第一个开始循环 -->
                        <xsl:when test="count(preceding-sibling::xs:article) = 0">
                            <xsl:value-of select="xs:name"/>&#160;
                        </xsl:when>
                        <xsl:otherwise>
                            <xsl:if test="self::xs:article/xs:name != preceding-sibling::xs:article/xs:name">
                                <xsl:value-of select="xs:name"/>&#160;
                            </xsl:if>
                        </xsl:otherwise>
                    </xsl:choose>
                    <!-- 2. 对name不去重输出 -->
                    <!-- <xsl:value-of select="xs:name/text()"/> <xsl:text> </xsl:text> -->
                </xsl:if>
            </xsl:for-each>
        </p>
    </xsl:template>
</xsl:stylesheet>