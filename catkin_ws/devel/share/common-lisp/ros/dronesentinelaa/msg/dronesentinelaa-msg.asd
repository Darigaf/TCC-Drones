
(cl:in-package :asdf)

(defsystem "dronesentinelaa-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "DestinoMarca" :depends-on ("_package_DestinoMarca"))
    (:file "_package_DestinoMarca" :depends-on ("_package"))
    (:file "Num" :depends-on ("_package_Num"))
    (:file "_package_Num" :depends-on ("_package"))
    (:file "Pessoa" :depends-on ("_package_Pessoa"))
    (:file "_package_Pessoa" :depends-on ("_package"))
    (:file "Um" :depends-on ("_package_Um"))
    (:file "_package_Um" :depends-on ("_package"))
  ))