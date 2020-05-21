(defun rand (floor ceiling / mul add HashRange)
  (setq mul 100001333)
  (setq add 100000223)
  (setq HashRange 1000000000)
  (+ 
    (*
      (/ (rem (+ (* (getvar "cputicks") mul) add) HashRange) HashRange)
      (- ceiling floor)
    )
    floor
  )
)

(defun RandomCircle (coord0 coord1 radmin radmax num / ctr xmin xmax ymin ymax)
  (setq ctr num)
  (setq xmin (min (car coord0) (car coord1)))
  (setq xmax (max (car coord0) (car coord1)))
  (setq ymin (min (cadr coord0) (cadr coord1)))
  (setq ymax (max (cadr coord0) (cadr coord1)))
  (while (> ctr 0)
    (command-s
      "_circle"
      (strcat
        (rtos (rand xmin xmax))
        ","
        (rtos (rand ymin ymax))
      ) 
      (rand radmin radmax)
    )
    (setq ctr (1- ctr))
  )
)

(defun c:randomcircle (/ coord0 coord1 radmin radmax num)
  (prompt "\nfirstly,specify the range of center for drawing circle by two diagonal point...")
  (setq coord0 (getpoint "\nfirst point: "))
  (setq coord1 (getpoint "\nsecond point: "))
  (prompt "\nthen, specify the range of radius by min and man...")
  (setq radmin (getreal "\nmin: "))
  (setq radmax (getreal "\nmax: "))
  (setq num (getreal "lastly, enter number for drawing"))
  (RandomCircle coord0 coord1 radmin radmax num)
)
