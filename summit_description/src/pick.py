#!/usr/bin/env python
import rospy
import roslib
import time
from std_msgs.msg import Float64
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan 

rospy.init_node("twist_to_mots")
i = 1

while not rospy.is_shutdown():
	pub0 = rospy.Publisher('/lib_bot/height_position_controller/command',Float64, queue_size=1)
	height = Float64()
	height.data = 0.08
	pub0.publish(height)
	i = i + 1
	time.sleep(1)
	pub2 = rospy.Publisher('/lib_bot/jaw_1_position_controller/command',Float64, queue_size=1)
	jaw1 = Float64()
	jaw1.data = 1
	pub2.publish(jaw1)
	i = i + 1
	pub3 = rospy.Publisher('/lib_bot/jaw_2_position_controller/command',Float64, queue_size=1)
	jaw2 = Float64()
	jaw2.data = -1
	pub3.publish(jaw2)
	i = i + 1
	time.sleep(1)
	pub1 = rospy.Publisher('/lib_bot/push_position_controller/command',Float64, queue_size=1)
	push = Float64()
	push.data = 1
	pub1.publish(push)
	i = i + 1
	time.sleep(3)
	pub2 = rospy.Publisher('/lib_bot/jaw_1_position_controller/command',Float64, queue_size=1)
	jaw1 = Float64()
	print (i)
	if i == 12:
	   jaw1.data = 0.03
	   pub2.publish(jaw1)
	   print ("jaw1")
	i = i + 1
	pub3 = rospy.Publisher('/lib_bot/jaw_2_position_controller/command',Float64, queue_size=1)
	jaw2 = Float64()
	print (i)
	if i == 13:
	   jaw2.data = -0.03
	   pub3.publish(jaw2)
	   print ("jaw2")
	i = i + 1
	time.sleep(3)
	pub1 = rospy.Publisher('/lib_bot/push_position_controller/command',Float64, queue_size=1)
	push = Float64()
	push.data = 0
	pub1.publish(push)
	i = i + 1
	if i == 15:
	   print (i)
	   break
	time.sleep(1)
	
	
	
