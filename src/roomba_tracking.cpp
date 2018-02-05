#include <ros/ros.h>

#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <sensor_msgs/CameraInfo.h>
#include <sensor_msgs/Image.h>

#include <image_transport/image_transport.h>

#include <tf/transform_listener.h>

#include "../include/m7_tracking/Tracker.h"
#include "../include/m7_tracking/Params.h"


tf::TransformListener* tf;

void camera1_callback(const sensor_msgs::ImageConstPtr& img, const sensor_msgs::CameraInfoConstPtr& cam){

}

void camera2_callback(const sensor_msgs::ImageConstPtr& img, const sensor_msgs::CameraInfoConstPtr& cam){

}

void camera3_callback(const sensor_msgs::ImageConstPtr& img, const sensor_msgs::CameraInfoConstPtr& cam){

}

void camera4_callback(const sensor_msgs::ImageConstPtr& img, const sensor_msgs::CameraInfoConstPtr& cam){

}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "m7_tracking", ros::init_options::AnonymousName);
	ros::NodeHandle nh;

	tf = new tf::TransformListener(nh);

	ros::param::param<std::string>("~image_topic_1", CAMERA_IMAGE_TOPIC_1, D_CAMERA_IMAGE_TOPIC_1);
	ros::param::param<std::string>("~image_topic_2", CAMERA_IMAGE_TOPIC_2, D_CAMERA_IMAGE_TOPIC_2);
	ros::param::param<std::string>("~image_topic_3", CAMERA_IMAGE_TOPIC_3, D_CAMERA_IMAGE_TOPIC_3);
	ros::param::param<std::string>("~image_topic_4", CAMERA_IMAGE_TOPIC_4, D_CAMERA_IMAGE_TOPIC_4);

	ros::param::param<std::string>("~image__topic_1", RED_HUE_HSV_HIGH, D_RED_HUE_HSV_HIGH);
	ros::param::param<std::string>("~image_topic_2", RED_HUE_HSV_LOW, D_HUE_RED_HSV_LOW);
	ros::param::param<std::string>("~image_topic_2", RED_SATURATION_HSV_HIGH, D_SATURATION_RED_HSV_HIGH);
	ros::param::param<std::string>("~image_topic_2", RED_SATURATION_HSV_LOW, D_SATURATION_RED_HSV_LOW);
	ros::param::param<std::string>("~image_topic_2", RED_VALUE_HSV_HIGH, D_VALUE_RED_HSV_HIGH);
	ros::param::param<std::string>("~image_topic_2", RED_VALUE_HSV_LOW, D_VALUE_RED_HSV_LOW);

	ros::param::param<std::string>("~image__topic_1", GREEN_HUE_HSV_HIGH, D_GREEN_HUE_HSV_HIGH);
	ros::param::param<std::string>("~image_topic_2", GREEN_HUE_HSV_LOW, D_HUE_GREEN_HSV_LOW);
	ros::param::param<std::string>("~image_topic_2", GREEN_SATURATION_HSV_HIGH, D_SATURATION_GREEN_HSV_HIGH);
	ros::param::param<std::string>("~image_topic_2", GREEN_SATURATION_HSV_LOW, D_SATURATION_GREEN_HSV_LOW);
	ros::param::param<std::string>("~image_topic_2", GREEN_VALUE_HSV_HIGH, D_VALUE_GREEN_HSV_HIGH);
	ros::param::param<std::string>("~image_topic_2", GREEN_VALUE_HSV_LOW, D_VALUE_GREEN_HSV_LOW);


	// setup image transport
	image_transport::ImageTransport it1(nh);
	image_transport::CameraSubscriber cam1_sub = it1.subscribeCamera(CAMERA_IMAGE_TOPIC_1, 10, camera1_callback);

	image_transport::ImageTransport it2(nh);
	image_transport::CameraSubscriber cam2_sub = it2.subscribeCamera(CAMERA_IMAGE_TOPIC_2, 10, camera2_callback);

	image_transport::ImageTransport it3(nh);
	image_transport::CameraSubscriber cam3_sub = it3.subscribeCamera(CAMERA_IMAGE_TOPIC_3, 10, camera3_callback);

	image_transport::ImageTransport it4(nh);
	image_transport::CameraSubscriber cam4_sub = it4.subscribeCamera(CAMERA_IMAGE_TOPIC_4, 10, camera4_callback);


	ros::spin();

	return 0;
}
