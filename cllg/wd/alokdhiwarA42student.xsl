<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">

<html>
<head>
    <title>Student Records</title>
    <style>
        body {
            font-family: Verdana;
            background: linear-gradient(to right, #667eea, #764ba2);
            color: #333;
        }

        h2 {
            text-align: center;
            color: white;
        }

        table {
            width: 95%;
            margin: 20px auto;
            border-collapse: collapse;
            background: white;
            border-radius: 10px;
            overflow: hidden;
        }

        th {
            background: #222;
            color: #fff;
            padding: 12px;
        }

        td {
            padding: 10px;
            text-align: center;
        }

        tr:nth-child(even) {
            background: #f9f9f9;
        }

        tr:hover {
            background: #dfe6e9;
        }
    </style>
</head>

<body>

<h2>College Student Records</h2>

<table border="1">
    <tr>
        <th>Roll No</th>
        <th>Student ID</th>
        <th>First Name</th>
        <th>Last Name</th>
        <th>DOB</th>
        <th>Gender</th>
        <th>Email</th>
        <th>Branch</th>
        <th>Division</th>
        <th>Year</th>
    </tr>

    <xsl:for-each select="college/record">
        <tr>
            <td><xsl:value-of select="roll"/></td>
            <td><xsl:value-of select="id"/></td>
            <td><xsl:value-of select="name/first"/></td>
            <td><xsl:value-of select="name/last"/></td>
            <td><xsl:value-of select="birthdate"/></td>
            <td><xsl:value-of select="gender"/></td>
            <td><xsl:value-of select="contact/email"/></td>
            <td><xsl:value-of select="academic/branch"/></td>
            <td><xsl:value-of select="academic/division"/></td>
            <td><xsl:value-of select="academic/year"/></td>
        </tr>
    </xsl:for-each>

</table>

</body>
</html>

</xsl:template>
</xsl:stylesheet>