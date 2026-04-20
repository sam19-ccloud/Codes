<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">

<html>
<head>
    <title>Student Data Table</title>
    <style>
        body {
            font-family: Arial;
            background-color: #f4f4f4;
        }
        h2 {
            text-align: center;
            color: #333;
        }
        table {
            border-collapse: collapse;
            width: 90%;
            margin: auto;
            background-color: white;
        }
        th {
            background-color: #4CAF50;
            color: white;
            padding: 10px;
        }
        td {
            padding: 8px;
            text-align: center;
        }
        tr:nth-child(even) {
            background-color: #f2f2f2;
        }
        tr:hover {
            background-color: #ddd;
        }
    </style>
</head>

<body>
    <h2>Student Data Table</h2>

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

        <xsl:for-each select="students/student">
        <tr>
            <td><xsl:value-of select="rollno"/></td>
            <td><xsl:value-of select="studentid"/></td>
            <td><xsl:value-of select="firstname"/></td>
            <td><xsl:value-of select="lastname"/></td>
            <td><xsl:value-of select="dob"/></td>
            <td><xsl:value-of select="gender"/></td>
            <td><xsl:value-of select="email"/></td>
            <td><xsl:value-of select="branch"/></td>
            <td><xsl:value-of select="division"/></td>
            <td><xsl:value-of select="year"/></td>
        </tr>
        </xsl:for-each>

    </table>
</body>

</html>

</xsl:template>
</xsl:stylesheet>