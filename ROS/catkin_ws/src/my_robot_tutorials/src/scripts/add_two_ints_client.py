#!/usr/bin/env python3

import rospy
from rospy_tutorials.srv import AddTwoInts

if __name__ == '__main__':
	rospy.init_node("add_two_ints_client")

	# we wait for service to start before calling for it; otherwise this will throw an error if service is not initialized
	rospy.wait_for_service("/add_two_ints")

	# creating client
	# if the client fails to call the client it will throw an exception.
	try:
		# creating a client using ServiceProxy with arguments:
		# name of topic, topic type
		add_two_ints = rospy.ServiceProxy("/add_two_ints", AddTwoInts)
		# calling the client and capturing the output
		response = add_two_ints(2,6)
		rospy.loginfo("Sum is: " + str(response.sum))

	except rospy.ServiceException as e:
		# catching the exception
		rospy.logwarn("Service failed: " + str(e))