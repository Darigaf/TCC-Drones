#include "ros/ros.h"
#include "nav_msgs/Odometry.h" 
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h" 
#include "std_msgs/Empty.h" 
#include <iostream>
#include <math.h>
#include <time.h>
#include <std_msgs/Float32.h>
#include <tf/tf.h>
#include "visualization_msgs/Marker.h"
#include "visualization_msgs/MarkerArray.h"
#include "geometry_msgs/Pose.h"
//parece que vai transformar a msg tipo pose em algo que consiga ler, e operar

using namespace std;

tf::Pose posetf;
geometry_msgs::Pose pos;
geometry_msgs::Twist cmd_vel;
std_msgs::Empty empty;

float yaw_angle;
float pose_x=0.1, difpos_x;
float pose_y=0.1, difpos_y;
double orienta_w;
double delta =0;
float velocidade=0.3, x,y,z;

void VisuCallBack(const visualization_msgs::Marker::ConstPtr tag){
    //pose.orientation.x = (float)tag->id; só caso detecta outras tags
    pos.position.x = tag->pose.position.x;//passando a data da tag para uma variavel para melhor manipulação
    pos.position.y = tag->pose.position.y;
    pos.position.z = tag->pose.position.z;

    pose_x = -(tag->pose.position.x); //conversão para utilizar o quaternion 
    pose_y = -(tag->pose.position.y); 
    tf::poseMsgToTF(tag->pose, posetf); //convertendo pro tf, assim a maquina ocnsegue ler
    yaw_angle = -(tf::getYaw(posetf.getRotation()));//agora que o posetf tem as datas, fez conversão para pegar o angulo Yaw (o que serve pra girar em si mesmo)

    ROS_INFO("o xy é: %f %f", pose_x, pose_y);
}
int main(int argc, char **argv)
{

// ROS publisher and subscriber initialization
    ROS_WARN("...Publicado dormir");
    ros::init(argc, argv, "posetello");//vai chamar o quaternion para fazer calculos e n dar merda
    ros::NodeHandle n;

    ros::Subscriber subvisu = n.subscribe("/visualization_marker",1000, VisuCallBack); //vai usar o topico e fazer oq ta escrito no callback
    ros::Publisher pubcmd_vel = n.advertise<geometry_msgs::Twist>("/tello/cmd_vel", 1000);
    ros::Publisher pubtakeoff = n.advertise<std_msgs::Empty>("/tello/takeoff", 1);
    ros::Publisher publand = n.advertise<std_msgs::Empty>("/tello/land", 1);

   //chama callback
    ros::spinOnce();
    ros::Rate loop_rate(10);
    pubtakeoff.publish(empty);
    while(ros::ok()){
            if(pose_x<0.30){
                x=0.2;
                y=0;
                z=0;
                ROS_WARN("...Publicado x1");
                
            }else if(pose_x >0.40){
                x=-0.2;
                y=0;
                z=0;
                ROS_WARN("...Publicado x2");
            }else if(pose_y<0.15){
                x=0;
                y=0.2;
                z=0;
                ROS_WARN("...Publicado y1");
            }else if(pose_y >0.26){
                x=0;
                y=-0.2;
                z=0;
                ROS_WARN("...Publicado y2");
            }
            cmd_vel.linear.x = x;
            cmd_vel.linear.y = y;
            cmd_vel.linear.z = z;
            cmd_vel.angular.x = 0;
            cmd_vel.angular.y = 0;
            cmd_vel.angular.z = 0;
            pubcmd_vel.publish(cmd_vel);
            sleep(1);
    }
    return 0;
}