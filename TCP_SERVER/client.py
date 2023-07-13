import socket as s

client = s.socket(s.AF_INET,s.SOCK_STREAM)

host=s.gethostname()
port = 444

client.connect((host,port))

message=client.recv(1024)

client.close()

print(message.decode('ASCII'))