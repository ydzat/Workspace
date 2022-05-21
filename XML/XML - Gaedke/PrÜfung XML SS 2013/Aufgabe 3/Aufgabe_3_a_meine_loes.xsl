<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">

  <xsl:template match="/">
    <table border="1">
      <tr>
        <th>Name</th><th>price</th><th>warehouse</th>
      </tr>
      <xsl:apply-templates select="warehouse"/>
    </table>
  </xsl:template>

  <xsl:template match="warehouse">
    <xsl:variable name="w_name" select="@name"/>
    <xsl:for-each select="Item">
      <tr>
        <td><xsl:value-of select="Name/text()"/></td>
        <td><xsl:value-of select="price/text()"/></td>
        <td><xsl:value-of select="$w_name"/></td>
      </tr>
    </xsl:for-each>
  </xsl:template>
</xsl:stylesheet>
