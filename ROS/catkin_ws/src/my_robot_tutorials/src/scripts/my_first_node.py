#!/usr/bin/env python3
import rospy
if __name__ == '__main__':
	# initializing node name
	rospy.init_node('my_first_python_node')

	rospy.loginfo("This node has been started")

	# rospy.sleep(2)

	# rospy.loginfo("Exit now")

	rate = rospy.Rate(10)

	while not rospy.is_shutdown():
		rospy.loginfo("Hello")
		rate.sleep()