import socket

HOST = "25.150.140.133"
Port = 8080

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server.bind((HOST, Port))

server.listen(1)

conn, addr = server.accept()

print("Verbund mit: ", addr[0])

web = ("""HTTP/1.1 200 OK \n\n<!doctype html>
<html>
    <head><title>Hello</title></head>
    <body>
        <H2>Hello</H2>
        your IP address is: """+addr[0]+"""
    </body>
</html>
""" )

errweb = ("""HTTP/1.1 200 OK \n\n <!doctype html>
<html>
    <head><title>404</title></head>
    <body>Site not found on this server!</body>
</html>
""" )

while 1:
    data = conn.recv(1024)
    datasplit = data.decode().split()
    if ((datasplit[0] == "GET") and (datasplit[1] == "/" or datasplit[1] == "/index.html") and (datasplit[2] == "HTTP/1.1")):
        conn.send(web.encode())
        break
    else:
        conn.send(errweb.encode())
        break
conn.close()
server.close()
