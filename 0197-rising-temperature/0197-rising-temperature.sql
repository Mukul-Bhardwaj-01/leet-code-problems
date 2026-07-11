# Write your MySQL query statement below
SELECT W1.id
FROM Weather W1
JOIN Weather W2
ON W1.temperature > W2.temperature AND DATE_SUB(W1.recordDate, INTERVAL 1 DAY) = W2.recordDate;