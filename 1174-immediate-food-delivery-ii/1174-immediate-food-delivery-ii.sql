# Write your MySQL query statement below
SELECT ROUND(
        SUM(
        CASE
            WHEN first_order_data.first_order_date = Delivery.customer_pref_delivery_date
                THEN 1
            ELSE 0
        END
        )*100/COUNT(first_order_data.first_order_date)
        ,2) as immediate_percentage
FROM Delivery
INNER JOIN (SELECT 
        customer_id,
        MIN(order_date) as first_order_date
    FROM Delivery 
    GROUP BY customer_id) as first_order_data

ON first_order_date = order_date
    AND first_order_data.customer_id = Delivery.customer_id;