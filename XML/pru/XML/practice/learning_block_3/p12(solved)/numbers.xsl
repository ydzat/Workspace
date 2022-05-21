<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <!-- 模板输出 -->
    <!-- 知识点：
            递归：使用参数设置初始值和递归结束条件 -->
    <xsl:template match="/">
        <html>
            <body>
                <h1><xsl:text>Numbers</xsl:text></h1>
                <hr/>
                <xsl:apply-templates select="//number"/>
            </body>
        </html>
    </xsl:template>
    <xsl:template match="number">
        <p>
            <xsl:variable name="this_number" select="@value" />
            <xsl:call-template name="for-loop">
                <xsl:with-param name="i" select="1"/>
                <xsl:with-param name="count" select="$this_number"/>
            </xsl:call-template>
        </p>
    </xsl:template>
    <xsl:template name="for-loop">
        <xsl:param name="i" />
        <xsl:param name="count" />
        <xsl:if test="$i &lt;= $count">
            <xsl:value-of select="$count"/>
            <xsl:text> </xsl:text>
            <xsl:call-template name="for-loop">
                <xsl:with-param name="i" select="$i + 1" />
                <xsl:with-param name="count" select="$count" />
            </xsl:call-template>
        </xsl:if>
    </xsl:template>
</xsl:stylesheet>