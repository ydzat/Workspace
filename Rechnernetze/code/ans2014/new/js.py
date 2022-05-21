'''
@Author: Dongze Yang
@LastEditors: Dongze Yang
'''
import socket
import re

path="C:\\Users\\ydzat\\OneDrive\\Workspace\\Rechnernetze\\code\\ans2014\\new\\index.html"

f = open(path,'r+')
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = '25.150.140.133'
port = 8080

s.bind((host,port))
s.listen(1)

stock = 0

for line in f.readlines():
    da = re.search(r'Still (\d+)', line, re.M)
    if (type(da) == re.Match ):
        stock = da.group(1)
        break
    
while True:
    data = ''
    conn, addr = s.accept()
    msg = conn.recv(1024)
    userRequest = msg.decode().split()
    if userRequest[1] == "/one":
        stock = int(stock) - 1
    elif userRequest[1] == "/five":
        stock = int(stock) - 5
    elif userRequest[1] == "/ten":
        stock = int(stock) - 10
    f.seek(0, 0)
    for line in f.readlines():
        if (type(re.search(r'Still (\d+)', line, re.M))==re.Match):
            line = 'Still ' + str(stock) + " pieces\n" 
        data += line
    data = "\"\"\"HTTP/1.1200OK\n\n"+ data
    #print(data)
    #f.seek(0,0)
    #f.writelines(data)
    conn.send(data.encode())
    conn.close()
    
conn.close()
s.close()