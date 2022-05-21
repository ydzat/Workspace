<?xml version="1.0" encoding="UTF-8"?>

<!-- 解决的问题：从xml文件的第一个元素开始读取 -->
<!-- 存在的问题：对于supplier没有实际去重，而是手动进行分类输出；对于name在xml文件从尾部插入重名元素时不去重，但是从xml文件的第二个位置插入重名元素可以去重  -->
<xsl:stylesheet version="1.0"
    xmlns:xs="p5"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

    <xsl:template match="/">
        <html>
            <meta http-equiv="cache-control" content="no-cache, no-store"></meta>
            <body>
                <h1>Supplier</h1>
                
                <p>Krause Inc. supplies:
                    <xsl:for-each select="xs:deliveries/xs:article[xs:supplier='Krause Inc.']">
                        <xsl:choose>
                            <xsl:when test="count(preceding-sibling::xs:article) = 0">
                                <xsl:value-of select="xs:name"/>&#160;
                            </xsl:when>
                            <xsl:otherwise>
                                <xsl:if test=" self::xs:article/xs:name != preceding-sibling::xs:article/xs:name">
                                    <xsl:value-of select="xs:name"/>&#160;
                                </xsl:if>
                            </xsl:otherwise>
                        </xsl:choose>
                    </xsl:for-each>
                </p>

                <p>Helbig Inc. supplies:
                    <xsl:for-each select="xs:deliveries/xs:article[xs:supplier='Helbig Inc.']">
                        <xsl:choose>
                            <xsl:when test="count(preceding-sibling::xs:article) = 0">
                                <xsl:value-of select="xs:name"/>&#160;
                            </xsl:when>
                            <xsl:otherwise>
                                <xsl:if test=" self::xs:article/xs:name != preceding-sibling::xs:article/xs:name">
                                    <xsl:value-of select="xs:name"/>&#160;
                                </xsl:if>
                            </xsl:otherwise>
                        </xsl:choose>
                    </xsl:for-each>
                </p>

                <p>Liebig Inc. supplies:
                    <xsl:for-each select="xs:deliveries/xs:article[xs:supplier='Liebig Inc.']">
                        <xsl:choose>
                            <xsl:when test="count(preceding-sibling::xs:article) = 0">
                                <xsl:value-of select="xs:name"/>&#160;
                            </xsl:when>
                            <xsl:otherwise>
                                <xsl:if test=" self::xs:article/xs:name != preceding-sibling::xs:article/xs:name">
                                    <xsl:value-of select="xs:name"/>&#160;
                                </xsl:if>
                            </xsl:otherwise>
                        </xsl:choose>
                    </xsl:for-each>
                </p>

                <p>Mertes Inc. supplies:
                    <xsl:for-each select="xs:deliveries/xs:article[xs:supplier='Mertes Inc.']">
                        <xsl:choose>
                            <xsl:when test="count(preceding-sibling::xs:article) = 0">
                                <xsl:value-of select="xs:name"/>&#160;
                            </xsl:when>
                            <xsl:otherwise>
                                <xsl:if test=" self::xs:article/xs:name != preceding-sibling::xs:article/xs:name">
                                    <xsl:value-of select="xs:name"/>&#160;
                                </xsl:if>
                            </xsl:otherwise>
                        </xsl:choose>
                    </xsl:for-each>
                </p>

                <p>Hoeller Inc. supplies:
                    <xsl:for-each select="xs:deliveries/xs:article[xs:supplier='Hoeller Inc.']">
                        <xsl:choose>
                            <xsl:when test="count(preceding-sibling::xs:article) = 0">
                                <xsl:value-of select="xs:name"/>&#160;
                            </xsl:when>
                            <xsl:otherwise>
                                <xsl:if test=" self::xs:article/xs:name != preceding-sibling::xs:article/xs:name">
                                    <xsl:value-of select="xs:name"/>&#160;
                                </xsl:if>
                            </xsl:otherwise>
                        </xsl:choose>
                    </xsl:for-each>
                </p>

                <p>Richard Inc. supplies:
                    <xsl:for-each select="xs:deliveries/xs:article[xs:supplier='Richard Inc.']">
                        <xsl:choose>
                            <xsl:when test="count(preceding-sibling::xs:article) = 0">
                                <xsl:value-of select="xs:name"/>&#160;
                            </xsl:when>
                            <xsl:otherwise>
                                <xsl:if test=" self::xs:article/xs:name != preceding-sibling::xs:article/xs:name">
                                    <xsl:value-of select="xs:name"/>&#160;
                                </xsl:if>
                            </xsl:otherwise>
                        </xsl:choose>
                    </xsl:for-each>
                </p>

                <p>Reinhardt Inc. supplies:
                    <xsl:for-each select="xs:deliveries/xs:article[xs:supplier='Reinhardt Inc.']">
                        <xsl:choose>
                            <xsl:when test="count(preceding-sibling::xs:article) = 0">
                                <xsl:value-of select="xs:name"/>&#160;
                            </xsl:when>
                            <xsl:otherwise>
                                <xsl:if test=" self::xs:article/xs:name != preceding-sibling::xs:article/xs:name">
                                    <xsl:value-of select="xs:name"/>&#160;
                                </xsl:if>
                            </xsl:otherwise>
                        </xsl:choose>
                    </xsl:for-each>
                </p>
                
            </body>
        </html>
    </xsl:template>

    

</xsl:stylesheet>