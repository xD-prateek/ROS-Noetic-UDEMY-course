#!/usr/bin/env python3

import rospy
from std_msgs.msg import String #import the message type to be used

if __name__ == '__main__':

	# initialize the node with node name as argument
	rospy.init_node('robot_news_radio_transmitter', anonymous=False)

	# create a publisher
	# arguments: name of topic, type off topic, buffer size
	pub = rospy.Publisher("/robot_news_radio", String, queue_size=10)

	# create a rate to make the loop wait for the specified time
	rate = rospy.Rate(2)	

	while not rospy.is_shutdown(): # while shutdown command is not given
		# create the instance of the message type object
		msg = String()
		# put in the data
		msg.data = "Hi, this is Radio Mirchi!"
		# publish the data
		pub.publish(msg)
		# pause the loop
		rate.sleep()

	# print a message at the end of node
	rospy.loginfo("Node has stopped")