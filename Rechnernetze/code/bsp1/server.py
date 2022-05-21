import socket
import requests

#ipadr = requests.get('http://ifconfig.me/ip',timeout=1).text.strip()

server = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server.bind(('192.168.2.102',25565)) 
server.listen(5) 
while True:
    conn,addr = server.accept() 
    #print(conn,addr)
    
    data = conn.recv(1024) 
    print('recive:', data.decode())  
    
    data = 'server！'

    conn.send(data.encode())
    conn.close()
    print("server closed!")
    exit()