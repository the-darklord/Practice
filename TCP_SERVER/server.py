import socket as s

server=s.socket(s.AF_INET,s.SOCK_STREAM)

host=s.gethostname()
port=444

server.bind((host,port))

server.listen(3)

while True:
    client,address=server.accept()
    print("Connected to ",address)
    client.send("You are connected ".encode('ASCII'))
    client.close()