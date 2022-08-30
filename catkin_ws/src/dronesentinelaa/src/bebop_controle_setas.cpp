   
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
#include <std_msgs/Empty.h>
#include "kbhit.h"
using namespace std;
     

int i;

std_msgs::Empty myMsg;
geometry_msgs::Twist msg;


ros::Publisher pub1; 
ros::Publisher pub2; 
ros::Publisher pub3; 


    
// Main function

int main(int argc, char **argv)
{
int key;
char entrada;
float velocidade;
// ROS publisher and subscriber initialization

ros::init(argc, argv, "petrobras");
ros::NodeHandle n;//Cria os nós para publicar os comandos de voo para o bebop
 
ros::Publisher pub1 = n.advertise<geometry_msgs::Twist>("/bebop/cmd_vel", 100); 
ros::Publisher pub2 = n.advertise<std_msgs::Empty>("/bebop/takeoff", 100);	
ros::Publisher pub3 = n.advertise<std_msgs::Empty>("/bebop/land", 100);	

//Publica mensagem de take-off (foi feito tres vezes porque ele não pega direito só uma vez)		


ROS_WARN("Take Off");
pub2.publish(myMsg);
ros::spinOnce();
sleep(1);
ROS_WARN("Take Off");
pub2.publish(myMsg);
ros::spinOnce();
sleep(1);
ROS_WARN("Take Off");

sleep(3);

msg.linear.x = 0;
msg.linear.y = 0;
msg.linear.z = 0;
msg.angular.x = 0;
msg.angular.y = 0;
msg.angular.z = 0;


// Publica comando de ir para frente durante 3 segundos


ros::Rate loop_rate(20);

while(entrada != 'f')
{    	
if (kbhit())
{		

ROS_WARN("Pressionada");
entrada = getchar();
velocidade=0.1;
  
switch (entrada)
{

case 's':  	
msg.linear.x = 0;
msg.linear.y = 0;
msg.linear.z = 0;
msg.angular.x = 0;
msg.angular.y = 0;
msg.angular.z = 0;

break;

case 'w':  	
msg.linear.x = velocidade;
msg.linear.y = 0;
msg.linear.z = 0;
msg.angular.x = 0;
msg.angular.y = 0;
msg.angular.z = 0;

break;

case 'x':  	
msg.linear.x = -velocidade;
msg.linear.y = 0;
msg.linear.z = 0;
msg.angular.x = 0;
msg.angular.y = 0;
msg.angular.z = 0;

break;

case 'd':  	
msg.linear.x = 0;
msg.linear.y = -velocidade;
msg.linear.z = 0;
msg.angular.x = 0;
msg.angular.y = 0;
msg.angular.z = 0;

break;

case 'a':  	
msg.linear.x = 0;
msg.linear.y = velocidade;
msg.linear.z = 0;
msg.angular.x = 0;
msg.angular.y = 0;
msg.angular.z = 0;

break;

case '1':  	
msg.linear.x = 0;
msg.linear.y = 0;
msg.linear.z = 0.5;
msg.angular.x = 0;
msg.angular.y = 0;
msg.angular.z = 0;

break;


case '2':  	
msg.linear.x = 0;
msg.linear.y = 0;
msg.linear.z = -0.5;
msg.angular.x = 0;
msg.angular.y = 0;
msg.angular.z = 0;

break;

case 'g':  	
msg.linear.x = 0;
msg.linear.y = 0;
msg.linear.z = 0;
msg.angular.x = 0;
msg.angular.y = 0;
msg.angular.z = velocidade;

break;

case 'h':  	
msg.linear.x = 0;
msg.linear.y = 0;
msg.linear.z = 0;
msg.angular.x = 0;
msg.angular.y = 0;
msg.angular.z = -velocidade;

break;


case 'l':  	
 ROS_WARN("No encerrado!");
entrada ='f';


break;


	
}

pub1.publish(msg);
ros::spinOnce();

}


}



pub3.publish(myMsg);
ros::spinOnce();
ROS_WARN("Land");





      return 0;
    }
