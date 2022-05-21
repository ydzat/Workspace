<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

    <xsl:template match="/">
        <html>
            <body>
                <p>E-mails Prioritaet 1</p>
                <div> 
                    <table>
                        <tr>
                            <th>Inbox</th>
                            <th>Absender</th>
                            <th>Datum</th>
                            <th>Betreff</th>
                        </tr>
                        <xsl:for-each select="//mail">
                            <xsl:if test="@prioritaet = 1">
                                <tr>
                                    <xsl:apply-templates select=".">
                                        <!-- <xsl:with-param name="p" select=".//@prioritaet"/> -->
                                        <!-- <xsl:sort data-type="number" order="incending"/> -->
                                    </xsl:apply-templates>
                                </tr>
                            </xsl:if>
                        </xsl:for-each>
                    </table>
                </div>
                <p>E-mails Prioritaet 2</p>
                <div> 
                    <table>
                        <tr>
                            <th>Inbox</th>
                            <th>Absender</th>
                            <th>Datum</th>
                            <th>Betreff</th>
                        </tr>
                        <xsl:for-each select="//mail">
                            <xsl:if test="@prioritaet = 2">
                                <tr>
                                    <xsl:apply-templates select=".">
                                        <!-- <xsl:with-param name="p" select=".//@prioritaet"/> -->
                                        <!-- <xsl:sort data-type="number" order="incending"/> -->
                                    </xsl:apply-templates>
                                </tr>
                            </xsl:if>
                        </xsl:for-each>
                    </table>
                </div>
            </body>
        </html>

    </xsl:template>

    <xsl:template match="*">
        <td><xsl:value-of select="./../@type"/></td>
        <td><xsl:value-of select="absender"/></td>
        <td><xsl:value-of select="datum"/></td>
        <td><xsl:value-of select="betreff"/></td>
    </xsl:template>
</xsl:stylesheet>