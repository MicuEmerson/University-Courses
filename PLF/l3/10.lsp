
(defun replaceNode (X A B)
	(cond	
		((and (atom X) (equal A X)) B)
		((and (atom X) (not (equal A X))) X)
		(T (mapcar #'(lambda (X) (replaceNode X A B)) X))
	)
)