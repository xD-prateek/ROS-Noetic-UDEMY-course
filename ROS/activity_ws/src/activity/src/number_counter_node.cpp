#include <ros/ros.h>
#include <std_msgs/Int64.h>
#include <std_srvs/SetBool.h>

int ans = 0;
ros::Publisher pub;

void callback_publish_data(const std_msgs::Int64 msg) {

	ans += msg.data;
	std_msgs::Int64 new_msg;
	new_msg.data = ans;
	pub.publish(new_msg);

}

bool reset_number(std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &res) {
	if (req.data) {
		res.success = true;
		res.message = " ";
		ROS_INFO("Resetting node counter...");
		ans = 0;
	}
	else {
		res.success = false;
		res.message = "Failed to reset number counter.";
		ROS_INFO("Request denied.");
	}
	return true;
}

int main(int argc, char **argv) {

	ros::init(argc, argv, "number_counter");
	ros::NodeHandle nh;

	// create a subscriber
	ros::Subscriber sub = nh.subscribe("/number", 1000, callback_publish_data);
	// create a publisher
	pub = nh.advertise<std_msgs::Int64>("/number_count", 10);

	//creating a service and passing the call from command line
	ros::ServiceServer server = nh.advertiseService("/reset_counter", reset_number);

	ros::spin();
}