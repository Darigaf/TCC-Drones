
//http://docs.ros.org/lunar/api/mavros/html/global__position_8cpp_source.html
#include <ros/ros.h>
#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include <sensor_msgs/NavSatStatus.h>
#include <sensor_msgs/NavSatFix.h>
#include "conv.h"
#include <nav_msgs/Odometry.h>
   
   using namespace gps_common;
   
    static ros::Publisher odom_pub;
geometry_msgs::Point msg;


float pos_x, pos_y, pos_z, orient;
float pos_x2, pos_y2, pos_z2, orient2;
float pos_x3, pos_y3, pos_z3, orient3;
float pos_FX, pos_FY, pos_FZ, orientF;
int i=0;

    std::string frame_id, child_frame_id;
    double rot_cov;
   
    void callback(const sensor_msgs::NavSatFixConstPtr& fix) {
      if (fix->status.status == sensor_msgs::NavSatStatus::STATUS_NO_FIX) {
       ROS_DEBUG_THROTTLE(60,"No fix.");
        return;
    }
    
     if (fix->header.stamp == ros::Time(0)) {
       return;
      }
    
      double northing, easting;
      std::string zone;
    
    LLtoUTM(fix->latitude, fix->longitude, northing, easting, zone);
    
    if (odom_pub) {
      nav_msgs::Odometry odom;
       odom.header.stamp = fix->header.stamp;
   
       if (frame_id.empty())
         odom.header.frame_id = fix->header.frame_id;
        else
          odom.header.frame_id = frame_id;
   
        odom.child_frame_id = child_frame_id;
   
        odom.pose.pose.position.x = easting;
       odom.pose.pose.position.y = northing;
        odom.pose.pose.position.z = fix->altitude;
        
       odom.pose.pose.orientation.x = 0;
      odom.pose.pose.orientation.y = 0;
       odom.pose.pose.orientation.z = 0;
       odom.pose.pose.orientation.w = 1;
       
        // Use ENU covariance to build XYZRPY covariance
       boost::array<double, 36> covariance = {{
         fix->position_covariance[0],
         fix->position_covariance[1],
         fix->position_covariance[2],
         0, 0, 0,
          fix->position_covariance[3],
         fix->position_covariance[4],
         fix->position_covariance[5],
          0, 0, 0,
          fix->position_covariance[6],
         fix->position_covariance[7],
          fix->position_covariance[8],
         0, 0, 0,
         0, 0, 0, rot_cov, 0, 0,
          0, 0, 0, 0, rot_cov, 0,
         0, 0, 0, 0, 0, rot_cov
        }};
   
        odom.pose.covariance = covariance;
    
        odom_pub.publish(odom);




pos_x2=odom.pose.pose.position.x;
odom.pose.pose.position.y;
pos_z2=odom.pose.pose.position.z;
orient2=0;

pos_FX=690793.070244;
pos_FY=7178106.87322;

pos_x3=pos_x2-pos_FX;
pos_y3=pos_y2-pos_FY;

//ROS_INFO("I heard X2: [%f]", pos_x2);
//ROS_INFO("I heard FX: [%f]", pos_FX);
ROS_INFO("I heard delta-X: [%f]", pos_x3);
ROS_INFO("I heard delta-y: [%f]", pos_y3);










      }
    }
   
    int main (int argc, char **argv) {
     ros::init(argc, argv, "utm_odometry_node");
      ros::NodeHandle node;
      ros::NodeHandle priv_node("~");
    
      priv_node.param<std::string>("frame_id", frame_id, "map");
      priv_node.param<std::string>("child_frame_id", child_frame_id, "");
      priv_node.param<double>("rot_covariance", rot_cov, 99999.0);
    
     odom_pub = node.advertise<nav_msgs::Odometry>("odom_rtk", 1000);
     ros::Publisher path_pub2 = node.advertise<nav_msgs::Path>("path_rtk",1, true); 
      ros::Subscriber fix_sub = node.subscribe("tcpfix", 1000, callback);
   
     ros::spin();
    }