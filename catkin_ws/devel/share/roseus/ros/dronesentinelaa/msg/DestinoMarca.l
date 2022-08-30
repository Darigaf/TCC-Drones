;; Auto-generated. Do not edit!


(when (boundp 'dronesentinelaa::DestinoMarca)
  (if (not (find-package "DRONESENTINELAA"))
    (make-package "DRONESENTINELAA"))
  (shadow 'DestinoMarca (find-package "DRONESENTINELAA")))
(unless (find-package "DRONESENTINELAA::DESTINOMARCA")
  (make-package "DRONESENTINELAA::DESTINOMARCA"))

(in-package "ROS")
;;//! \htmlinclude DestinoMarca.msg.html


(defclass dronesentinelaa::DestinoMarca
  :super ros::object
  :slots (_name _distancia ))

(defmethod dronesentinelaa::DestinoMarca
  (:init
   (&key
    ((:name __name) "")
    ((:distancia __distancia) 0.0)
    )
   (send-super :init)
   (setq _name (string __name))
   (setq _distancia (float __distancia))
   self)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:distancia
   (&optional __distancia)
   (if __distancia (setq _distancia __distancia)) _distancia)
  (:serialization-length
   ()
   (+
    ;; string _name
    4 (length _name)
    ;; float64 _distancia
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;; float64 _distancia
       (sys::poke _distancia (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; float64 _distancia
     (setq _distancia (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get dronesentinelaa::DestinoMarca :md5sum-) "9d9d507dbde14f38120241599b9deca4")
(setf (get dronesentinelaa::DestinoMarca :datatype-) "dronesentinelaa/DestinoMarca")
(setf (get dronesentinelaa::DestinoMarca :definition-)
      "string name # Name of the landmark
float64 distancia # Distance to the landmark

")



(provide :dronesentinelaa/DestinoMarca "9d9d507dbde14f38120241599b9deca4")


