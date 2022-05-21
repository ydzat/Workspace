'''
@Author: Dongze Yang
@LastEditors: Dongze Yang
'''

import socket
import ipaddress

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
HOST = 'localhost'
Port = 26718

#计算主机134.109.133.128/26所属网络
#26-8-8-8=2 -> 11111111.11111111.11111111.11000000 -> 255.255.255.192
#范围为128-191

valid_low = ipaddress.ip_address("134.109.133.128")
valid_high = ipaddress.ip_address("134.109.133.191")

server.bind((HOST, 26718))
server.listen(5)
while True:
    conn, addr = server.accept()
    usr = ipaddress.ip_address(addr[0])
    if ( valid_low <= usr <= valid_high):
        msg = 'Access granted' 
    else:
        msg = 'Access denied'
    conn.send(msg.encode())
    conn.close()
server.close()