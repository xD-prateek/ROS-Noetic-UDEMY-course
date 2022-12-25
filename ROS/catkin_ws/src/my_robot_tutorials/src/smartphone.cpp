#include <ros/ros.h>
#include <std_msgs/String.h>

void callback_recieve_radio_data(const std_msgs::String &msg) {
	ROS_INFO("Message recieved: %s", msg.data.c_str());
}

int main(int argc, char **argv) {

	// initialize the node
	ros::init(argc, argv, "smartphone");
	// initialize NodeHandle
	ros::NodeHandle nh;

	// create a subscriber node using nodehandle object subscribe.
	// arguments: (topic name, buffer size, a function handling the recieved data)
	ros::Subscriber sub = nh.subscribe("/robot_news_radio", 1000, callback_recieve_radio_data);

	// it keeps the node running until we ask it to shutdown
	ros::spin();
}