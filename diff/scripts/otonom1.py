#!/usr/bin/env python
# -*- coding: UTF-8 -*-

import rospy
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist

def Lidar_data(veri):
    bolgeler = {
        'sag' : min(min(veri.ranges[0:143]), 10),
        'on_sag' : min(min(veri.ranges[144:287]), 10),
        'on' : min(min(veri.ranges[288:431]), 10),
        'on_sol' : min(min(veri.ranges[432:575]), 10),
        'sol' : min(min(veri.ranges[0:143]), 30),
    }
    print(bolgeler)
    hareket(bolgeler)

def hareket(bolgeler):
    
    if (bolgeler['on'] > 0.7):
        rospy.loginfo('on>0.7')
        hiz = 0.4

        

    else:
        print('DUR')
        hiz = 0.0
        donus = 0.0

    obje.linear.x = hiz
    obje.angular.z = donus
    pub.publish(obje)

def sonlandir():
    rospy.loginfo('robot durduruldu')
    pub.publish(Twist()) #robotun durdurulmasÄ± iÃ§in boÅŸ twist deÄŸerleri gÃ¶nderir.

if __name__ == "__main__":
    rospy.init_node('otonom_bir', anonymous=True)
    rospy.Subscriber('/mybot/laser/scan', LaserScan, Lidar_data)

    rospy.loginfo('Sonlandirmak icin CTRL+C')
    rospy.on_shutdown(sonlandir)

    pub = rospy.Publisher('cmd_vel', Twist, queue_size=1)
    obje = Twist()
    
    rospy.spin()