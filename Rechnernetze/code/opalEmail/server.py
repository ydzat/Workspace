'''
@Author: Dongze Yang
@LastEditors: Dongze Yang
'''
import socket
import re

def auth(conn,usr = ""):
    
    #验证用户名，密码
    while 1:
        data = conn.recv(1024).decode()
        usr = re.search(r'(^USER)(.+)', str(msg_content),re.M)
        passw = re.search(r'(^PASS)(.+)', str(msg_content),re.M)
        if (usr not in reg.keys):
            print("der Benutzername existiert nicht, bitte erneue eingeben")
        else:
            if (reg[usr] == passw):
                return true
            if (auth(conn, usr)):
                print("Die Authentifizierung ist erfolgreich")
                return true
            else:
                print("Authentifizierung fehlgeschlagen")


reg = {"doya":"208093."}

server = server.socket(socket.AF_INET, socket.SOCK_STREAM)

HOST = '25.150.140.133'
PORT = 110

version = "v1.0"

server.bind((HOST, PORT))

server.listen(5)

while 1:
    conn, addr = server.accept()
    
    welcome = "+OK POP3 " + HOST + " " + version + " ready"
    
    conn.send(welcome.encode())
    
    auth(conn)
        
    print("Hier")

    conn.close()
server.close()

    
