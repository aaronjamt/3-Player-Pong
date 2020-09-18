import socket, time

# b'\x28\x00', b'\x3A\x00', b'\x34\x00', b'\x11\x00', b'\x83\x00', b'\xC2\x00', b'\xC2\x00'
#     ASM({PRGM}{F1}{F1}
# b'\x07\x00', b'\x07\x00'
#     Exit, Exit
# b'\x06\x00'
#     Enter
keys = [b'\x28\x00', b'\x3A\x00', b'\x34\x00', b'\x11\x00', b'\x83\x00', b'\xC2\x00', b'\xC2\x00', b'\x07\x00', b'\x07\x00', b'\x06\x00']

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(("10.6.61.134", 86))

for key in keys:
    sock.sendall(b'\x06\x87'+key)
    time.sleep(0.2)
