;; Auto-generated. Do not edit!


(when (boundp 'dronesentinelaa::Um)
  (if (not (find-package "DRONESENTINELAA"))
    (make-package "DRONESENTINELAA"))
  (shadow 'Um (find-package "DRONESENTINELAA")))
(unless (find-package "DRONESENTINELAA::UM")
  (make-package "DRONESENTINELAA::UM"))

(in-package "ROS")
;;//! \htmlinclude Um.msg.html


(defclass dronesentinelaa::Um
  :super ros::object
  :slots (_um ))

(defmethod dronesentinelaa::Um
  (:init
   (&key
    ((:um __um) 0.0)
    )
   (send-super :init)
   (setq _um (float __um))
   self)
  (:um
   (&optional __um)
   (if __um (setq _um __um)) _um)
  (:serialization-length
   ()
   (+
    ;; float32 _um
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _um
       (sys::poke _um (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _um
     (setq _um (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get dronesentinelaa::Um :md5sum-) "618dab28f65c47698004ab746e672599")
(setf (get dronesentinelaa::Um :datatype-) "dronesentinelaa/Um")
(setf (get dronesentinelaa::Um :definition-)
      "float32 um

")



(provide :dronesentinelaa/Um "618dab28f65c47698004ab746e672599")


