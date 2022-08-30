# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "dronesentinelaa: 4 messages, 1 services")

set(MSG_I_FLAGS "-Idronesentinelaa:/home/drones/catkin_ws/src/dronesentinelaa/msg;-Iactionlib_msgs:/opt/ros/melodic/share/actionlib_msgs/cmake/../msg;-Iar_track_alvar_msgs:/opt/ros/melodic/share/ar_track_alvar_msgs/cmake/../msg;-Idiagnostic_msgs:/opt/ros/melodic/share/diagnostic_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/melodic/share/geometry_msgs/cmake/../msg;-Imavros_msgs:/opt/ros/melodic/share/mavros_msgs/cmake/../msg;-Inav_msgs:/opt/ros/melodic/share/nav_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/melodic/share/sensor_msgs/cmake/../msg;-Ishape_msgs:/opt/ros/melodic/share/shape_msgs/cmake/../msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg;-Istereo_msgs:/opt/ros/melodic/share/stereo_msgs/cmake/../msg;-Itrajectory_msgs:/opt/ros/melodic/share/trajectory_msgs/cmake/../msg;-Ivisualization_msgs:/opt/ros/melodic/share/visualization_msgs/cmake/../msg;-Igeographic_msgs:/opt/ros/melodic/share/geographic_msgs/cmake/../msg;-Iuuid_msgs:/opt/ros/melodic/share/uuid_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(dronesentinelaa_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/msg/Pessoa.msg" NAME_WE)
add_custom_target(_dronesentinelaa_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "dronesentinelaa" "/home/drones/catkin_ws/src/dronesentinelaa/msg/Pessoa.msg" ""
)

get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/msg/Um.msg" NAME_WE)
add_custom_target(_dronesentinelaa_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "dronesentinelaa" "/home/drones/catkin_ws/src/dronesentinelaa/msg/Um.msg" ""
)

get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/msg/Num.msg" NAME_WE)
add_custom_target(_dronesentinelaa_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "dronesentinelaa" "/home/drones/catkin_ws/src/dronesentinelaa/msg/Num.msg" ""
)

get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/srv/AddTwoInts.srv" NAME_WE)
add_custom_target(_dronesentinelaa_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "dronesentinelaa" "/home/drones/catkin_ws/src/dronesentinelaa/srv/AddTwoInts.srv" ""
)

get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/msg/DestinoMarca.msg" NAME_WE)
add_custom_target(_dronesentinelaa_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "dronesentinelaa" "/home/drones/catkin_ws/src/dronesentinelaa/msg/DestinoMarca.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(dronesentinelaa
  "/home/drones/catkin_ws/src/dronesentinelaa/msg/Pessoa.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/dronesentinelaa
)
_generate_msg_cpp(dronesentinelaa
  "/home/drones/catkin_ws/src/dronesentinelaa/msg/Um.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/dronesentinelaa
)
_generate_msg_cpp(dronesentinelaa
  "/home/drones/catkin_ws/src/dronesentinelaa/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/dronesentinelaa
)
_generate_msg_cpp(dronesentinelaa
  "/home/drones/catkin_ws/src/dronesentinelaa/msg/DestinoMarca.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/dronesentinelaa
)

### Generating Services
_generate_srv_cpp(dronesentinelaa
  "/home/drones/catkin_ws/src/dronesentinelaa/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/dronesentinelaa
)

### Generating Module File
_generate_module_cpp(dronesentinelaa
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/dronesentinelaa
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(dronesentinelaa_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(dronesentinelaa_generate_messages dronesentinelaa_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/msg/Pessoa.msg" NAME_WE)
add_dependencies(dronesentinelaa_generate_messages_cpp _dronesentinelaa_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/msg/Um.msg" NAME_WE)
add_dependencies(dronesentinelaa_generate_messages_cpp _dronesentinelaa_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/msg/Num.msg" NAME_WE)
add_dependencies(dronesentinelaa_generate_messages_cpp _dronesentinelaa_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/srv/AddTwoInts.srv" NAME_WE)
add_dependencies(dronesentinelaa_generate_messages_cpp _dronesentinelaa_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/msg/DestinoMarca.msg" NAME_WE)
add_dependencies(dronesentinelaa_generate_messages_cpp _dronesentinelaa_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(dronesentinelaa_gencpp)
add_dependencies(dronesentinelaa_gencpp dronesentinelaa_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS dronesentinelaa_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(dronesentinelaa
  "/home/drones/catkin_ws/src/dronesentinelaa/msg/Pessoa.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/dronesentinelaa
)
_generate_msg_eus(dronesentinelaa
  "/home/drones/catkin_ws/src/dronesentinelaa/msg/Um.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/dronesentinelaa
)
_generate_msg_eus(dronesentinelaa
  "/home/drones/catkin_ws/src/dronesentinelaa/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/dronesentinelaa
)
_generate_msg_eus(dronesentinelaa
  "/home/drones/catkin_ws/src/dronesentinelaa/msg/DestinoMarca.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/dronesentinelaa
)

### Generating Services
_generate_srv_eus(dronesentinelaa
  "/home/drones/catkin_ws/src/dronesentinelaa/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/dronesentinelaa
)

### Generating Module File
_generate_module_eus(dronesentinelaa
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/dronesentinelaa
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(dronesentinelaa_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(dronesentinelaa_generate_messages dronesentinelaa_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/msg/Pessoa.msg" NAME_WE)
add_dependencies(dronesentinelaa_generate_messages_eus _dronesentinelaa_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/msg/Um.msg" NAME_WE)
add_dependencies(dronesentinelaa_generate_messages_eus _dronesentinelaa_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/msg/Num.msg" NAME_WE)
add_dependencies(dronesentinelaa_generate_messages_eus _dronesentinelaa_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/srv/AddTwoInts.srv" NAME_WE)
add_dependencies(dronesentinelaa_generate_messages_eus _dronesentinelaa_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/msg/DestinoMarca.msg" NAME_WE)
add_dependencies(dronesentinelaa_generate_messages_eus _dronesentinelaa_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(dronesentinelaa_geneus)
add_dependencies(dronesentinelaa_geneus dronesentinelaa_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS dronesentinelaa_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(dronesentinelaa
  "/home/drones/catkin_ws/src/dronesentinelaa/msg/Pessoa.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/dronesentinelaa
)
_generate_msg_lisp(dronesentinelaa
  "/home/drones/catkin_ws/src/dronesentinelaa/msg/Um.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/dronesentinelaa
)
_generate_msg_lisp(dronesentinelaa
  "/home/drones/catkin_ws/src/dronesentinelaa/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/dronesentinelaa
)
_generate_msg_lisp(dronesentinelaa
  "/home/drones/catkin_ws/src/dronesentinelaa/msg/DestinoMarca.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/dronesentinelaa
)

### Generating Services
_generate_srv_lisp(dronesentinelaa
  "/home/drones/catkin_ws/src/dronesentinelaa/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/dronesentinelaa
)

### Generating Module File
_generate_module_lisp(dronesentinelaa
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/dronesentinelaa
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(dronesentinelaa_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(dronesentinelaa_generate_messages dronesentinelaa_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/msg/Pessoa.msg" NAME_WE)
add_dependencies(dronesentinelaa_generate_messages_lisp _dronesentinelaa_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/msg/Um.msg" NAME_WE)
add_dependencies(dronesentinelaa_generate_messages_lisp _dronesentinelaa_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/msg/Num.msg" NAME_WE)
add_dependencies(dronesentinelaa_generate_messages_lisp _dronesentinelaa_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/srv/AddTwoInts.srv" NAME_WE)
add_dependencies(dronesentinelaa_generate_messages_lisp _dronesentinelaa_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/msg/DestinoMarca.msg" NAME_WE)
add_dependencies(dronesentinelaa_generate_messages_lisp _dronesentinelaa_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(dronesentinelaa_genlisp)
add_dependencies(dronesentinelaa_genlisp dronesentinelaa_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS dronesentinelaa_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(dronesentinelaa
  "/home/drones/catkin_ws/src/dronesentinelaa/msg/Pessoa.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/dronesentinelaa
)
_generate_msg_nodejs(dronesentinelaa
  "/home/drones/catkin_ws/src/dronesentinelaa/msg/Um.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/dronesentinelaa
)
_generate_msg_nodejs(dronesentinelaa
  "/home/drones/catkin_ws/src/dronesentinelaa/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/dronesentinelaa
)
_generate_msg_nodejs(dronesentinelaa
  "/home/drones/catkin_ws/src/dronesentinelaa/msg/DestinoMarca.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/dronesentinelaa
)

### Generating Services
_generate_srv_nodejs(dronesentinelaa
  "/home/drones/catkin_ws/src/dronesentinelaa/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/dronesentinelaa
)

### Generating Module File
_generate_module_nodejs(dronesentinelaa
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/dronesentinelaa
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(dronesentinelaa_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(dronesentinelaa_generate_messages dronesentinelaa_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/msg/Pessoa.msg" NAME_WE)
add_dependencies(dronesentinelaa_generate_messages_nodejs _dronesentinelaa_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/msg/Um.msg" NAME_WE)
add_dependencies(dronesentinelaa_generate_messages_nodejs _dronesentinelaa_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/msg/Num.msg" NAME_WE)
add_dependencies(dronesentinelaa_generate_messages_nodejs _dronesentinelaa_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/srv/AddTwoInts.srv" NAME_WE)
add_dependencies(dronesentinelaa_generate_messages_nodejs _dronesentinelaa_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/msg/DestinoMarca.msg" NAME_WE)
add_dependencies(dronesentinelaa_generate_messages_nodejs _dronesentinelaa_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(dronesentinelaa_gennodejs)
add_dependencies(dronesentinelaa_gennodejs dronesentinelaa_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS dronesentinelaa_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(dronesentinelaa
  "/home/drones/catkin_ws/src/dronesentinelaa/msg/Pessoa.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dronesentinelaa
)
_generate_msg_py(dronesentinelaa
  "/home/drones/catkin_ws/src/dronesentinelaa/msg/Um.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dronesentinelaa
)
_generate_msg_py(dronesentinelaa
  "/home/drones/catkin_ws/src/dronesentinelaa/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dronesentinelaa
)
_generate_msg_py(dronesentinelaa
  "/home/drones/catkin_ws/src/dronesentinelaa/msg/DestinoMarca.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dronesentinelaa
)

### Generating Services
_generate_srv_py(dronesentinelaa
  "/home/drones/catkin_ws/src/dronesentinelaa/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dronesentinelaa
)

### Generating Module File
_generate_module_py(dronesentinelaa
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dronesentinelaa
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(dronesentinelaa_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(dronesentinelaa_generate_messages dronesentinelaa_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/msg/Pessoa.msg" NAME_WE)
add_dependencies(dronesentinelaa_generate_messages_py _dronesentinelaa_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/msg/Um.msg" NAME_WE)
add_dependencies(dronesentinelaa_generate_messages_py _dronesentinelaa_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/msg/Num.msg" NAME_WE)
add_dependencies(dronesentinelaa_generate_messages_py _dronesentinelaa_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/srv/AddTwoInts.srv" NAME_WE)
add_dependencies(dronesentinelaa_generate_messages_py _dronesentinelaa_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/drones/catkin_ws/src/dronesentinelaa/msg/DestinoMarca.msg" NAME_WE)
add_dependencies(dronesentinelaa_generate_messages_py _dronesentinelaa_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(dronesentinelaa_genpy)
add_dependencies(dronesentinelaa_genpy dronesentinelaa_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS dronesentinelaa_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/dronesentinelaa)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/dronesentinelaa
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_cpp)
  add_dependencies(dronesentinelaa_generate_messages_cpp actionlib_msgs_generate_messages_cpp)
endif()
if(TARGET ar_track_alvar_msgs_generate_messages_cpp)
  add_dependencies(dronesentinelaa_generate_messages_cpp ar_track_alvar_msgs_generate_messages_cpp)
endif()
if(TARGET diagnostic_msgs_generate_messages_cpp)
  add_dependencies(dronesentinelaa_generate_messages_cpp diagnostic_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(dronesentinelaa_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET mavros_msgs_generate_messages_cpp)
  add_dependencies(dronesentinelaa_generate_messages_cpp mavros_msgs_generate_messages_cpp)
endif()
if(TARGET nav_msgs_generate_messages_cpp)
  add_dependencies(dronesentinelaa_generate_messages_cpp nav_msgs_generate_messages_cpp)
endif()
if(TARGET sensor_msgs_generate_messages_cpp)
  add_dependencies(dronesentinelaa_generate_messages_cpp sensor_msgs_generate_messages_cpp)
endif()
if(TARGET shape_msgs_generate_messages_cpp)
  add_dependencies(dronesentinelaa_generate_messages_cpp shape_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(dronesentinelaa_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET stereo_msgs_generate_messages_cpp)
  add_dependencies(dronesentinelaa_generate_messages_cpp stereo_msgs_generate_messages_cpp)
endif()
if(TARGET trajectory_msgs_generate_messages_cpp)
  add_dependencies(dronesentinelaa_generate_messages_cpp trajectory_msgs_generate_messages_cpp)
endif()
if(TARGET visualization_msgs_generate_messages_cpp)
  add_dependencies(dronesentinelaa_generate_messages_cpp visualization_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/dronesentinelaa)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/dronesentinelaa
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_eus)
  add_dependencies(dronesentinelaa_generate_messages_eus actionlib_msgs_generate_messages_eus)
endif()
if(TARGET ar_track_alvar_msgs_generate_messages_eus)
  add_dependencies(dronesentinelaa_generate_messages_eus ar_track_alvar_msgs_generate_messages_eus)
endif()
if(TARGET diagnostic_msgs_generate_messages_eus)
  add_dependencies(dronesentinelaa_generate_messages_eus diagnostic_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(dronesentinelaa_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()
if(TARGET mavros_msgs_generate_messages_eus)
  add_dependencies(dronesentinelaa_generate_messages_eus mavros_msgs_generate_messages_eus)
endif()
if(TARGET nav_msgs_generate_messages_eus)
  add_dependencies(dronesentinelaa_generate_messages_eus nav_msgs_generate_messages_eus)
endif()
if(TARGET sensor_msgs_generate_messages_eus)
  add_dependencies(dronesentinelaa_generate_messages_eus sensor_msgs_generate_messages_eus)
endif()
if(TARGET shape_msgs_generate_messages_eus)
  add_dependencies(dronesentinelaa_generate_messages_eus shape_msgs_generate_messages_eus)
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(dronesentinelaa_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET stereo_msgs_generate_messages_eus)
  add_dependencies(dronesentinelaa_generate_messages_eus stereo_msgs_generate_messages_eus)
endif()
if(TARGET trajectory_msgs_generate_messages_eus)
  add_dependencies(dronesentinelaa_generate_messages_eus trajectory_msgs_generate_messages_eus)
endif()
if(TARGET visualization_msgs_generate_messages_eus)
  add_dependencies(dronesentinelaa_generate_messages_eus visualization_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/dronesentinelaa)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/dronesentinelaa
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_lisp)
  add_dependencies(dronesentinelaa_generate_messages_lisp actionlib_msgs_generate_messages_lisp)
endif()
if(TARGET ar_track_alvar_msgs_generate_messages_lisp)
  add_dependencies(dronesentinelaa_generate_messages_lisp ar_track_alvar_msgs_generate_messages_lisp)
endif()
if(TARGET diagnostic_msgs_generate_messages_lisp)
  add_dependencies(dronesentinelaa_generate_messages_lisp diagnostic_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(dronesentinelaa_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()
if(TARGET mavros_msgs_generate_messages_lisp)
  add_dependencies(dronesentinelaa_generate_messages_lisp mavros_msgs_generate_messages_lisp)
endif()
if(TARGET nav_msgs_generate_messages_lisp)
  add_dependencies(dronesentinelaa_generate_messages_lisp nav_msgs_generate_messages_lisp)
endif()
if(TARGET sensor_msgs_generate_messages_lisp)
  add_dependencies(dronesentinelaa_generate_messages_lisp sensor_msgs_generate_messages_lisp)
endif()
if(TARGET shape_msgs_generate_messages_lisp)
  add_dependencies(dronesentinelaa_generate_messages_lisp shape_msgs_generate_messages_lisp)
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(dronesentinelaa_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET stereo_msgs_generate_messages_lisp)
  add_dependencies(dronesentinelaa_generate_messages_lisp stereo_msgs_generate_messages_lisp)
endif()
if(TARGET trajectory_msgs_generate_messages_lisp)
  add_dependencies(dronesentinelaa_generate_messages_lisp trajectory_msgs_generate_messages_lisp)
endif()
if(TARGET visualization_msgs_generate_messages_lisp)
  add_dependencies(dronesentinelaa_generate_messages_lisp visualization_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/dronesentinelaa)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/dronesentinelaa
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_nodejs)
  add_dependencies(dronesentinelaa_generate_messages_nodejs actionlib_msgs_generate_messages_nodejs)
endif()
if(TARGET ar_track_alvar_msgs_generate_messages_nodejs)
  add_dependencies(dronesentinelaa_generate_messages_nodejs ar_track_alvar_msgs_generate_messages_nodejs)
endif()
if(TARGET diagnostic_msgs_generate_messages_nodejs)
  add_dependencies(dronesentinelaa_generate_messages_nodejs diagnostic_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(dronesentinelaa_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()
if(TARGET mavros_msgs_generate_messages_nodejs)
  add_dependencies(dronesentinelaa_generate_messages_nodejs mavros_msgs_generate_messages_nodejs)
endif()
if(TARGET nav_msgs_generate_messages_nodejs)
  add_dependencies(dronesentinelaa_generate_messages_nodejs nav_msgs_generate_messages_nodejs)
endif()
if(TARGET sensor_msgs_generate_messages_nodejs)
  add_dependencies(dronesentinelaa_generate_messages_nodejs sensor_msgs_generate_messages_nodejs)
endif()
if(TARGET shape_msgs_generate_messages_nodejs)
  add_dependencies(dronesentinelaa_generate_messages_nodejs shape_msgs_generate_messages_nodejs)
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(dronesentinelaa_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET stereo_msgs_generate_messages_nodejs)
  add_dependencies(dronesentinelaa_generate_messages_nodejs stereo_msgs_generate_messages_nodejs)
endif()
if(TARGET trajectory_msgs_generate_messages_nodejs)
  add_dependencies(dronesentinelaa_generate_messages_nodejs trajectory_msgs_generate_messages_nodejs)
endif()
if(TARGET visualization_msgs_generate_messages_nodejs)
  add_dependencies(dronesentinelaa_generate_messages_nodejs visualization_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dronesentinelaa)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dronesentinelaa\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dronesentinelaa
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_py)
  add_dependencies(dronesentinelaa_generate_messages_py actionlib_msgs_generate_messages_py)
endif()
if(TARGET ar_track_alvar_msgs_generate_messages_py)
  add_dependencies(dronesentinelaa_generate_messages_py ar_track_alvar_msgs_generate_messages_py)
endif()
if(TARGET diagnostic_msgs_generate_messages_py)
  add_dependencies(dronesentinelaa_generate_messages_py diagnostic_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(dronesentinelaa_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET mavros_msgs_generate_messages_py)
  add_dependencies(dronesentinelaa_generate_messages_py mavros_msgs_generate_messages_py)
endif()
if(TARGET nav_msgs_generate_messages_py)
  add_dependencies(dronesentinelaa_generate_messages_py nav_msgs_generate_messages_py)
endif()
if(TARGET sensor_msgs_generate_messages_py)
  add_dependencies(dronesentinelaa_generate_messages_py sensor_msgs_generate_messages_py)
endif()
if(TARGET shape_msgs_generate_messages_py)
  add_dependencies(dronesentinelaa_generate_messages_py shape_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(dronesentinelaa_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET stereo_msgs_generate_messages_py)
  add_dependencies(dronesentinelaa_generate_messages_py stereo_msgs_generate_messages_py)
endif()
if(TARGET trajectory_msgs_generate_messages_py)
  add_dependencies(dronesentinelaa_generate_messages_py trajectory_msgs_generate_messages_py)
endif()
if(TARGET visualization_msgs_generate_messages_py)
  add_dependencies(dronesentinelaa_generate_messages_py visualization_msgs_generate_messages_py)
endif()
