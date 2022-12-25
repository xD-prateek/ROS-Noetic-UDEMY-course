#!/usr/bin/env python3

import rospy
from std_msgs.msg import String

# creating a function to pass to subscriber node
def callback_recieve_radio_data(msg):
	rospy.loginfo("Message recieved: ")
	rospy.loginfo(msg)

if __name__ == '__main__':
	rospy.init_node('smartphone')

	# create a subscriber
	# arguments: topic name, topic type, the function to be performed using the topic data
	sub = rospy.Subscriber("/robot_news_radio", String, callback_recieve_radio_data)

	# spin will keep running the whole "smartphone" node code until it is stopped
	rospy.spin()