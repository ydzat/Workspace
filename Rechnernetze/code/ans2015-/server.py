'''
@Author: Dongze Yang
@LastEditors: Dongze Yang
'''
import socket

def getNum(msg):
    if (msg in data.keys()):
        data[msg] = data[msg] + 1
        print(data[msg])
    else:
        data[msg] = 1
    return data[msg] 

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = 'localhost'
port = 8080

server.bind((host,port))

server.listen(1)

data = {}

conn, addr = server.accept()
while 1:
    msg = getNum(conn.recv(1024).decode())
    conn.send(str(msg).encode())
conn.close()


