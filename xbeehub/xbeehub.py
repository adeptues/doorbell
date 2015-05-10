#!/usr/bin/python

"""
Continuously read the serial port and process IO data received from a remote XBee.
"""

from xbee import XBee
import paho.mqtt.client as mqtt
import serial

#globals
broker = "192.168.0.10"
port = 1883
keepalive = 60


ser = serial.Serial('/dev/ttyUSB0', 9600)

#xbee = XBee(ser)



client = mqtt.Client()
#client.on_connect = on_connect
#client.on_message = on_message
client.connect(broker, port, keepalive)
# Continuously read and print packets
while True:
    try:
        #        response = xbee.wait_read_frame()
        respone = ser.read()
        print response
    except KeyboardInterrupt:
        break
        
ser.close()
client.disconnect()
