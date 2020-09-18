import serial
import socket
import sys
import time
import threading

BUFFER = 1024
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(("10.6.61.134", 86))
ser = serial.Serial("/dev/ttyUSB0", 115200)

def sock_to_ser():
    global sock, ser
    while True:
        data = sock.recv(BUFFER)
        print(b'[sock_to_ser]: ' + data)
        ser.write(data)

def ser_to_sock():
    global sock, ser
    while True:
        data = ser.read_all()
        if len(data) > 0:
            print(b'[ser_to_sock]: ' + data)
            sock.sendall(data)

sock_to_ser_thread = threading.Thread(target=sock_to_ser, daemon=True)
sock_to_ser_thread.start()
ser_to_sock_thread = threading.Thread(target=ser_to_sock, daemon=True)
ser_to_sock_thread.start()

sock_to_ser_thread.join()
ser_to_sock_thread.join()
