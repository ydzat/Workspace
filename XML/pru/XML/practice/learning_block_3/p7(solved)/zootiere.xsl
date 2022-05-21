<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
    xmlns="p7"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <!-- 使用模板输出 -->
    <!-- 知识点：
                1. XPath函数not()，用于判断是否有某节点
                2. 简化模板输出不仅可以用在xsl:template还可以用在xsl:apply-templates上，select的表达式使用|-->
    <xsl:template match="zoo">
        <html>
            <body>
                <h1><xsl:text>Animals in zoo</xsl:text><xsl:text>"</xsl:text><xsl:value-of select="@name" /><xsl:text>"</xsl:text></h1>
                <hr/>
                <table border="1"> 
                    <tbody>
                        <tr>
                            <th>Number</th>
                            <th>Animal</th>
                            <th>ID</th>
                            <th>Age</th>
                            <th>Gestation Period</th>
                            <th>Remarks</th>
                        </tr>
                        <xsl:apply-templates select="zoo_animal"/>
                    </tbody>
                </table>
            </body>
        </html>
    </xsl:template>
    <xsl:template match="zoo_animal">
        <tr>
            <td>
                <xsl:number count="zoo_animal"/>
            </td>
            <td>
                <xsl:value-of select="name"/>
            </td>
            <td>
                <xsl:value-of select="@id"/>
            </td>
            <td>
                <xsl:value-of select="age"/>
            </td>
            <td>
                <xsl:choose>
                    <xsl:when test="not(gestation_period)">
                        <xsl:text>(N/A)</xsl:text>
                    </xsl:when>
                    <xsl:otherwise>
                        <xsl:value-of select="gestation_period"/>
                    </xsl:otherwise>
                </xsl:choose>
            </td>
            <xsl:if test="@white_horse">
                <td>
                    <xsl:choose>
                    <xsl:when test="@white_horse='true'">
                        <xsl:text>White Horse</xsl:text>
                    </xsl:when>
                    <xsl:otherwise>
                        <xsl:text>No White Horse</xsl:text>
                    </xsl:otherwise>
                </xsl:choose>
                </td>
            </xsl:if>
            <xsl:if test="@ringed">
                <td>
                    <xsl:choose>
                    <xsl:when test="@ringed='true'">
                        <xsl:text>ringed</xsl:text>
                    </xsl:when>
                    <xsl:otherwise>
                        <xsl:text>not ringed</xsl:text>
                    </xsl:otherwise>
                </xsl:choose>
                </td>
            </xsl:if>
            <xsl:apply-templates select="fur_color|slaughter_weight" />
        </tr>
    </xsl:template>
    <xsl:template match="fur_color">
        <td>
            <xsl:value-of select="." />
        </td>
    </xsl:template>
    <xsl:template match="slaughter_weight">
        <td>
            <xsl:text>Slaughter Weight::</xsl:text>
            <xsl:value-of select="." />
            <xsl:text>g</xsl:text>
        </td>
    </xsl:template>
</xsl:stylesheet>