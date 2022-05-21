import socket

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = "localhost"
port = 8080

client.connect((host, port))


while 1:
    msg = input()
    client.send(msg.encode())
    count = client.recv(1024)
    print(count.decode())
    
