   
// BOB robot control script


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

geometry_msgs::Pose pose;
ros::Publisher pub1; 
 
// Receive the pose estimations though ROS Alvar Package

void subCallback(const visualization_msgs::Marker::ConstPtr& marker)
{


  pose.orientation.x = (float)marker->id;	// If more than one tag is found on the environment, the script selects the number one.
  pose.position.x = marker->pose.position.x;	
  pose.position.y = marker->pose.position.y;
  pose.position.z = marker->pose.position.z;
 
  
printf("%f x: ", pose.orientation.x); 

  if(marker->id ==3)
{

position_y = -(marker->pose.position.x); // Change of variables are necessary to correct the quadrant changes cause the camera downpointing.
position_x = -(marker->pose.position.y);// The same to the signal changes.
tf::poseMsgToTF(marker->pose, pose2);//
yaw_angle = -(tf::getYaw(pose2.getRotation()));

}

}

     
// Main function

int main(int argc, char **argv)
{

// ROS publisher and subscriber initialization

ros::init(argc, argv, "quaternion");
ros::NodeHandle n;
     
      	//ros::Subscriber sub = n.subscribe("bob1/odom", 1000, chatterCallback);
     	ros::Subscriber sub2 = n.subscribe("/visualization_marker", 1000, subCallback); 
		
		ros::Publisher pub1 = n.advertise<geometry_msgs::Twist>("/Pioner", 1000);
		
      	ros::spinOnce();
		ros::Rate loop_rate(10);

if (ros::ok())
{
geometry_msgs::Twist msg;
 
//  Control loop

// Variable initialization

		int interation=0, round=0;       
 		float posdesejada[2], oridesejada, dist=99, erroorie=99, last_erroorie=0, last_dist=0; 
        float tolerance_orie = 0.2, tolerance_pos = 0.2; // PID setpoint tolerance
        float KposP = 0.5, KposI = 0.01, KposD = 0; // PID position gains
		float KorieP = 1, KorieI = 0, KorieD = 0.1; // PIF orientation gains
		float Corr_OrP, Corr_OrI, Corr_OrD;
		float Corr_PosP, Corr_PosI, Corr_PosD;
        float angle;
     	float seconds;
		float last_secs = 0;
		ros:: Time last_time, actual_time, delta_time, begin;

//Set the position (0.0) as endpoint. The position (0.0) is right below the quadcopter, wherever it is positioned.  

posdesejada[0]= 0;
     
posdesejada[1]= 0;
   

// Begin the orientation correction 

double secs =ros::Time::now().toSec();
    	
while (1)
{
//ROS_INFO("Correcting orientation");

secs =ros::Time::now().toSec();




difpos_y = posdesejada[1]-position_y;
difpos_x = posdesejada[0]-position_x;
angle = atan2(difpos_y,difpos_x); 	
erroorie = angle-yaw_angle;

printf("posição: %f\n",position_y); 
msg.linear.x=position_y;
msg.angular.z=0;
pub1.publish(msg);
   

}
    }  return 0;
    }
