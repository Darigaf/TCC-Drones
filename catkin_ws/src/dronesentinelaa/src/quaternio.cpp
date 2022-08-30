#include "ros/ros.h"
#include "nav_msgs/Odometry.h" 
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h" 
#include <iostream>
#include <math.h>
#include <time.h>
#include <std_msgs/Float32.h>
#include <tf/tf.h>
#include "visualization_msgs/Marker.h"
#include "visualization_msgs/MarkerArray.h"
#include "geometry_msgs/Pose.h"
#include <std_msgs/Empty.h>
     
using namespace std;
     
tf::Pose pose2;
geometry_msgs::Pose pose;     
float yaw_angle, pich_angle;

   double roll, pitch, yaw;   

float position_x=0.1, difpos_x;
float position_y=0.1, difpos_y;
float position_z = 0.1;
double orientation_w;
double delta =0;
float velocidade_x=0;
float angulo_graus;
int c;
//double round=0;
std_msgs::Empty myMsg;
geometry_msgs::Twist msg;


ros::Publisher pub1; 
ros::Publisher pub2; 
ros::Publisher pub3; 


const double velz[8]={1,1,1,0,-1,-1,-1,0};


void subCallback(const visualization_msgs::Marker::ConstPtr& marker)
{


	// If more than one tag is found on the environment, the script selects the number one.
  pose.position.x = marker->pose.position.x;	
  pose.position.y = marker->pose.position.y;
  pose.position.z = marker->pose.position.z;


 tf::Quaternion q(
        marker->pose.orientation.x,
        marker->pose.orientation.y,
        marker->pose.orientation.z,
        marker->pose.orientation.w);
    tf::Matrix3x3 m(q);
  


 
    m.getRPY(roll, pitch, yaw);

ROS_INFO("I heard row: [%f]", roll);
ROS_INFO("I heard pitch: [%f]", pitch);
ROS_INFO("I heard yaw: [%f]", yaw);

ros::spinOnce();

}

int main(int argc, char **argv)
{

// ROS publisher and subscriber initialization

ros::init(argc, argv, "quaternion");
ros::NodeHandle n;

ros::Subscriber quaternio = n.subscribe("/visualization_marker", 1000, subCallback); 
ros::spinOnce();
ros::Rate loop_rate(20);
while(1)
{





    }
return 0;
}
