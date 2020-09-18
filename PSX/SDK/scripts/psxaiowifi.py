import socket
import sys
import time

if len(sys.argv) < 2:
    print("usage: pypsxserial.py <IPADDRESS> <FILE_TO_UPLOAD.EXE>\n")
    quit(-1)

addr = sys.argv[1]

if len(addr) == 0:
    print("usage: pypsxserial.py <IPADDRESS> <FILE_TO_UPLOAD.EXE>\n")
    quit(-1)

filename = sys.argv[2]

if len(filename) == 0:
    print("usage: pypsxserial.py <IPADDRESS> <FILE_TO_UPLOAD.EXE>\n")
    quit(-1)

sock = None

try:
#    input("Press enter to start upload.")
    print("Connecting to PSX...")
    filedata=open(filename,"rb").read()
    filelen=len(filedata)
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect((addr, 80))
    print("Connected.")
    print("Sending start command 0x63...",end="")
#    sock.sendall(b'\x63')
    print("done. receiving 1 byte from PSX...")
#    sock.recv(1)
    print("done. having a little nap...")
    time.sleep(1)
    print("sending header....",end="")
    sock.sendall(filedata[0:2048])
    print(",PC...",end="")
    sock.sendall(filedata[16:20])
    print(",writeaddr...",end="")
    sock.sendall(filedata[24:28])
    print(",writelen...")
    sock.sendall(filedata[28:32])
    print(f'now sending file contents ({filelen} bytes):')
    chunks = (int)((filelen-(filelen%2048))/2048)
    for x in range(chunks):
        print(f'chunk: {x} / {chunks}')
        sock.sendall(filedata[(x+1)*2048:(x+2)*2048])
        time.sleep(0.15)
    print("writing remaining bytes")
    sock.sendall(filedata[(chunks*2048):(chunks*2048)+(filelen%2048)])
    print("sending close & execute command...")
    finalchunk = b''
    for x in range(2048):
        finalchunk += b'\xff'
    sock.sendall(finalchunk)
    time.sleep(0.5)
    sock.sendall(finalchunk)
    print("done!")
finally:
    if sock:
        sock.close()
