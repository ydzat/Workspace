<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <!-- 模板输出 -->
    <!-- 知识点：
               与16年考题一样-->
    <xsl:key name="valuelist" match="//article" use="@value" />

    <xsl:template match="/">
        <html>
            <body>
                <h1><xsl:text>Tool-Storage</xsl:text></h1>
                <hr/>
                <h2><xsl:text>stock sorted by value</xsl:text></h2>

                <xsl:for-each select="//article[generate-id()=generate-id(key('valuelist', @value))]">
                    <xsl:variable name="this_value" select="@value"/>
                    <xsl:call-template name="table">
                        <xsl:with-param name="id" select="$this_value"/>
                    </xsl:call-template>
                </xsl:for-each>

            </body>
        </html>
    </xsl:template>

    <xsl:template name="table">
        <xsl:param name="id"/>
        <h3><xsl:text>articles with the value </xsl:text><xsl:value-of select="$id"/></h3>
        <table border="1">
            <tbody>
                <tr>
                    <th>Article number</th>
                    <th>Name</th>
                    <th>Value</th>
                    <th>Condition</th>
                    <th>Comment</th>
                    <th>House</th>
                    <th>Shelf</th>
                </tr>
                <xsl:apply-templates select="//article[@value=$id]"/>
            </tbody>
        </table>
    </xsl:template>
    <xsl:template match="//article">
        <tr>
            <td><xsl:value-of select="@nr" /></td>
            <td><xsl:value-of select="@name" /></td>
            <td><xsl:value-of select="@value" /></td>
            <td><xsl:value-of select="@condition" /></td>
            <td>
                <xsl:choose>
                    <xsl:when test="not(./text())">
                        <xsl:text>keine</xsl:text>
                    </xsl:when>
                    <xsl:otherwise>
                        <xsl:value-of select="."/>
                    </xsl:otherwise>
                </xsl:choose>
            </td>
            <xsl:apply-templates select=".." />
        </tr>
    </xsl:template>
    <xsl:template match="shelf">
        <xsl:apply-templates select=".."/>
        <td><xsl:value-of select="@id"/></td>
    </xsl:template>
    <xsl:template match="house">
        <td><xsl:value-of select="@id"/></td>
    </xsl:template>
</xsl:stylesheet>