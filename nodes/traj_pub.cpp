
#include <ardrone_autonomy/ardrone_driver.h>
#include <ardrone_autonomy/teleop_twist.h>

int main(int argc, char **argv)
{

  ros::init(argc, argv, "traj_pub");
  ros::NodeHandle nh;

  ros::Publisher traj_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
  ros::Publisher takeoff_pub = nh.advertise<std_msgs::Empty>("/ardrone/takeoff", 1000);
  ros::Publisher land_pub = nh.advertise<std_msgs::Empty>("/ardrone/land", 1000);

  while(!traj_pub.getNumSubscribers() > 0){}

  ros::Rate loop_rate(10);
  loop_rate.sleep();

  while(ros::ok()){
    ros::spinOnce();
  }

  return 0;
}
