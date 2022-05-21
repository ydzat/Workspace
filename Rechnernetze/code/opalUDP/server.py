'''
@Author: Dongze Yang
@LastEditors: Dongze Yang
'''

import sys,socket

if len(sys.argv) != 2:
        print ("Benutzung %s <port>" % sys.argv[0])
        sys.exit(1)
prog,port = sys.argv
try:
    n_port = int(port)
except:
    print ("%s ist kein gueltiger Port"%port)
    sys.exit(1)
try:
    s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
    s.bind(("", n_port))
    msg,adr = s.recvfrom(1000)
    print ("Empfange von Host %s, port %d: %s"%(adr[0], adr[1], msg))
    s.sendto("+++ " + msg + " +++", adr)
except:
    print ("Netzwerkfehler")
    sys.exit(1)