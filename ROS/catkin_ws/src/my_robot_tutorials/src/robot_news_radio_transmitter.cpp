#include <ros/ros.h>
#include <std_msgs/String.h>

int main(int argc, char **argv) {

	// create a node
	// arguments: argc, argv, name of node
	ros::init(argc, argv, "robot_news_radio_transmitter", ros::init_options::AnonymousName);
	// initialize node handles
	ros::NodeHandle nh;

	// create a ros publisher
	// make a nodehandle object advertise<message type>(topic name, buffer size)
	ros::Publisher pub = nh.advertise<std_msgs::String>("/robot_news_radio", 10);

	// create a rate object which make the loop take 3sec before going to next cycle
	ros::Rate rate(3);

	// while ros node is running
	while (ros::ok()) {
		// create an object
		std_msgs::String msg;

		msg.data = "Hi, this is Radio Mirchi!!";
		pub.publish(msg);
		rate.sleep();

	}

}