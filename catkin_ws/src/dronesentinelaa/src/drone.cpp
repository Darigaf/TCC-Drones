#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/Empty.h"
//tello cmd vel type = geometry_msgs/Twist
//tello takeoff type = std_msgs/Empty
//tello land type = std_msgs/Empty

geometry_msgs::Twist cmd_vel;
std_msgs::Empty empty;
float x,y,z;


int main(int argc, char **argv){
    ros::init(argc, argv, "drone");
    ros::NodeHandle n;
    
    ros::Publisher pubcmdvel = n.advertise<geometry_msgs::Twist>("/tello/cmd_vel", 1000); //criando o publisher do cmd_vel
    ros::Publisher publand = n.advertise<std_msgs::Empty>("/tello/land", 1);//criando o publisher do land

    ros::Rate loop_rate(10);
    ros::Publisher pubtakeoff = n.advertise<std_msgs::Empty>("/tello/takeoff", 1);//criando o publisher do takeoff

    sleep(5); //é importante dar um sleep quando for usa publicar multiplos topicos, para dar tempo de se conectar e executar a façanha
    pubtakeoff.publish(empty);
    sleep(5); //sendo sincer
    while (ros::ok()){
        cmd_vel.linear.x = 0.3;
        cmd_vel.linear.y = 0;
        cmd_vel.linear.z = 0;
        cmd_vel.angular.x = 0;
        cmd_vel.angular.y = 0;
        cmd_vel.angular.z = 0;
        pubcmdvel.publish(cmd_vel);
        ROS_WARN("...Publicado o x");
        sleep(5);
        cmd_vel.linear.x = 0;
        cmd_vel.linear.y = 0.3;
        cmd_vel.linear.z = 0;
        cmd_vel.angular.x = 0;
        cmd_vel.angular.y = 0;
        cmd_vel.angular.z = 0;
         pubcmdvel.publish(cmd_vel);
        ROS_WARN("...Publicado y");
        sleep(10);
        cmd_vel.linear.x = 0;
        cmd_vel.linear.y = 0;
        cmd_vel.linear.z = 0.5;
        cmd_vel.angular.x = 0;
        cmd_vel.angular.y = 0;
        cmd_vel.angular.z = 0;
        pubcmdvel.publish(cmd_vel);
        ROS_WARN("...Publicado z");
        sleep(10);
        publand.publish(empty);
        ros::spinOnce();
        sleep(5);


    }
    return 0;
}