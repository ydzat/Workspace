'''
@Author: Dongze Yang
@LastEditors: Dongze Yang
'''
import socket
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
HOST = '134.109.133.128'
client.connect((HOST, 26718))
data = client.recv(1024)
print(data.decode())
client.close()