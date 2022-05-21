'''
@Author: Dongze Yang
LastEditors: Dongze Yang
'''
import poplib
import socket
import re

def akt(client, web):
    
    lists = client.list()
    
    numOfmail = int(lists[0].decode().split()[1])
    data = ""
    
    for i in range(numOfmail,0,-1):

        resp, lines, octets = client.top(i,0)
        msg_content = b'\r\n'.join(lines).decode('utf-8')
        dateT = re.search(r'(^Date:)(.+)', str(msg_content),re.M)
        date.append(dateT.group(2).rstrip())
        betreffT = re.search(r'(^Subject:)(.+)', str(msg_content), re.M)
        betreff.append(betreffT.group(2).rstrip())
        senderT = re.search(r'(^From:)(.+)', str(msg_content), re.M)
        senderT = senderT.group(2).rstrip().replace('<','&lt;').replace('>','&gt;')
        sender.append(senderT)

    i = 0
    flag = 2
    for line in web.splitlines():
        i += 1
        data = data + line + '\n'
        if (i == 1):
            data = data + '\n\n'
        if (type(re.search("Sender", line)) == re.Match):
            data = data + "</tr>"
            for j in range(numOfmail):
                data = data + "<tr><td><a>" + date[j] + "</a></td><td><a href="">" + betreff[j] + "</a></td><td><a>" + sender[j] + "</a></td></tr><br/>\n"
                
            data = data + "</table></body></html>"
            break
    return data

date = []
betreff = []
sender = []

HOST = 'taurus.informatik.tu-chemnitz.de'
PORT = 110

sHost = 'localhost'
sPort = 8080

web = """HTTP/1.1 200 OK\n\n
<html>
    <head><h1>Webmailer Uebersicht</h1></head>
    <body>
        <table>
            <tr>
                <td action="http://localhost:8080">
                    <a href="http://localhost:8080/aktuallisieren">Aktuallisieren</a></br>
                    <a href="http://localhost:8080/beenden">Server beenden</a></br>
                </td>
            </tr>
            <tr>
                <td>Datum</td>
                <td>Betreff</td>
                <td>Sender</td>
            </tr>
            <tr>
                None
            </tr>
        </table>
    </body>
</html>
"""

client = poplib.POP3(HOST, PORT)
server = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server.bind((sHost, sPort))
server.listen(1)
client.user("rot\r\n")
client.pass_("rot\r\n")
conn, addr = server.accept()
web = akt(client,web)
conn.send(web.encode())
conn.close()

while 1:
    conn, addr = server.accept()
    msg = conn.recv(1024).decode().split()
    if (msg[1] == "/aktuallisieren"):
        web = akt(client, web)
    if(msg[1]=="beenden"):
        client.quit()
        conn.close()
        server.close()
        break
    conn.send(web.encode())
    conn.close()
client.quit()  #beendet die Verbindung
server.close()