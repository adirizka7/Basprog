(define (nilai a b c)
  (/ (+ a b c) 3)
)

(define (mutu a b c)
  (cond
    ((>= (nilai a b c) 80)"A")
    ((>= (nilai a b c) 60)"B")
    ((>= (nilai a b c) 40)"C")
    ((>= (nilai a b c) 20)"D")
    ((>= (nilai a b c) 0)"E")
    ))

(display (mutu (read) (read) (read)))
(newline)