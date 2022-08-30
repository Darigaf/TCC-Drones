#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/Empty.h"
#include "geometry_msgs/Point.h"
/*rosmsg show geometry_msgs/Point
    float64 x
    float64 y
    float64 z
*/
#include "geometry_msgs/Pose.h" 
/*rosmsg show geometry_msgs/Pose
    geometry_msgs/Point position
    float64 x
    float64 y
    float64 z
    geometry_msgs/Quaternion orientation
    float64 x
    float64 y
    float64 z
    float64 w
*/
geometry_msgs::Twist cmdvel;
geometry_msgs::Point ponto;
geometry_msgs::Pose posicao;

int main(int argc, char **argv){
    ros::init(argc, argv, "pidrascunho");
    ros::NodeHandle n;
    
    ros::Publisher pubcmdvel = n.advertise<geometry_msgs::Twist>("/tello/cmd_vel", 1000); //criando o publisher do cmd_vel
    ros::Publisher publand = n.advertise<std_msgs::Empty>("/tello/land", 1);//criando o publisher do land
    ros::Publisher pubpose = n.advertise<geometry_msgs::Twist>("nsei direito", 1000); 
    ros::Rate loop_rate(10);
    ros::Publisher pubtakeoff = n.advertise<std_msgs::Empty>("/tello/takeoff", 1);//criando o publisher do takeoff
    while (ros::ok()){
        //hmmmmmmmmm pid;
        while (posicao.position.z =! ponto.z)
        {
            if (posicao.position.z < ponto.z)
            {
                cmdvel.linear.z = 0.5;
            } else if (posicao.position.z > ponto.z)
            {
                cmdvel.linear.z = -0.5;
            }
            
        }
        
        while (posicao.position.y =! ponto.y)
        {
            if (posicao.position.y < ponto.y)
            {
                cmdvel.linear.y = 0.5;
            } else if (posicao.position.y > ponto.y)
            {
                cmdvel.linear.y = -0.5;
            }
        }
        while (posicao.position.x =! ponto.x)
        {
            if (posicao.position.x < ponto.x)
            {
                cmdvel.linear.x = 0.5;
            } else if (posicao.position.x > ponto.x)
            {
                cmdvel.linear.x = -0.5;
            }
        }
        pubcmdvel.publish(cmdvel);
    }
    
}