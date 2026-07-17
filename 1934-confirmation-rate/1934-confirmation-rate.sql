# Write your MySQL query statement below
SELECT s.user_id,
    ROUND(
        AVG(
            CASE
                WHEN c.action = 'confirmed' THEN 1.00
                ELSE 0
            END
            ),
            2
        ) as confirmation_rate
FROM Signups as s
LEFT JOIN Confirmations as c
ON s.user_id = c.user_id
GROUP BY s.user_id;