#!/usr/bin/env python3

import rospy
from rospy_tutorials.srv import AddTwoInts

def handle_add_two_ints(req):
	result = req.a + req.b
	rospy.loginfo("Sum of " + str(req.a) + " and " + str(req.b) + " is " + str(result))
	return result

if __name__ == '__main__':
	# initialize the node
	rospy.init_node("add_two_ints_server")
	rospy.loginfo("Creating Add Two Ints Server")

	# initialize service
	# arguments: service name, service type, callback function called when request is made
	service = rospy.Service("/add_two_ints", AddTwoInts, handle_add_two_ints)
	rospy.loginfo("Service server has been started")

	# the following will keep the node running until termination command is given
	rospy.spin()