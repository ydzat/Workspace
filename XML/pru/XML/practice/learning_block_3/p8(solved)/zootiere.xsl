<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
    xmlns="p8"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

    <!-- 模板输出 -->
    <!-- 知识点：
                1. xsl:variable 创建变量 此处应用于xml中非同类节点的合并 -->
    <xsl:template match="zoo">
        <html>
            <body>
                <h1><xsl:text>Dwellings in zoo</xsl:text><xsl:text>"</xsl:text><xsl:value-of select="@name" /><xsl:text>"</xsl:text></h1>
                <hr/>
                <xsl:apply-templates select="dwelling"/>
            </body>
        </html>
    </xsl:template>

    <xsl:template match="dwelling">
        <p>
            <xsl:value-of select="count(houses)"/>
            <xsl:text>animals live in </xsl:text>
            <xsl:value-of select="@name"/>
            <xsl:text>:</xsl:text>
            <xsl:apply-templates select="houses"/>
        </p>
    </xsl:template>

    <xsl:template match="houses">
        <xsl:variable name="this_animal" select="@animal" />
        <xsl:for-each select="//zoo_animal">
            <xsl:if test="@id=$this_animal">
                <xsl:value-of select="name"/>
                <xsl:text> (</xsl:text>
                <xsl:value-of select="@id"/>
                <xsl:text>) </xsl:text>
            </xsl:if>
        </xsl:for-each>
    </xsl:template>
</xsl:stylesheet>