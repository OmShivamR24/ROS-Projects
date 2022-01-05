// http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29

#include'ros/ros.h"
#include"std_msgs/String.h"
using namespace ros;

int main(int argc , char** argv){

	init(argc , argv , "publisher");
	NodeHandle n;
	Publisher publisherNode = n.advertise< std_msgs::String>("publisherTopic", 100);
	Rate loop_rate(10);
	
	int count = 0 ;
	while(ok()){

	std_msgs::String msg;
	std::stringstream ss;
	ss << "ramram" << count ;
	msg.data = ss.str();

	ROS_INFO("%s" , msg.data.c_str());
	publisherTopic.publish(msg);
	spinOnce();
	loop_rate.sleep();
	++count ;
}

return 0;
}
