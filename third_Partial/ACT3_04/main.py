#  Eduardo Peinado
#  https://github.com/corneliusreed1910
#  Student number: 22073
#  TIADSM05A
#  Friday, November 7th, 2025
#  Subject: Applications for Internet of Things (AIoT)
#  ACT3_04: conectivity protocols (Wi-Fi)
#  Profe. Rocío del Carmen Martínez Luna
#  TIADSM (Tecnologías de la Información Área Desarrollo Software Multiplataforma)
#  Universidad Tecnológica Santa Catarina
#  Santa Catarina, Nuevo León, México

import network
import socket
from machine import Pin
import time

# Define LED pins
red = Pin(12, Pin.OUT)
blue = Pin(13, Pin.OUT)
green = Pin(14, Pin.OUT)

# Wi-Fi credentials
ssid = 'KINGKONG9'
password = 'chupamelasbolas1987'

# Connect to Wi-Fi
wlan = network.WLAN(network.STA_IF)
wlan.active(True)
wlan.connect(ssid, password)

print("Connecting to Wi-Fi...")
while not wlan.isconnected() and wlan.status() >= 0:
    print(".", end="")
    time.sleep(1)

ip = wlan.ifconfig()[0]
print("\nConnected! IP:", ip)

# Generate web page
def web_page():
    state_r = "ON" if red.value() else "OFF"
    state_g = "ON" if green.value() else "OFF"
    state_b = "ON" if blue.value() else "OFF"

    html = f"""
    <!DOCTYPE html>
    <html>
    <head><title>Pico W LED Control</title></head>
    <body>
        <h1>Raspberry Pi Pico W LED Control</h1>
        <p>Red LED: {state_r}</p>
        <a href="/?red=on"><button>Red ON</button></a>
        <a href="/?red=off"><button>Red OFF</button></a>
        <p>Green LED: {state_g}</p>
        <a href="/?green=on"><button>Green ON</button></a>
        <a href="/?green=off"><button>Green OFF</button></a>
        <p>Blue LED: {state_b}</p>
        <a href="/?blue=on"><button>Blue ON</button></a>
        <a href="/?blue=off"><button>Blue OFF</button></a>
    </body>
    </html>
    """
    return html

# Start the web server
addr = socket.getaddrinfo('0.0.0.0', 80)[0][-1]
s = socket.socket()
s.bind(addr)
s.listen(1)
print('Web server running on http://%s' % ip)

# Main loop
while True:
    cl, addr = s.accept()
    print('Client connected from', addr)
    request = cl.recv(1024).decode()
    print('Request:', request)

    # Parse LED controls
    if '/?red=on' in request:
        red.value(1)
    if '/?red=off' in request:
        red.value(0)
    if '/?green=on' in request:
        green.value(1)
    if '/?green=off' in request:
        green.value(0)
    if '/?blue=on' in request:
        blue.value(1)
    if '/?blue=off' in request:
        blue.value(0)

    # Send updated page
    response = web_page()
    cl.send('HTTP/1.1 200 OK\n')
    cl.send('Content-Type: text/html\n')
    cl.send('Connection: close\n\n')
    cl.sendall(response)
    cl.close()
