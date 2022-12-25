#include <ros/ros.h>
#include <battery_status/set_led.h>

void setLED(ros::NodeHandle *nh, bool battery_state) {
	ros::service::waitForService("/toggle_led");

	ros::ServiceClient client = nh->serviceClient<battery_status::set_led>("/toggle_led");

	battery_status::set_led srv;
	srv.request.led_toggle = 1;
	srv.request.state = true;
	if (battery_state) {
		srv.request.state = false;
	}

	if (client.call(srv)) {
		ROS_INFO("Set led success flag: %d", srv.request.state);
	}
	else {
		ROS_WARN("Service call failed.");
	}
}

int main(int argc, char **argv) {
	ros::init(argc, argv, "battery_status");
	ros::NodeHandle nh;

	while (ros::ok()) {
		ros::Duration(7.0).sleep();
		ROS_INFO("Battery empty!");
		setLED(&nh, false);
		ros::Duration(3.0).sleep();
		ROS_INFO("Battery full!");
		setLED(&nh, true);
	}
}