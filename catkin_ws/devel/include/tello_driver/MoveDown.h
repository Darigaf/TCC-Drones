// Generated by gencpp from file tello_driver/MoveDown.msg
// DO NOT EDIT!


#ifndef TELLO_DRIVER_MESSAGE_MOVEDOWN_H
#define TELLO_DRIVER_MESSAGE_MOVEDOWN_H

#include <ros/service_traits.h>


#include <tello_driver/MoveDownRequest.h>
#include <tello_driver/MoveDownResponse.h>


namespace tello_driver
{

struct MoveDown
{

typedef MoveDownRequest Request;
typedef MoveDownResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct MoveDown
} // namespace tello_driver


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::tello_driver::MoveDown > {
  static const char* value()
  {
    return "93e098705f3e00df20d27935dc5efafa";
  }

  static const char* value(const ::tello_driver::MoveDown&) { return value(); }
};

template<>
struct DataType< ::tello_driver::MoveDown > {
  static const char* value()
  {
    return "tello_driver/MoveDown";
  }

  static const char* value(const ::tello_driver::MoveDown&) { return value(); }
};


// service_traits::MD5Sum< ::tello_driver::MoveDownRequest> should match
// service_traits::MD5Sum< ::tello_driver::MoveDown >
template<>
struct MD5Sum< ::tello_driver::MoveDownRequest>
{
  static const char* value()
  {
    return MD5Sum< ::tello_driver::MoveDown >::value();
  }
  static const char* value(const ::tello_driver::MoveDownRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::tello_driver::MoveDownRequest> should match
// service_traits::DataType< ::tello_driver::MoveDown >
template<>
struct DataType< ::tello_driver::MoveDownRequest>
{
  static const char* value()
  {
    return DataType< ::tello_driver::MoveDown >::value();
  }
  static const char* value(const ::tello_driver::MoveDownRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::tello_driver::MoveDownResponse> should match
// service_traits::MD5Sum< ::tello_driver::MoveDown >
template<>
struct MD5Sum< ::tello_driver::MoveDownResponse>
{
  static const char* value()
  {
    return MD5Sum< ::tello_driver::MoveDown >::value();
  }
  static const char* value(const ::tello_driver::MoveDownResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::tello_driver::MoveDownResponse> should match
// service_traits::DataType< ::tello_driver::MoveDown >
template<>
struct DataType< ::tello_driver::MoveDownResponse>
{
  static const char* value()
  {
    return DataType< ::tello_driver::MoveDown >::value();
  }
  static const char* value(const ::tello_driver::MoveDownResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // TELLO_DRIVER_MESSAGE_MOVEDOWN_H
