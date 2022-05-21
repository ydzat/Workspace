import socket
import urllib

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

HOST = "25.150.140.133"
Port = 8080

client.connect((HOST, Port))

msg = "GET /index.html HTTP/1.1"

client.send(msg.encode())

web = client.recv(1024)

print(web.decode())