# Write your MySQL query statement below
SELECT S.product_id, first_sale.first_year, S.quantity, S.price
FROM Sales as S
INNER JOIN
(SELECT product_id, MIN(year) as first_year FROM Sales GROUP BY product_id) as first_sale
ON S.product_id = first_sale.product_id AND S.year = first_sale.first_year;