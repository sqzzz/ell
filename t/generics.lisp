(defclass super-1)
(defclass super-2)
(defclass c (super-1 super-2))
(defmethod m ((s super-1)) "super 1")
(defmethod m ((s super-2)) "super 2")
(defmethod m ((c c)) "c")
(m (make c))