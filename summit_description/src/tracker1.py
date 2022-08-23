#!/usr/bin/env python
import rospy
import roslib
from std_msgs.msg import Float32
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan 

class TwistToMotors():

    def __init__(self):
        rospy.init_node("twist_to_motors")
        nodename = rospy.get_name()
        rospy.loginfo("%s started" % nodename)
    
        self.pub = rospy.Publisher('/cmd_vel', Twist, queue_size=1)
        sub = rospy.Subscriber('/mybot/laser/scan_bottom', LaserScan, self.callback)
        self.rate = rospy.get_param("~rate", 50)
        self.l = 0
        self.r = 0
        self.mid = 0 
        self.twist = Twist()
        
    def spin(self):
    
        r = rospy.Rate(self.rate)
    
        ###### main loop  ######
        while not rospy.is_shutdown():
                self.spinOnce()
                r.sleep()

    def spinOnce(self):
   
        if self.r < self.l:
           self.twist.angular.z = -0.3 
           self.twist.linear.x = 0     
        if self.r > self.l:
           self.twist.angular.z = 0.3
           self.twist.linear.x = 0
        if abs(self.r-self.l) <= 0.04: #adjust angular tolerance here
           self.twist.angular.z = 0
           if self.mid > 0.27:         
              self.twist.linear.x = 0.2
          
             

        self.pub.publish(self.twist)
  

    def callback(self,msg):
        self.l = msg.ranges[440]
        print ("left: ",self.l)
        self.r = msg.ranges[280]
        print("right:",self.r)
        self.mid = msg.ranges[360]
        print("mid: ", self.mid)
        

if __name__ == '__main__':
    """ main """
    try:
        twistToMotors = TwistToMotors()
        twistToMotors.spin()
    except rospy.ROSInterruptException:
        pass
