# Write your MySQL query statement below
SELECT B.product_name, A.year, A.price
FROM Sales as A
LEFT JOIN Product as B
ON A.product_id = B.product_id;