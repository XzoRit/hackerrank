(ns hackerrank.core-test
  (:require [clojure.test :refer :all]
            [hackerrank.core :refer :all]))

(deftest test-list-replication
    (is (= () (list-replication 0 ())))
    (is (= () (list-replication 9 ())))
    (is (= '(1) (list-replication 1 '(1))))
    (is (= '(1 22 333) (list-replication 1 '(1 22 333))))
    (is (= '(1 1 1 22 22 22 333 333 333) (list-replication 3 '(1 22 333)))))

(deftest test-filter-array
    (is (= () (filter-array 5 ())))
    (is (= '(0) (filter-array 1 '(0))))
    (is (= '(0) (filter-array 1 '(0 1))))
    (is (= '(4 3) (filter-array 5 '(4 7 5 3)))))

(deftest test-filter-position
    (is (= () (filter-position ())))
    (is (= () (filter-position '(0))))
    (is (= '(1) (filter-position '(0 1))))
    (is (= '(5 4 7 8) (filter-position '(2 5 3 4 6 7 9 8)))))

(deftest test-array-of-n-elements
    (is (= () (array-of-n-elements 0)))
    (is (= '(0) (array-of-n-elements 1)))
    (is (= '(0 1 2) (array-of-n-elements 3)))
    (is (= '(0 1 2 3 4 5 6 7 8 9) (array-of-n-elements 10))))
