#include <ros/ros.h>
#include <rospy_tutorials/AddTwoInts.h>

int main(int argc, char **argv) {

	ros::init(argc, argv, "add_two_ints_client");
	ros::NodeHandle nh;

	// create a ServiceClient object.
	// Arguments: service name
	ros::ServiceClient client = nh.serviceClient<rospy_tutorials::AddTwoInts>("/add_two_ints");

	rospy_tutorials::AddTwoInts srv;
	srv.request.a = 12;
	srv.request.b = 5;

	// if will call the service
	if (client.call(srv)) {
		// proccess the data
		ROS_INFO("Returned sum is %d", (int)srv.response.sum);
	}
	else {
		// proccess failed
		ROS_WARN("Service call failed");
	}
}