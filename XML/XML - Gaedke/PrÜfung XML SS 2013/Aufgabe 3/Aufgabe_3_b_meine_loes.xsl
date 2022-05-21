<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
  
  <xsl:template match="//warehouse">
    <xsl:variable name="W_name" select="@name"/>
    <xsl:for-each select="Item">
      <xsl:call-template name="doppelt">
        <xsl:with-param name="w_name" select="$W_name"/>
        <xsl:with-param name="Item_n" select="Name/text()"/>
      </xsl:call-template>
    </xsl:for-each>
  </xsl:template>
  
  <xsl:template name="doppelt">
    <xsl:param name="w_name"/>
    <xsl:param name="Item_n"/>
    <xsl:for-each select="//warehouse[not(@name = $w_name)]">
      <xsl:for-each select="Item[Name/text() = $Item_n]">
        <p><xsl:value-of select="Name/text()"/></p>
      </xsl:for-each>
    </xsl:for-each>
  </xsl:template>
  
</xsl:stylesheet>
