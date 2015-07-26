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
channel = "doorbell"

ser = serial.Serial('/dev/ttyUSB0', 9600)

def getMessage(code):
    #TODO make oop with message response class
    mappings = {0x1:"Doorbell: Some one is at the door"}
    response = mappings.get(code)
    return response
    
def doWork():
    client = mqtt.Client()
    #client.on_connect = on_connect
    #client.on_message = on_message
    client.connect(broker, port, keepalive)
    client.loop_start()
    # Continuously read and print packets
    #do sothing with the onpublish callback
    while True:
        try:
        #        response = xbee.wait_read_frame()
            response = ord(ser.read())
            message  = getMessage(response)
            print "response from xbee "+str(response)
            print "Sending message "+message
            client.publish(channel,message)

        except KeyboardInterrupt:
            break
            
    ser.close()
    client.disconnect()

print "starting xbeehub-mqtt hub"
doWork()




