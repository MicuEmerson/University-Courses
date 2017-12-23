
(defun substituie (X E L1)
	(cond
		((and (atom X) (= X E)) L1)
		((and (atom X) (not (= X E))) (list X))
		(T  (mapcan #'(lambda (X) (substituie X E L1)) X))
	)
)
; gresitaaa idk why