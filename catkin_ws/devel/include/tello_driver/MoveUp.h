// Generated by gencpp from file tello_driver/MoveUp.msg
// DO NOT EDIT!


#ifndef TELLO_DRIVER_MESSAGE_MOVEUP_H
#define TELLO_DRIVER_MESSAGE_MOVEUP_H

#include <ros/service_traits.h>


#include <tello_driver/MoveUpRequest.h>
#include <tello_driver/MoveUpResponse.h>


namespace tello_driver
{

struct MoveUp
{

typedef MoveUpRequest Request;
typedef MoveUpResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct MoveUp
} // namespace tello_driver


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::tello_driver::MoveUp > {
  static const char* value()
  {
    return "93e098705f3e00df20d27935dc5efafa";
  }

  static const char* value(const ::tello_driver::MoveUp&) { return value(); }
};

template<>
struct DataType< ::tello_driver::MoveUp > {
  static const char* value()
  {
    return "tello_driver/MoveUp";
  }

  static const char* value(const ::tello_driver::MoveUp&) { return value(); }
};


// service_traits::MD5Sum< ::tello_driver::MoveUpRequest> should match
// service_traits::MD5Sum< ::tello_driver::MoveUp >
template<>
struct MD5Sum< ::tello_driver::MoveUpRequest>
{
  static const char* value()
  {
    return MD5Sum< ::tello_driver::MoveUp >::value();
  }
  static const char* value(const ::tello_driver::MoveUpRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::tello_driver::MoveUpRequest> should match
// service_traits::DataType< ::tello_driver::MoveUp >
template<>
struct DataType< ::tello_driver::MoveUpRequest>
{
  static const char* value()
  {
    return DataType< ::tello_driver::MoveUp >::value();
  }
  static const char* value(const ::tello_driver::MoveUpRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::tello_driver::MoveUpResponse> should match
// service_traits::MD5Sum< ::tello_driver::MoveUp >
template<>
struct MD5Sum< ::tello_driver::MoveUpResponse>
{
  static const char* value()
  {
    return MD5Sum< ::tello_driver::MoveUp >::value();
  }
  static const char* value(const ::tello_driver::MoveUpResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::tello_driver::MoveUpResponse> should match
// service_traits::DataType< ::tello_driver::MoveUp >
template<>
struct DataType< ::tello_driver::MoveUpResponse>
{
  static const char* value()
  {
    return DataType< ::tello_driver::MoveUp >::value();
  }
  static const char* value(const ::tello_driver::MoveUpResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // TELLO_DRIVER_MESSAGE_MOVEUP_H
