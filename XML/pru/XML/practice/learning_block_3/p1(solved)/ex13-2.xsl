<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
    xmlns:sc3="p1"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <!-- 使用模板输出 -->
    <!-- 知识点：1. xsl:apply-templates和xsl:template使用和定义模板；2. <xsl:value-of select="." />和<xsl:apply-templates/>等价 -->
    <xsl:template match="/">
        <html>
            <body>
                <h2>Person</h2>
                <xsl:apply-templates />
            </body>
        </html>
    </xsl:template>
    <xsl:template match="sc3:form">
        <table border="1">
            <xsl:apply-templates select="sc3:firstName" />
            <xsl:apply-templates select="sc3:familyName" />
            <xsl:apply-templates select="sc3:psnr" />
        </table>
    </xsl:template>
    <xsl:template match="sc3:firstName">
        <tr>
            <td>First Name:</td>
            <td>
                <!-- <xsl:value-of select="." /> -->
                <!-- 两者在此处是等价的 -->
                <xsl:apply-templates/>
            </td>
        </tr>
    </xsl:template>
    <xsl:template match="sc3:familyName">
        <tr>
            <td>Family Name:</td>
            <td>
                <!-- <xsl:value-of select="." /> -->
                <!-- 两者在此处是等价的 -->
                <xsl:apply-templates/>
            </td>
        </tr>
    </xsl:template>
    <xsl:template match="sc3:psnr">
        <tr>
            <td>PSNR:</td>
            <td>
                <!-- <xsl:value-of select="." /> -->
                <!-- 两者在此处是等价的 -->
                <xsl:apply-templates/>
            </td>
        </tr>
    </xsl:template>
</xsl:stylesheet>