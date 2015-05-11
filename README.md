#Doorbell

this project consists of the tools nessecary for thye doorbell project

HANNotfier is the android app for notifications from the home area network

xbee is the interface app from the computer to the xbee device

mqtt is the mqtt server config

for creating a linux/ubuntu client no need for complicated c++ app just write
a python script in init d which reads from mqtt and calls send-notify and then
plays a loud sound 

use the python scripts for protoypeing the idea then use qt c++ for desktop
client on all platforms with snore notify


## Android emulator netowork config TODO


##TODO list 

Make xbee broker python oop provide mappings from xbee codes to messages
create MessageResponse class which takes a code param in the constructor