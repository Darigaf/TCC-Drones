; Auto-generated. Do not edit!


(cl:in-package dronesentinelaa-msg)


;//! \htmlinclude DestinoMarca.msg.html

(cl:defclass <DestinoMarca> (roslisp-msg-protocol:ros-message)
  ((name
    :reader name
    :initarg :name
    :type cl:string
    :initform "")
   (distancia
    :reader distancia
    :initarg :distancia
    :type cl:float
    :initform 0.0))
)

(cl:defclass DestinoMarca (<DestinoMarca>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DestinoMarca>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DestinoMarca)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dronesentinelaa-msg:<DestinoMarca> is deprecated: use dronesentinelaa-msg:DestinoMarca instead.")))

(cl:ensure-generic-function 'name-val :lambda-list '(m))
(cl:defmethod name-val ((m <DestinoMarca>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dronesentinelaa-msg:name-val is deprecated.  Use dronesentinelaa-msg:name instead.")
  (name m))

(cl:ensure-generic-function 'distancia-val :lambda-list '(m))
(cl:defmethod distancia-val ((m <DestinoMarca>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dronesentinelaa-msg:distancia-val is deprecated.  Use dronesentinelaa-msg:distancia instead.")
  (distancia m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DestinoMarca>) ostream)
  "Serializes a message object of type '<DestinoMarca>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'name))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'distancia))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DestinoMarca>) istream)
  "Deserializes a message object of type '<DestinoMarca>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'distancia) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DestinoMarca>)))
  "Returns string type for a message object of type '<DestinoMarca>"
  "dronesentinelaa/DestinoMarca")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DestinoMarca)))
  "Returns string type for a message object of type 'DestinoMarca"
  "dronesentinelaa/DestinoMarca")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DestinoMarca>)))
  "Returns md5sum for a message object of type '<DestinoMarca>"
  "9d9d507dbde14f38120241599b9deca4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DestinoMarca)))
  "Returns md5sum for a message object of type 'DestinoMarca"
  "9d9d507dbde14f38120241599b9deca4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DestinoMarca>)))
  "Returns full string definition for message of type '<DestinoMarca>"
  (cl:format cl:nil "string name # Name of the landmark~%float64 distancia # Distance to the landmark~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DestinoMarca)))
  "Returns full string definition for message of type 'DestinoMarca"
  (cl:format cl:nil "string name # Name of the landmark~%float64 distancia # Distance to the landmark~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DestinoMarca>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'name))
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DestinoMarca>))
  "Converts a ROS message object to a list"
  (cl:list 'DestinoMarca
    (cl:cons ':name (name msg))
    (cl:cons ':distancia (distancia msg))
))
