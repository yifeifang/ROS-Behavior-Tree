#! /usr/bin/env python
import rospy
from sensor_msgs.msg import LaserScan

def update_obstacle(data):
    print data.ranges[330]

rospy.init_node('laser_test')
sub = rospy.Subscriber("base_scan", LaserScan, update_obstacle)
rospy.spin()

