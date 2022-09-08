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
        for (size_t i = 0; i < 4; i++)
        {
            if (i==0)
            {
                x=0.3;
                y=0;
                z=0;
                ROS_WARN("...Publicado x");
            }
            if (i==1)
            {
                x=0;
                y=0.3;
                z=0;
                ROS_WARN("...Publicado y");
            }
            if (i==2)
            {
                x=-0.3;
                y=0;
                z=0;
                ROS_WARN("...Publicado x");
            }
            if (i==3)
            {
                x=0;
                y=-0.3;
                z=0;
                ROS_WARN("...Publicado y");
            }
        
            cmd_vel.linear.x = x;
            cmd_vel.linear.y = y;
            cmd_vel.linear.z = z;
            cmd_vel.angular.x = 0;
            cmd_vel.angular.y = 0;
            cmd_vel.angular.z = 0;
            pubcmdvel.publish(cmd_vel);
            ROS_WARN("...Publicado dormir");
            sleep(10);
        }
        
        publand.publish(empty);
        ros::spinOnce();
        sleep(5);


    }
    return 0;
}