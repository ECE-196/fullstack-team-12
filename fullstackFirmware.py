from serial import Serial, SerialException

with Serial('COM5', 9600) as ser:
    ser.write(bytes([0x1]))
    assert ser.read() == bytes([0xaa])

    ser.write(bytes([0x0]))
    assert ser.read() == bytes([0xaa])

    ser.write(bytes([0x2]))
    assert ser.read() == bytes([0xff])