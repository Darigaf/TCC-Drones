#include <unistd.h>
#include <stdio.h>
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


     
using namespace std;
     
tf::Pose pose2;
     
float yaw_angle;
float position_x=0.1, difpos_x;
float position_y=0.1, difpos_y;
double orientation_w;
double delta =0;
float velocidade_x=0;
int tecla;
geometry_msgs::Point pose;
ros::Publisher pub1; 
ros::Publisher pub2; 
int i=0;
float vetorx[31]={0,0,0,0,0,2,4,6,6,4,2,0,-2,-4,-6,-6,-4,-2,0,2,4,6,6,4,2,0,-2,-4,-6,-6,-4};
float vetory[31]={6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6};
float vetorz[31]={2,4,6,8,10,10,10,10,12,12,12,12,12,12,12,14,14,14,14,14,14,14,16,16,16,16,16,16,16,18,18};
// Main function

int main(int argc, char **argv)
{

// ROS publisher and subscriber initialization

ros::init(argc, argv, "quaternion");
ros::NodeHandle n;
     
      	//ros::Subscriber sub = n.subscribe("bob1/odom", 1000, chatterCallback);
     	//ros::Subscriber sub2 = n.subscribe("/visualization_marker", 1000, subCallback); 
		
		ros::Publisher pub1 = n.advertise<geometry_msgs::Point>("/position", 1000);
		ros::Publisher pub2 = n.advertise<std_msgs::Float32>("/orientation", 1000);
      	ros::spinOnce();
		ros::Rate loop_rate(10);


while(ros::ok())
{

geometry_msgs::Twist msg;
std_msgs::Float32 orientacao;
//  Control loop

// Variable initialization



for (i=0;i<31;i++)
{
pose.x = vetorx[i];	
  pose.y = vetory[i];
  pose.z = vetorz[i];
 orientacao.data=0; 
ROS_WARN("...Publicado x: y: z: %f %f %f", vetorx[i], vetory[i], vetorz[i]);

pub1.publish(pose);
pub2.publish(orientacao);
ros::spinOnce();
sleep(5);
}

 






}
      return 0;
    }

