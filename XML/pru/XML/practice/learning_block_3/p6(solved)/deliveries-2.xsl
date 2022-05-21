<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
    xmlns:xs="p6"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

    <!-- 输出形式是对的，但是会重复输出 -->

    <xsl:template match="/">
        <html>
            <body bgcolor="#ffffff">
                <h1>Articles with same Name but different ID</h1>
                <p>The following pairs were found:</p>
                <hr />

                <xsl:for-each select="xs:deliveries/xs:article">
                    <xsl:apply-templates select="xs:name"/>
                </xsl:for-each>
            </body>
        </html>
    </xsl:template>

    <xsl:template match="xs:name">
        <xsl:variable name="article_name" select="./text()"/>
        <xsl:for-each select="//xs:article[xs:name=$article_name]">
            <xsl:choose>
                <!-- 判断是否第一次读取XML文件中具有该name的article -->
                <xsl:when test="count(preceding-sibling::xs:article[xs:name=$article_name]) = 0">
                    <p>
                        Name1&#160;=&#160;<xsl:value-of select="xs:name"/>;
                        supplier1&#160;=&#160;<xsl:value-of select="xs:supplier"/>;
                        ID1&#160;=&#160;<xsl:value-of select="@id"/>;
                    </p>
                </xsl:when>
                <!-- 判断读取的该同name的ariticle的id是否不同 -->
                <xsl:otherwise>
                    <xsl:if test="self::xs:article/@id != preceding-sibling::xs:article[xs:name=$article_name]/@id">
                        <p>
                            <!-- 统计在此之前的同名个数来改变编号 -->
                            Name<xsl:value-of select="count(preceding-sibling::xs:article[xs:name=$article_name]) + 1"/>&#160;=&#160;<xsl:value-of select="xs:name"/>;
                            supplier<xsl:value-of select="count(preceding-sibling::xs:article[xs:name=$article_name]) + 1"/>&#160;=&#160;<xsl:value-of select="xs:supplier"/>;
                            ID<xsl:value-of select="count(preceding-sibling::xs:article[xs:name=$article_name]) + 1"/>&#160;=&#160;<xsl:value-of select="@id"/>;
                        </p>
                    </xsl:if>
                </xsl:otherwise>
            </xsl:choose>
        </xsl:for-each>
    </xsl:template>
        
</xsl:stylesheet>

<!-- <?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
    xmlns:xs="p6"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

    <xsl:template match="/">
        <html>
            <body bgcolor="#ffffff">
                <h1>Articles with same Name but different ID</h1>
                <p>The following pairs were found:</p>
                <hr />
                <xsl:apply-templates />
            </body>
        </html>
    </xsl:template>

    <xsl:template match="xs:article">
        <xsl:variable name="article_name" select="xs:name/text()"/>
        <xsl:for-each select="//xs:article">
            <xsl:choose>
                <xsl:when test="count(preceding-sibling::xs:article[xs:name=$article_name]) = 0">
                    <p>
                        Name1&#160;=&#160;<xsl:value-of select="xs:name"/>;
                        supplier1&#160;=&#160;<xsl:value-of select="xs:supplier"/>;
                        ID1&#160;=&#160;<xsl:value-of select="@id"/>;
                    </p>
                </xsl:when>
                <xsl:otherwise>
                    <xsl:if test="self::xs:article/@id != preceding-sibling::xs:article[xs:name=$article_name]/@id">
                        <p>
                            Name<xsl:value-of select="count(preceding-sibling::xs:article[xs:name=$article_name]) + 1"/>&#160;=&#160;<xsl:value-of select="xs:name"/>;
                            supplier<xsl:value-of select="count(preceding-sibling::xs:article[xs:name=$article_name]) + 1"/>&#160;=&#160;<xsl:value-of select="xs:supplier"/>;
                            ID<xsl:value-of select="count(preceding-sibling::xs:article[xs:name=$article_name]) + 1"/>&#160;=&#160;<xsl:value-of select="@id"/>;
                        </p>
                    </xsl:if>
                </xsl:otherwise>
            </xsl:choose>
        </xsl:for-each>
    </xsl:template>
        
</xsl:stylesheet> -->