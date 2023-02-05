#!/usr/bin/env python3
import rospy
import roslib
from std_msgs.msg import Float32
from geometry_msgs.msg import Twist
from cmvision.msg import Blobs, Blob
from geometry_msgs.msg import PoseStamped
from sensor_msgs.msg import LaserScan 

#global
turn = 0.0 #turning rate
blob_position = 0 # x position for the blob
x = 0.0
z = 0.0

# callback function checks to see if any blobs were found then
# loop through each and get the x position.  Since the camera
# will sometimes find many blobs in the same object we just
# average all the x values.  You could also just take the first
# one if you are sure you will only have one blob. 
#
# This doesn't use multiple blobs but if are tracking several 
# objects you need to check the /data.blobs.color topic for
# the color tag you put in your colors.txt file. 
#
# after we have the x value we just make the robot turn to 
# keep it in the center of the image.

def callback(data):
    global turn
    global blob_position
    print (data)

    if(data):

                blob_position = data.pose.position.x
        
                rospy.loginfo("blob is at %s"%blob_position)
                # turn right if we set off the left cliff sensor
                if( blob_position > 0.14 ):
                    rospy.loginfo("TURN RIGHT")
                    turn = -0.2
                # turn left if we set off the right cliff sensor
                if( blob_position < 0.14 ):
                    rospy.loginfo("TURN LEFT")
                    turn = 0.2
        
                if( blob_position > 0.13 and blob_position < 0.14):
                    rospy.loginfo("CENTERED")
                    turn = 0.0
    else: 
        turn = 0.0

def laser_callback(msg):
    global x
    global z
    l = msg.ranges[440]
    r = msg.ranges[280]
    mid = msg.ranges[360]
    if mid > 0.27:
       x = 0.2
       if abs(mid - 0.27) <= 0.04:
          if r < l:
             z = -0.3
             x = 0
          if r > l:
             z = 0.3
             x = 0
          if abs(r - l) <= 0.02: #adjust angular tolerance here
             z = 0

def run():
    rospy.init_node("track_blob_color_node", log_level=rospy.WARN)
    global blob_position
    # publish twist messages to /cmd_vel
    pub = rospy.Publisher('/cmd_vel', Twist, queue_size=1)

    #subscribe to the robot sensor state
    rospy.Subscriber('/aruco_single/pose', PoseStamped, callback)
    rospy.Subscriber('/mybot/laser/scan_bottom', LaserScan, laser_callback)
    

    global turn
    global x
    global z
    twist = Twist()

    while not rospy.is_shutdown():

        # turn if we hit the line
        if ( turn != 0.0 or x != 0 or z !=0):
            str = "Turning %s"%turn
            rospy.loginfo(str)
            twist.linear.x = x; twist.linear.y = turn; twist.linear.z = 0
            twist.angular.x = 0; twist.angular.y = 0; twist.angular.z = z
            turn = 0.0

            # straight otherwise
        else:
            str = "Straight %s"%turn
            rospy.loginfo(str)
            twist.linear.x = 0.0; twist.linear.y = 0; twist.linear.z = 0
            twist.angular.x = 0; twist.angular.y = 0; twist.angular.z = 0

            # send the message and delay
        pub.publish(twist)
        blob_position = 0
        rospy.sleep(0.1)

if __name__ == '__main__':
    try:
        run()
    except rospy.ROSInterruptException: pass