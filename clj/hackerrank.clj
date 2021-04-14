(ns xzr
  (:use clojure.test))

(defn list-replication [num lst]
    (->>
        (map #(repeat num %) lst)
        (flatten)))
                
(deftest test-list-replication
    (is (= () (list-replication 0 ())))
    (is (= () (list-replication 9 ())))
    (is (= '(1) (list-replication 1 '(1))))
    (is (= '(1 22 333) (list-replication 1 '(1 22 333))))
    (is (= '(1 1 1 22 22 22 333 333 333) (list-replication 3 '(1 22 333)))))

(defn filter-array [delim lst]
    (for [x lst :when (< x delim)] x))
  
(deftest test-filter-array
    (is (= () (filter-array 5 ())))
    (is (= '(0) (filter-array 1 '(0))))
    (is (= '(0) (filter-array 1 '(0 1))))
    (is (= '(4 3) (filter-array 5 '(4 7 5 3)))))

(defn filter-position [lst]
    (for [a (range (count lst)) :when (odd? a)]
        (nth lst a)))
  
(deftest test-filter-position
    (is (= () (filter-position ())))
    (is (= () (filter-position '(0))))
    (is (= '(1) (filter-position '(0 1))))
    (is (= '(5 4 7 8) (filter-position '(2 5 3 4 6 7 9 8)))))

(run-tests 'xzr)