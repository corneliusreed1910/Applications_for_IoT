#  Eduardo Peinado
#  https://github.com/corneliusreed1910
#  Student number: 22073
#  TIADSM05A
#  Friday, October 24th, 2025
#  Subject: Applications for Internet of Things (AIoT)
#  ACT2_06: making a servo motor turn with HC-SR04 ultrasonic sensor and LEDs indicators 
#  Profe. Rocío del Carmen Martínez Luna
#  TIADSM (Tecnologías de la Información Área Desarrollo Software Multiplataforma)
#  Universidad Tecnológica Santa Catarina
#  Santa Catarina, Nuevo León, México

from machine import Pin, PWM
import time

# Pin definitions
reds    = [6, 7, 8]
yellows = [9, 10, 11]
greens  = [12, 13, 14]
blues   = [15, 16, 17]

motor_pin = 18
echo = Pin(4, Pin.IN)
trigger = Pin(5, Pin.OUT)

# Configure servo
servo = PWM(Pin(motor_pin))
servo.freq(50)

def servo_write(angle):
    # Convert angle (0–180) to duty_us (500–2500)
    duty = int(500 + (angle / 180) * 2000)
    servo.duty_u16(int(duty * 65535 / 20000))

# Configure LEDs
all_leds = []

for p in reds:
    led = Pin(p, Pin.OUT)
    all_leds.append(led)

for p in yellows:
    led = Pin(p, Pin.OUT)
    all_leds.append(led)

for p in greens:
    led = Pin(p, Pin.OUT)
    all_leds.append(led)

for p in blues:
    led = Pin(p, Pin.OUT)
    all_leds.append(led)

def clear_leds():
    for led in all_leds:
        led.low()

# Helper to turn on a full group
def group_on(group):
    for pin in group:
        Pin(pin, Pin.OUT).high()

# Distance measurement
def get_distance():
    trigger.low()
    time.sleep_us(2)
    trigger.high()
    time.sleep_us(10)
    trigger.low()

    pulse_time = time.ticks_us()
    while echo.value() == 0:
        if time.ticks_diff(time.ticks_us(), pulse_time) > 30000:
            return -1

    start = time.ticks_us()
    while echo.value() == 1:
        if time.ticks_diff(time.ticks_us(), start) > 30000:
            return -1

    end = time.ticks_us()
    duration = time.ticks_diff(end, start)
    distance = (duration * 0.034) / 2
    return distance


# Main loop
servo_write(0)

while True:
    dist = get_distance()
    print("Distance:", dist)

    clear_leds()

    if dist > 0 and dist < 10:
        group_on(reds)
        servo_write(180)

    elif dist >= 10 and dist < 20:
        group_on(yellows)
        servo_write(135)

    elif dist >= 20 and dist < 30:
        group_on(greens)
        servo_write(90)

    else:
        group_on(blues)
        servo_write(0)

    time.sleep(0.3)
