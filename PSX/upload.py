import serial
import sys
import time

if len(sys.argv) < 3:
    print("usage: pypsxserial.py <FILE_TO_UPLOAD.EXE> <SERIAL_PORT_DEVICE>\n")
    print("example port devices:\n   /dev/cu.usbserial (macOS - avoid tty.*)\n   /dev/ttyUSB0 (linux)\n   COM1 (windows)\n")
    quit(-1)

filename = sys.argv[1]
ttydevice = sys.argv[2]

try:
    filedata=open(filename,"rb").read()
    filelen=len(filedata)
    with serial.Serial(ttydevice,115200) as ser:
        print(f'using serial port: {ser.name}')
        print("sending start command 0x63...",end="")
        ser.write(b'\x63')
        print("done. reading response...")
        data=ser.read(1)
        print(f'response received: {data}')
        print("having a little nap...")
        time.sleep(1)
        print("sending header....",end="")
        ser.write(filedata[0:2048])
        print(",PC...",end="")
        ser.write(filedata[16:20])
        print(",writeaddr...",end="")
        ser.write(filedata[24:28])
        print(",writelen...")
        ser.write(filedata[28:32])
        print("now sending file contents:")
        chunks = (int)((filelen-(filelen%2048))/2048)
        for x in range(chunks):
            print(f'chunk: {x}')
            ser.write(filedata[(x+1)*2048:(x+2)*2048])
        print("writing remaining bytes")
        ser.write(filedata[(chunks*2048):(chunks*2048)+(filelen%2048)])
        print("sending close & execute command...")
        finalchunk = b''
        for x in range(2048):
            finalchunk += b'\xff'
        ser.write(finalchunk)
        print("done!")
        ser.close()
    time.sleep(2)
except KeyboardInterrupt:
    pass
