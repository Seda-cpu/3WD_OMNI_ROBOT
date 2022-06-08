#!/usr/bin/env python
# -*- coding: UTF-8 -*-

import rospy
from sensor_msgs.msg import LaserScan

def func(veri):
    print(veri)

def sonlandir():
    rospy.loginfo('sonlandirildi.')

if __name__ == "__main__":
    rospy.init_node('lidar_verileri', anonymous=True)

    rospy.loginfo('Sonlandirmak icin ctrl+C')
    rospy.on_shutdown(sonlandir)

    rospy.Subscriber('/scan', LaserScan, func)
    rospy.spin()