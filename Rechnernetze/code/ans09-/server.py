'''
@Author: Dongze Yang
@LastEditors: Dongze Yang
'''
import poplib
import email as e
from email.parser import Parser
from email.header import decode_header
from email.utils import parseaddr
import re
from email import message

def guess_charset(msg):
    charset = msg.get_charset()
    if charset is None:
        content_type = msg.get('Content-Type', '').lower()
        pos = content_type.find('charset=')
        if pos >= 0:
            charset = content_type[pos + 8:].strip()
    return charset

def print_info(msg, indent=0):
    if (msg.get_content_type() == 'multipart/signed'):
        
        parts = msg.get_payload()
        for n, part in enumerate(parts):
            print('%spart %s' % ('  ' * indent, n))
            print('%s--------------------' % ('  ' * indent))
            print_info(part, indent + 1)
    else:
        content_type = msg.get_content_type()
        if content_type=='text/plain' or content_type=='text/html':
            content = msg.get_payload(decode=True)
            charset = guess_charset(msg)
            if charset:
                content = content.decode(charset)
            print('%sText: %s' % ('  ' * indent, content + '...'))
        else:
            print('%sAttachment: %s' % ('  ' * indent, content_type))

email = 'doya'
password = '2080938ABc.'

pop3_server = 'mailbox.hrz.tu-chemnitz.de'

server = poplib.POP3_SSL(pop3_server)

server.user(email)
server.pass_(password)

resp, mails, octets = server.list()

index = len(mails)

Date = []
From = []
Sender = []
Reply_To = []
To = []
Subject = []
Text = []

for i in range(index,index-2,-1):

    resp, lines, octets = server.top(i,0)

    msg_content = b'\r\n'.join(lines).decode('utf-8')

    #print(msg_content)

    var_date = re.search(r'(?<=Date:)(.+)', str(msg_content))
    #print(var_date.group())
    Date.append(var_date)

    var_from = re.search(r'(?<=From:)(.+)', str(msg_content))
    From.append(var_from.group())

    var_sender = re.search(r'(^Sender:)(.+)', str(msg_content),re.M)
    #print(var_sender)
    if var_sender:
        Sender.append(var_sender)
    else:
        Sender.append('None')


    var_ReplyTo = re.search(r'(?<=Reply-To:)(.+)', str(msg_content))
    #print(var_from.group())
    Reply_To.append(var_ReplyTo)

    var_To = re.search(r'(^To:)(.+)', str(msg_content),re.M)
    #print(var_To.group())
    To.append(var_To)

    var_Subject = re.search(r'(^Subject:)(.+)', str(msg_content),re.M)
    #print(var_Subject.group())

    
    msg = Parser().parsestr(msg_content)
    
    content_type = msg.get_content_type()
    #print(content_type)
    
    print_info(msg,indent = 0)

server.quit()