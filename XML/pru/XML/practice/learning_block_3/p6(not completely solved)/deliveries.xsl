<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0"
    xmlns:xs="p6"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

    <!-- 直接输出 -->
    <!-- 知识点：
                1. XPath函数
                    count()计数
                2. XPath轴
                    preceding-sibiling 当前节点之前的所有同级节点
                    self 当前节点 -->
    <xsl:template match="/">
        <html>
            <body>
                <h1>Articles with same Name but different ID</h1>
                <p>The following pairs were found:</p>
                <hr />

                <!-- 归类name一样的article -->
                <xsl:for-each select="xs:deliveries/xs:article[xs:name='apple']">
                    <xsl:choose>
                        <!-- 判断是否第一次读取XML文件中具有该name的article -->
                        <xsl:when test="count(preceding-sibling::xs:article[xs:name='apple']) = 0">
                            <p>
                                Name1&#160;=&#160;<xsl:value-of select="xs:name"/>;
                                supplier1&#160;=&#160;<xsl:value-of select="xs:supplier"/>;
                                ID1&#160;=&#160;<xsl:value-of select="@id"/>;
                            </p>
                        </xsl:when>
                        <xsl:otherwise>
                            <!-- 判断读取的该同name的ariticle的id是否不同 -->
                            <xsl:if test="self::xs:article/@id != preceding-sibling::xs:article[xs:name='apple']/@id">
                                <p>
                                    <!-- 统计在此之前的同名个数来改变编号 -->
                                    Name<xsl:value-of select="count(preceding-sibling::xs:article[xs:name='apple']) + 1"/>&#160;=&#160;<xsl:value-of select="xs:name"/>;
                                    supplier<xsl:value-of select="count(preceding-sibling::xs:article[xs:name='apple']) + 1"/>&#160;=&#160;<xsl:value-of select="xs:supplier"/>;
                                    ID<xsl:value-of select="count(preceding-sibling::xs:article[xs:name='apple']) + 1"/>&#160;=&#160;<xsl:value-of select="@id"/>;
                                </p>
                            </xsl:if>
                        </xsl:otherwise>
                    </xsl:choose>
                </xsl:for-each>
                <xsl:for-each select="xs:deliveries/xs:article[xs:name='cherries']">
                    <xsl:choose>
                        <xsl:when test="count(preceding-sibling::xs:article[xs:name='cherries']) = 0">
                            <p>
                                Name1&#160;=&#160;<xsl:value-of select="xs:name"/>;
                                supplier1&#160;=&#160;<xsl:value-of select="xs:supplier"/>;
                                ID1&#160;=&#160;<xsl:value-of select="@id"/>;
                            </p>
                        </xsl:when>
                        <xsl:otherwise>
                            <xsl:if test="self::xs:article/@id != preceding-sibling::xs:article[xs:name='cherries']/@id">
                                <p>
                                    Name<xsl:value-of select="count(preceding-sibling::xs:article[xs:name='cherries']) + 1"/>&#160;=&#160;<xsl:value-of select="xs:name"/>;
                                    supplier<xsl:value-of select="count(preceding-sibling::xs:article[xs:name='cherries']) + 1"/>&#160;=&#160;<xsl:value-of select="xs:supplier"/>;
                                    ID<xsl:value-of select="count(preceding-sibling::xs:article[xs:name='cherries']) + 1"/>&#160;=&#160;<xsl:value-of select="@id"/>;
                                </p>
                            </xsl:if>
                        </xsl:otherwise>
                    </xsl:choose>  
                </xsl:for-each>
                <xsl:for-each select="xs:deliveries/xs:article[xs:name='cabbage']">
                    <xsl:choose>
                        <xsl:when test="count(preceding-sibling::xs:article[xs:name='cabbage']) = 0">
                            <p>
                                Name1&#160;=&#160;<xsl:value-of select="xs:name"/>;
                                supplier1&#160;=&#160;<xsl:value-of select="xs:supplier"/>;
                                ID1&#160;=&#160;<xsl:value-of select="@id"/>;
                            </p>
                        </xsl:when>
                        <xsl:otherwise>
                            <xsl:if test="self::xs:article/@id != preceding-sibling::xs:article[xs:name='cabbage']/@id">
                                <p>
                                    Name<xsl:value-of select="count(preceding-sibling::xs:article[xs:name='cabbage']) + 1"/>&#160;=&#160;<xsl:value-of select="xs:name"/>;
                                    supplier<xsl:value-of select="count(preceding-sibling::xs:article[xs:name='cabbage']) + 1"/>&#160;=&#160;<xsl:value-of select="xs:supplier"/>;
                                    ID<xsl:value-of select="count(preceding-sibling::xs:article[xs:name='cabbage']) + 1"/>&#160;=&#160;<xsl:value-of select="@id"/>;
                                </p>
                            </xsl:if>
                        </xsl:otherwise>
                    </xsl:choose>    
                </xsl:for-each>
                <xsl:for-each select="xs:deliveries/xs:article[xs:name='bananas']">
                    <xsl:choose>
                        <xsl:when test="count(preceding-sibling::xs:article[xs:name='bananas']) = 0">
                            <p>
                                Name1&#160;=&#160;<xsl:value-of select="xs:name"/>;
                                supplier1&#160;=&#160;<xsl:value-of select="xs:supplier"/>;
                                ID1&#160;=&#160;<xsl:value-of select="@id"/>;
                            </p>
                        </xsl:when>
                        <xsl:otherwise>
                            <xsl:if test="self::xs:article/@id != preceding-sibling::xs:article[xs:name='bananas']/@id">
                                <p>
                                    Name<xsl:value-of select="count(preceding-sibling::xs:article[xs:name='bananas']) + 1"/>&#160;=&#160;<xsl:value-of select="xs:name"/>;
                                    supplier<xsl:value-of select="count(preceding-sibling::xs:article[xs:name='bananas']) + 1"/>&#160;=&#160;<xsl:value-of select="xs:supplier"/>;
                                    ID<xsl:value-of select="count(preceding-sibling::xs:article[xs:name='bananas']) + 1"/>&#160;=&#160;<xsl:value-of select="@id"/>;
                                </p>
                            </xsl:if>
                        </xsl:otherwise>
                    </xsl:choose>   
                </xsl:for-each>
                <xsl:for-each select="xs:deliveries/xs:article[xs:name='pineapple']">
                    <xsl:choose>
                        <xsl:when test="count(preceding-sibling::xs:article[xs:name='pineapple']) = 0">
                            <p>
                                Name1&#160;=&#160;<xsl:value-of select="xs:name"/>;
                                supplier1&#160;=&#160;<xsl:value-of select="xs:supplier"/>;
                                ID1&#160;=&#160;<xsl:value-of select="@id"/>;
                            </p>
                        </xsl:when>
                        <xsl:otherwise>
                            <xsl:if test="self::xs:article/@id != preceding-sibling::xs:article[xs:name='pineapple']/@id">
                                <p>
                                    Name<xsl:value-of select="count(preceding-sibling::xs:article[xs:name='pineapple']) + 1"/>&#160;=&#160;<xsl:value-of select="xs:name"/>;
                                    supplier<xsl:value-of select="count(preceding-sibling::xs:article[xs:name='pineapple']) + 1"/>&#160;=&#160;<xsl:value-of select="xs:supplier"/>;
                                    ID<xsl:value-of select="count(preceding-sibling::xs:article[xs:name='pineapple']) + 1"/>&#160;=&#160;<xsl:value-of select="@id"/>;
                                </p>
                            </xsl:if>
                        </xsl:otherwise>
                    </xsl:choose>
                </xsl:for-each>                
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>