<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
                xmlns:sc3="p1" 
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<!-- 直接从xml文档中读取数据输出 -->
<!-- 知识点：1. 命名空间的使用；2. XPath；3. xsl:value-of用于获取值  -->
<xsl:template match="/">
 <html>
 <body>
   <h2>Person</h2>
   <table border="1">
     <tr>
        <td>First Name:</td>
        <td><xsl:value-of select="sc3:form/sc3:firstName"/></td>
     </tr>
     <tr>
        <td>Family Name:</td>
        <td><xsl:value-of select="sc3:form/sc3:familyName"/></td>
     </tr>
     <tr>
        <td>PSNR:</td>
        <td><xsl:value-of select="sc3:form/sc3:psnr"/></td>
     </tr>
   </table>
 </body>
 </html>
</xsl:template>
</xsl:stylesheet>