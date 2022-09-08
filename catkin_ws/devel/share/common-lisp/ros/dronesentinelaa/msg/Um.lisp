; Auto-generated. Do not edit!


(cl:in-package dronesentinelaa-msg)


;//! \htmlinclude Um.msg.html

(cl:defclass <Um> (roslisp-msg-protocol:ros-message)
  ((um
    :reader um
    :initarg :um
    :type cl:float
    :initform 0.0))
)

(cl:defclass Um (<Um>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Um>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Um)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dronesentinelaa-msg:<Um> is deprecated: use dronesentinelaa-msg:Um instead.")))

(cl:ensure-generic-function 'um-val :lambda-list '(m))
(cl:defmethod um-val ((m <Um>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dronesentinelaa-msg:um-val is deprecated.  Use dronesentinelaa-msg:um instead.")
  (um m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Um>) ostream)
  "Serializes a message object of type '<Um>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'um))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Um>) istream)
  "Deserializes a message object of type '<Um>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'um) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Um>)))
  "Returns string type for a message object of type '<Um>"
  "dronesentinelaa/Um")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Um)))
  "Returns string type for a message object of type 'Um"
  "dronesentinelaa/Um")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Um>)))
  "Returns md5sum for a message object of type '<Um>"
  "618dab28f65c47698004ab746e672599")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Um)))
  "Returns md5sum for a message object of type 'Um"
  "618dab28f65c47698004ab746e672599")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Um>)))
  "Returns full string definition for message of type '<Um>"
  (cl:format cl:nil "float32 um~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Um)))
  "Returns full string definition for message of type 'Um"
  (cl:format cl:nil "float32 um~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Um>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Um>))
  "Converts a ROS message object to a list"
  (cl:list 'Um
    (cl:cons ':um (um msg))
))
