<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0"
    xmlns:xs="urn:myspace:deliveries"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
>

<xsl:template match="/">
    <html>
        <body>
            <h1>Articles with same Name but different ID</h1>
            <p>The following pairs were found:</p>

            
            <xsl:for-each select="xs:deliveries/xs:article[xs:name='apple']">
                <xsl:choose>
                    <xsl:when test="count(preceding-sibling::xs:article[xs:name='apple']) = 0">
                        <p>
                            Name1&#160;=&#160;<xsl:value-of select="xs:name"/>;
                            supplier1&#160;=&#160;<xsl:value-of select="xs:supplier"/>;
                            ID1&#160;=&#160;<xsl:value-of select="@id"/>;
                        </p>
                    </xsl:when>
                    <xsl:otherwise>
                        <xsl:if test="self::xs:article/@id != preceding-sibling::xs:article[xs:name='apple']/@id">
                            <p>
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