<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
  xmlns:xs="p3"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <!-- 知识点：xsl:sort 进行排序，data-type限定需要排序的类型，默认为text；order限定排序的顺序，默认为ascending -->
  <xsl:template match="/">
    <html>
      <body>
        <h2>deliveries are sorted by price</h2>
        <hr />
        <table border="1">
          <tr>
            <th>name</th>
            <th>article</th>
            <th>price</th>
            <th>supplier</th>
          </tr>
          <xsl:for-each select="xs:deliveries/xs:article">
            <xsl:sort select="xs:price" data-type="number" order="descending" />
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