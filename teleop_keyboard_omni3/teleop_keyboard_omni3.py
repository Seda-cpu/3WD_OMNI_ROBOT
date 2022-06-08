#!/usr/bin/env python

from __future__ import print_function

import rospy

from std_msgs.msg import Float64

import sys, select, termios, tty

msg = """
Reading from the keyboard !
---------------------------
Moving around:
   u    i    o
   j    k    l
   m    ,    .

For Holonomic mode (strafing), hold down the shift key:
---------------------------
   U    I    O
   J    K    L
   M    <    >


anything else : stop

q/z : increase/decrease max speeds by 10%

CTRL-C to quit
"""

moveBindings = {
        'i':(0.5774,0,-0.5774), #ileri R, G, B
        'o':(0.3,-1,-1), 
        'j':(0.3333,-0.3333,0.3333), #sola eksenel
        'l':(-0.3333,0.3333,-0.3333), #saga eksenel
        'u':(1,1,0), #RG-1
        ',':(-0.5774,0,0.5774), #geri
        '.':(0,1,-1),
        'm':(1,-1,0),  
        'O':(-1,1,0),
        'I':(-1,0,1),
        'J':(1,2,1),
        'L':(-1,-2,-1),
        'U':(0,-1,1),
        '<':(1,0,-1),
        '>':(0,1,-1),
        'M':(1,-1,0),  
    }


speedBindings={
        'q':(1.1,1.1),
        'z':(.9,.9),
    }

def getKey():
    tty.setraw(sys.stdin.fileno())
    key = sys.stdin.read(1)
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key


def vels(speed):
    return "currently:\tspeed %s " % (speed)

if __name__=="__main__":
    settings = termios.tcgetattr(sys.stdin)

    rospy.init_node('vel_Publisher')
    publ = rospy.Publisher('/omni_bot/left_wheel_controller/command', Float64, queue_size=1)
    pubb = rospy.Publisher('/omni_bot/front_wheel_controller/command', Float64, queue_size=1)
    pubr = rospy.Publisher('/omni_bot/right_wheel_controller/command', Float64, queue_size=1)

    


    speed = 1.0
    x = 0
    y = 0
    z = 0
    status = 0

    try:
        print(msg)
        print(vels(speed))
        while(1):
            key = getKey()
            if key in moveBindings.keys():
                x = moveBindings[key][0]
                y = moveBindings[key][1]
                z = moveBindings[key][2]
            elif key in speedBindings.keys():
                speed = speed * speedBindings[key][0]
       
                print(vels(speed))
                if (status == 14):
                    print(msg)
                status = (status + 1) % 15
            else:
                x = 0
                y = 0
                z = 0
                th = 0
                if (key == '\x03'):
                    break
                
            vell = Float64()
            velb = Float64()
            velr = Float64()

            vell = x*speed
            velb = y*speed
            velr = z*speed

            publ.publish(vell)
            pubb.publish(velb)
            pubr.publish(velr)

    except Exception as e:
        print(e)

    finally:
        vell = Float64()
        velb = Float64()
        velr = Float64()

        vell = 0.0
        velb = 0.0
        velr = 0.0

        pubb.publish(vell)
        publ.publish(velb)
        pubr.publish(velr)

        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
