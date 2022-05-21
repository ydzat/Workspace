<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
>

<xsl:template match="/">
\documentclass{article}
\usepackage[utf-8]{inputenc}
\usepackage{ngerman}
\pagestyle{empty}
\begin{document}
\begin{tabular}{|c|c|c|c|}
\hline
<xsl:for-each select="table/row">
    <xsl:for-each select="column">
        <xsl:if test="position() &lt; 4">
            <xsl:value-of select="."/>
            <xsl:text disable-output-escaping="yes"><![CDATA[&]]></xsl:text>
        </xsl:if>
        <xsl:if test="position() = 4">
            <xsl:value-of select="."/><xsl:text>\\ \hline </xsl:text>
        </xsl:if>
    </xsl:for-each>
</xsl:for-each>
\end{tabular}
\end{document}
</xsl:template>
</xsl:stylesheet>