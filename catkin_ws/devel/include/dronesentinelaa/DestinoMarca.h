// Generated by gencpp from file dronesentinelaa/DestinoMarca.msg
// DO NOT EDIT!


#ifndef DRONESENTINELAA_MESSAGE_DESTINOMARCA_H
#define DRONESENTINELAA_MESSAGE_DESTINOMARCA_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace dronesentinelaa
{
template <class ContainerAllocator>
struct DestinoMarca_
{
  typedef DestinoMarca_<ContainerAllocator> Type;

  DestinoMarca_()
    : name()
    , distancia(0.0)  {
    }
  DestinoMarca_(const ContainerAllocator& _alloc)
    : name(_alloc)
    , distancia(0.0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _name_type;
  _name_type name;

   typedef double _distancia_type;
  _distancia_type distancia;





  typedef boost::shared_ptr< ::dronesentinelaa::DestinoMarca_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dronesentinelaa::DestinoMarca_<ContainerAllocator> const> ConstPtr;

}; // struct DestinoMarca_

typedef ::dronesentinelaa::DestinoMarca_<std::allocator<void> > DestinoMarca;

typedef boost::shared_ptr< ::dronesentinelaa::DestinoMarca > DestinoMarcaPtr;
typedef boost::shared_ptr< ::dronesentinelaa::DestinoMarca const> DestinoMarcaConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dronesentinelaa::DestinoMarca_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dronesentinelaa::DestinoMarca_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dronesentinelaa::DestinoMarca_<ContainerAllocator1> & lhs, const ::dronesentinelaa::DestinoMarca_<ContainerAllocator2> & rhs)
{
  return lhs.name == rhs.name &&
    lhs.distancia == rhs.distancia;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dronesentinelaa::DestinoMarca_<ContainerAllocator1> & lhs, const ::dronesentinelaa::DestinoMarca_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dronesentinelaa

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dronesentinelaa::DestinoMarca_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dronesentinelaa::DestinoMarca_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dronesentinelaa::DestinoMarca_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dronesentinelaa::DestinoMarca_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dronesentinelaa::DestinoMarca_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dronesentinelaa::DestinoMarca_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dronesentinelaa::DestinoMarca_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9d9d507dbde14f38120241599b9deca4";
  }

  static const char* value(const ::dronesentinelaa::DestinoMarca_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9d9d507dbde14f38ULL;
  static const uint64_t static_value2 = 0x120241599b9deca4ULL;
};

template<class ContainerAllocator>
struct DataType< ::dronesentinelaa::DestinoMarca_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dronesentinelaa/DestinoMarca";
  }

  static const char* value(const ::dronesentinelaa::DestinoMarca_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dronesentinelaa::DestinoMarca_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string name # Name of the landmark\n"
"float64 distancia # Distance to the landmark\n"
;
  }

  static const char* value(const ::dronesentinelaa::DestinoMarca_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dronesentinelaa::DestinoMarca_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.name);
      stream.next(m.distancia);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct DestinoMarca_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dronesentinelaa::DestinoMarca_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dronesentinelaa::DestinoMarca_<ContainerAllocator>& v)
  {
    s << indent << "name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.name);
    s << indent << "distancia: ";
    Printer<double>::stream(s, indent + "  ", v.distancia);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DRONESENTINELAA_MESSAGE_DESTINOMARCA_H
