#! /usr/bin/env python

import rospy
from sensor_msgs.msg import LaserScan

def callback1(msg):
    print ("deg 80:", msg.ranges[280])
    print ("deg 90:", msg.ranges[360])
    print ("deg 110:", msg.ranges[440])

rospy.init_node('scan_values')
sub = rospy.Subscriber('/mybot/laser/scan_bottom', LaserScan, callback1)

rospy.spin()
