#include <ros/ros.h>
#include <battery_status/set_led.h>

bool ledState[] {false, false, false};

bool change_led(battery_status::set_led::Request &req, battery_status::set_led::Response &res) {
	int led_num = req.led_toggle;
	bool led_state = req.state;

	if (led_num > 3 or led_num < 1) {
		res.success_state = false;
		return true;
	}
	ledState[led_num - 1] = led_state;
	// switch (led_num) {
	// case 1:
	// 	ROS_INFO("LED 1 status: ON");
	// 	ROS_INFO("LED 2 status: OFF");
	// 	ROS_INFO("LED 3 status: OFF");
	// 	res.success_state = true;
	// case 2:
	// 	ROS_INFO("LED 1 status: OFF");
	// 	ROS_INFO("LED 2 status: ON");
	// 	ROS_INFO("LED 3 status: OFF");
	// 	res.success_state = true;
	// case 3:
	// 	ROS_INFO("LED 1 status: OFF");
	// 	ROS_INFO("LED 2 status: OFF");
	// 	ROS_INFO("LED 3 status: ON");
	// 	res.success_state = true;
	// default:
	// 	ROS_ERROR("Wrong LED input.");
	// 	res.success_state = false;
	// }
	ROS_INFO("\t%d\t%d\t%d", ledState[0], ledState[1], ledState[2]);


	res.success_state = true;
	return true;
}

int main(int argc, char **argv) {

	// initialise the node
	ros::init(argc, argv, "ledPanel");
	ros::NodeHandle nh;

	ros::ServiceServer server = nh.advertiseService("/toggle_led", change_led);

	ROS_INFO("\t%d\t%d\t%d", ledState[0], ledState[1], ledState[2]);

	ros::spin();

}