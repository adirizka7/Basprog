(define (mod n)
   (if (= n 0)
       0
       (+ (modulo n 10)
       (mod (/ (- n (modulo n 10)) 10)))
   )
  )

(display (mod (read)))
(newline)