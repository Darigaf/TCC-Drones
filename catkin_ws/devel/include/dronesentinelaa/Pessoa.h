// Generated by gencpp from file dronesentinelaa/Pessoa.msg
// DO NOT EDIT!


#ifndef DRONESENTINELAA_MESSAGE_PESSOA_H
#define DRONESENTINELAA_MESSAGE_PESSOA_H


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
struct Pessoa_
{
  typedef Pessoa_<ContainerAllocator> Type;

  Pessoa_()
    : first_name()
    , last_name()
    , age(0)
    , score(0)  {
    }
  Pessoa_(const ContainerAllocator& _alloc)
    : first_name(_alloc)
    , last_name(_alloc)
    , age(0)
    , score(0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _first_name_type;
  _first_name_type first_name;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _last_name_type;
  _last_name_type last_name;

   typedef uint8_t _age_type;
  _age_type age;

   typedef uint32_t _score_type;
  _score_type score;





  typedef boost::shared_ptr< ::dronesentinelaa::Pessoa_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dronesentinelaa::Pessoa_<ContainerAllocator> const> ConstPtr;

}; // struct Pessoa_

typedef ::dronesentinelaa::Pessoa_<std::allocator<void> > Pessoa;

typedef boost::shared_ptr< ::dronesentinelaa::Pessoa > PessoaPtr;
typedef boost::shared_ptr< ::dronesentinelaa::Pessoa const> PessoaConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dronesentinelaa::Pessoa_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dronesentinelaa::Pessoa_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::dronesentinelaa::Pessoa_<ContainerAllocator1> & lhs, const ::dronesentinelaa::Pessoa_<ContainerAllocator2> & rhs)
{
  return lhs.first_name == rhs.first_name &&
    lhs.last_name == rhs.last_name &&
    lhs.age == rhs.age &&
    lhs.score == rhs.score;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::dronesentinelaa::Pessoa_<ContainerAllocator1> & lhs, const ::dronesentinelaa::Pessoa_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace dronesentinelaa

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::dronesentinelaa::Pessoa_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dronesentinelaa::Pessoa_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dronesentinelaa::Pessoa_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dronesentinelaa::Pessoa_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dronesentinelaa::Pessoa_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dronesentinelaa::Pessoa_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dronesentinelaa::Pessoa_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f8bfa80ae3c7a93455596d9622ad33a9";
  }

  static const char* value(const ::dronesentinelaa::Pessoa_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf8bfa80ae3c7a934ULL;
  static const uint64_t static_value2 = 0x55596d9622ad33a9ULL;
};

template<class ContainerAllocator>
struct DataType< ::dronesentinelaa::Pessoa_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dronesentinelaa/Pessoa";
  }

  static const char* value(const ::dronesentinelaa::Pessoa_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dronesentinelaa::Pessoa_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string first_name \n"
"string last_name \n"
"uint8 age \n"
"uint32 score  \n"
;
  }

  static const char* value(const ::dronesentinelaa::Pessoa_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dronesentinelaa::Pessoa_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.first_name);
      stream.next(m.last_name);
      stream.next(m.age);
      stream.next(m.score);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Pessoa_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dronesentinelaa::Pessoa_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dronesentinelaa::Pessoa_<ContainerAllocator>& v)
  {
    s << indent << "first_name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.first_name);
    s << indent << "last_name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.last_name);
    s << indent << "age: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.age);
    s << indent << "score: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.score);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DRONESENTINELAA_MESSAGE_PESSOA_H
