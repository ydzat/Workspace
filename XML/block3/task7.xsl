<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
>

<xsl:template match="/">

<html>
    <body>
        <h1>Animals in Zoo "vsr zoo"</h1>
    </body>

    <table border = "1">
        <tr>
            <th>Number.</th>    <!-- 为每个动物生成数字 -->
            <th>Animal</th>     <!--  -->
            <th>ID</th>         <!--  -->
            <th>Age</th>        <!--  -->
            <th>Gestation Period</th>   <!-- 若动物为mammel，则写其妊娠期，否则写N/A -->
            <th>Remarks</th>    <!-- 动物的特定信息：
                                        geese  -  slaughter weight;
                                        horses -  white or not
                                        cats   -  fur fur_color
                                        starlings - ringed or not -->
        </tr>
        <xsl:for-each select="zoo/zoo_animal">
            <tr>
                <td><xsl:value-of select="position()"/></td>
                <td><xsl:value-of select="name"/></td>
                <td><xsl:value-of select="@id"/></td>
                <td><xsl:value-of select="age"/></td>
                <td>
                    <xsl:choose>
                        <xsl:when test="gestation_period !=''">
                            <xsl:value-of select="gestation_period"/>
                        </xsl:when>
                        <xsl:otherwise>
                            N/A
                        </xsl:otherwise>
                    </xsl:choose>
                </td>
                <td>
                    <xsl:for-each select="@*">
                        <xsl:if test="name() != 'id' and name() != 'xsi:type'">
                            <xsl:value-of select="name()"/>:<xsl:value-of select="current()"/>&#160;
                        </xsl:if>
                    </xsl:for-each>
                    <xsl:for-each select="child::*">
                        <xsl:if test="name() != 'name' and name() != 'age' and name() != 'gestation_period'">
                            <xsl:value-of select="name()"/>:<xsl:value-of select="current()"/>&#160;
                        </xsl:if>
                    </xsl:for-each>
                </td>
            </tr>
        </xsl:for-each>


    </table>



</html>



</xsl:template>

</xsl:stylesheet>