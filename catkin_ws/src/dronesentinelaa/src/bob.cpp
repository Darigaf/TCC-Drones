   
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
 
  
printf("%f x: ", pose.position.x); 

  if(marker->id ==0)
{

position_y = -(marker->pose.position.x); // Change of variables are necessary to correct the quadrant changes cause the camera downpointing.
position_x = -(marker->pose.position.y);// The same to the signal changes.
tf::poseMsgToTF(marker->pose, pose2);//
yaw_angle = -(tf::getYaw(pose2.getRotation()));

}

ros::spinOnce();

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
    	
while ((abs(erroorie) > tolerance_orie)) // While the orientation error is bigger than tolerance, repeats the loop
{
//ROS_INFO("Correcting orientation");

secs =ros::Time::now().toSec();

//The PID calculations makes a division by delta time. On the fist loops, the loop time received is too small, cause the system is still starting. So, the initial delta must be discard. This if(round<5) conditional has this function, only for the 5 rounds from program start running.

if(round<5)
{
delta = 1;
round++;
}
else
{

delta = secs - last_secs;

}


difpos_y = posdesejada[1]-position_y;
difpos_x = posdesejada[0]-position_x;
angle = atan2(difpos_y,difpos_x); 	
erroorie = angle-yaw_angle;

printf("posição: %f\n",position_y);  
//printf("w: %f\n\n",yaw_angle);
Corr_OrP = KorieP*erroorie; // Proportional correction calculation.
Corr_OrI = KorieI *erroorie * delta; // Integral correction calculation.
Corr_OrD = KorieD * ((last_erroorie - erroorie)/delta); //Differential correction calculation.


msg.angular.z = Corr_OrP + Corr_OrI + Corr_OrD;
pub1.publish(msg);
    
ros::spinOnce();
last_secs = secs;
last_erroorie = erroorie;
last_dist = dist;


interation++;
}           	


// Start the BOB displacement control loop

while ((dist > tolerance_pos)) // While position and orientation errors are not less than tolerance, repeats loop

{


ROS_INFO("Moving the BOB");


secs =ros::Time::now().toSec();

delta = secs - last_secs;

difpos_y = posdesejada[1]-position_y;
difpos_x = posdesejada[0]-position_x;
angle = atan2(difpos_y,difpos_x); 

//Position PID control		

erroorie = angle-yaw_angle;
     
Corr_OrP = KorieP*erroorie;
Corr_OrI = KorieI *erroorie * delta;
Corr_OrD = KorieD * ((last_erroorie - erroorie)/delta);

printf("difw: %f\n",erroorie);  
printf("w: %f\n\n",yaw_angle);

msg.angular.z = Corr_OrP + Corr_OrI + Corr_OrD;
pub1.publish(msg);
     
loop_rate.sleep(); 
    
ros::spinOnce();
last_secs = secs;
last_erroorie = erroorie;
last_dist = dist;


interation++;
     	
//Position PID control 	
dist =  sqrt(pow(posdesejada[0]-position_x,2)+pow(posdesejada[1]-position_y,2));
    		
Corr_PosP =  abs(KposP*(dist));
Corr_PosI = abs(KposI * dist *delta);
Corr_PosD = abs(KposD *((last_dist - dist)/delta));

//printf("difw: %f\n",erroorie);  
//printf("w: %f\n\n",yaw_angle);
printf("distancia: %f\n\n",dist);

msg.linear.x = Corr_PosP + Corr_PosI + Corr_PosD;
pub1.publish(msg); 
          		
loop_rate.sleep(); 
    
ros::spinOnce();
last_secs = secs;
last_erroorie = erroorie;
last_dist = dist;

interation++;
}

// Set the BOB angular and linear velocity to zero to stop the robot at the setpoint. 
msg.linear.x=0;
msg.angular.z=0;
pub1.publish(msg);
ros::spinOnce();







msg.linear.x=0;
msg.angular.z=0;
pub1.publish(msg);
ros::spinOnce();
ROS_WARN("...Orientation achieved...");
ROS_WARN("...Position achieved...");
ROS_WARN("...End of moving. To make another move, run the program again");    

}
      return 0;
    }
