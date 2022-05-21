<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <!-- 模板输出 -->
    <!-- 知识点：
                1. 分类输出需要使用的部分
                    <xsl:key name="xxxlist" match="//xxxx" use="@xxxxx"/>：定义键
                    <xsl:for-each select="//xxxx[generate-id()=generate-id(key('xxxlist', @xxxxx))]">：形成分类
                    参数和变量的使用：用于判断进行分类
                    <xsl:variable name="this_xxxxx" select="@xxxxx"/>：创建变量
                    <xsl:with-param name="x" select="$this_xxxxx"：创建参数/>
                    <xsl:param name="x"/>：引用参数
                2. XPath的选取节点
                    .：选取当前节点
                    ..：选取当前节点的父节点
                    @：选取属性
                    /：从根节点选取
                    //：忽略位置，从匹配选择的当前节点选择文档中的节点-->
    <xsl:key name="prioritaetlist" match="//mail" use="@prioritaet"/>
    <xsl:template match="/">
        <html>
            <body>
                <xsl:for-each select="//mail[generate-id()=generate-id(key('prioritaetlist', @prioritaet))]">
                    <p>
                        <xsl:text>Emails Prioritaet</xsl:text>
                        <xsl:value-of select="@prioritaet"/>
                    </p>
                    <xsl:variable name="this_prioritaet" select="@prioritaet"/>
                    <xsl:call-template name="table">
                        <xsl:with-param name="id" select="$this_prioritaet"/>
                    </xsl:call-template>
                </xsl:for-each>
            </body>
        </html>
    </xsl:template>
    <xsl:template name="table">
        <xsl:param name="id"/>
        <table border="1">
            <tbody border="1">
                <tr>
                    <th>Inbox</th>
                    <th>Absender</th>
                    <th>Datum</th>
                    <th>Betreff</th>
                </tr>
                <xsl:apply-templates select="//mail[@prioritaet=$id]"/>
            </tbody>
        </table>
    </xsl:template>
    <xsl:template match="mail">
        <tr>
            <xsl:apply-templates select=".."/>
            <td>
                <xsl:value-of select="absender"/>
            </td>
            <td>
                <xsl:value-of select="datum"/>
            </td>
            <td>
                <xsl:value-of select="betreff"/>
            </td>
        </tr>
    </xsl:template>
    <xsl:template match="inbox">
        <td>
            <xsl:value-of select="@type"/>
        </td>
    </xsl:template>

</xsl:stylesheet>