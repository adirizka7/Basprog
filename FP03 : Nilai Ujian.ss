(define (kondisi a b c)
  (if (= c 0)
     (* a b)
     (+ a b c))
)

(display (kondisi (read) (read) (read)))
(newline)