import base64

def encrypt_log(log_file_path):
    log_file = open(log_file_path, 'rb')
    data = log_file.read()
    encrypted_data = base64.b64encode(data)
    encrypted_file = open(log_file_path + ".enc", 'wb')
    encrypted_file.write(encrypted_data)
    encrypted_file.close()

def decrypt_log(log_file_path):
    encrypted_file = open(log_file_path, 'rb')
    encrypted_data = encrypted_file.read()
    decrypted_data = base64.b64decode(encrypted_data)
    print(decrypted_data)