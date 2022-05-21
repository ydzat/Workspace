import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = '25.150.140.133'
port = 8080

s.bind((host,port))
s.listen(1)

print("Server started")
stock = 1000

while True:
    conn, addr = s.accept()
    msg = conn.recv(1024)
    userRequest = msg.decode().split()
    if userRequest[1] == "/one":
        stock -= 1
    elif userRequest[1] == "/five":
        stock -= 5
    elif userRequest[1] == "/ten":
        stock -= 10
    answer = """HTTP/1.1 200 OK\n\n<html>
    <head>
        <style media="screen" type="text/css">
            table.abc {
                border: 2px solid black;
                border-style: solid;
                padding: 0;
                margin: 10;
    }
        </style>
        <meta charset="UTF-8">
    </head>
    <body>
        <table class="abc">
            <tr>
                <td>Shop<HR></td>
            </tr>
            <tr>
                <td action="http://25.150.140.133:8080">
                    <a href="http://25.150.140.133:8080/one">One piece</a><br />
                    <a href="http://25.150.140.133:8080/five">Five piece</a><br />
                    <a href="http://25.150.140.133:8080/ten">Ten piece</a>
                </td>
            </tr>
        </table>
        <table class="abc">
            <tr>
                <td>Remaining<hr></td>
            </tr>
            <tr>
                <td>Still"""+str(stock)+"""pieces.</td>
            </tr>
        </table>
    </body>
    </html>
    """
    conn.send(answer.encode())
conn.close()
s.close()