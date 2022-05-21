<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <!-- 模板输出 -->
    <!-- 知识点：
                1. position()获取节点的位置
                2. last()最后一个节点的位置-->
    <xsl:template match="zoo">
        <html>
            <body>
                <h1>
                    <xsl:text>Animal names in zoo "</xsl:text>
                    <xsl:value-of select="@name" />
                    <xsl:text>"</xsl:text>
                </h1>
                <hr/>
                <xsl:call-template name="zoo_animal_name"/>
            </body>
        </html>
    </xsl:template>
    <xsl:template name="zoo_animal_name">
        <p>
            <xsl:text>The animals in zoo "</xsl:text>
            <xsl:value-of select="@name"/>
            <xsl:text>" have the following names:</xsl:text>
        </p>
        <p>
            <xsl:for-each select="//zoo_animal">
                <xsl:choose>
                    <xsl:when test="position()=1">
                        <xsl:value-of select="name"/>
                    </xsl:when>
                    <xsl:when test="position()=last()">
                        <xsl:text> and </xsl:text>
                        <xsl:value-of select="name"/>
                    </xsl:when>
                    <xsl:otherwise>
                        <xsl:text>, </xsl:text>
                        <xsl:value-of select="name"/>
                    </xsl:otherwise>
                </xsl:choose>
            </xsl:for-each>
        </p>
    </xsl:template>
</xsl:stylesheet>