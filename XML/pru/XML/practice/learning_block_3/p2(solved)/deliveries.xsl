<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
  xmlns:xs="p2"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <!-- 直接输出 -->
  <!-- 知识点：1. xsl:for-each循环输出 -->
  <xsl:template match="/">
    <html>
      <body>
        <h2>Deliveries</h2>
        <hr />
        <table border="1">
          <tr>
            <th>name</th>
            <th>article</th>
            <th>price</th>
            <th>supplier</th>
          </tr>
          <xsl:for-each select="xs:deliveries/xs:article">
            <tr>
              <td>
                <xsl:value-of select="@id" />
              </td>
              <td>
                <xsl:value-of select="xs:name" />
              </td>
              <td>
                <xsl:value-of select="xs:price" />
              </td>
              <td>
                <xsl:value-of select="xs:supplier" />
              </td>
            </tr>
          </xsl:for-each>
        </table>
      </body>
    </html>
  </xsl:template>
</xsl:stylesheet>