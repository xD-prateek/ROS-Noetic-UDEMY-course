#include <ros/ros.h>

int main(int argc, char **argv) {
	// initiallise node and pass the file name arguments along with the node name as a string
	ros::init(argc, argv, "my_first_cpp_node");
	//we need to create an object of NodeHandle which is responsible for launching and exiting node
	ros::NodeHandle nh;

	ROS_INFO("Node has been started");

	// create a Rate object and pass integer 10 to make it run he loop at 10 hertz
	ros::Rate rate(10);
	// while the ros node is ok (i.e. not shutdown)
	while (ros::ok()) {
		ROS_INFO("Hello");
		rate.sleep();
		//rate ensures that one loop of while takes 0.1 sec(10 Hz)
	}

	// //there is no direct sleep object in cpp. For this purpose we need to create a duration object
	// ros::Duration(1.0).sleep();

	// ROS_INFO("Exit");
	return 0;

}