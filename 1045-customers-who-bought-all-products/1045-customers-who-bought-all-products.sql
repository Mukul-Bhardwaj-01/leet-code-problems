# Write your MySQL query statement below
SELECT customer_id
FROM Customer as C1
GROUP BY customer_id
HAVING COUNT(DISTINCT C1.product_key) = (SELECT COUNT(product_key) FROM Product);