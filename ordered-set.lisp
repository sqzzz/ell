(defpackage Ordered-Type ()
  (interface
    (deftype <t>)
    (defun compare (<t> <t> -> <int>))))

(defpackage Set ()
  (interface
    (deftype <t>)
    (deftype <elt>)
    (defun make (-> <t>))
    (defun add (<t> <elt>))))

(defpackage Set-Impl ((Elt Ordered-Type))
  (implementation
    (defclass <t> (elements <list> init: (list)))
    (deftype <elt> Elt::<t>)
    (defun make (-> <t>) (make-t))
    (defun add (<t> <elt>) (... (Elt::compare elt ...) ...))))

(defpackage Abstract-Set ((Elt Ordered-Type) -> (Set <elt> = Elt::<t>))
  Set-Impl)

;;;

(defpackage CI-String ()
  (implementation
    (deftype <t> <str>)
    (defun compare ((s1 <str>) (s2 <str>) -> <int>)
      (declare inline)
      (strcmp (tolower s1) (tolower s2)))))

(defpackage CI-String-Set ()
  (Abstract-Set CI-String))

;;;

(defpackage My ()
  (implementation
    (use S = CI-String-Set)
    (let set = (S::make)
      (S::add set "foo"))))

;; defunctorizes to

(defpackage My ()
  (implementation
    (let set = (Set-Impl##CI-String::make)
      (Set-Impl##CI-String::add set "foo"))))

(defpackage Set-Impl##CI-String ()
  (implementation
    (defclass <t> (elements <list> init: (list)))
    (deftype <elt> CI-String::<t>)
    (defun make (-> <t>) (make-t))
    (defun add (<t> <elt>) (... (strcmp (tolower elt) (tolower ...)) ...)))) ; inlining
   

;; http://caml.inria.fr/pub/docs/manual-ocaml/manual004.html
