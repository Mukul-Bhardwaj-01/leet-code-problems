# Write your MySQL query statement below
SELECT e.name
FROM employee as e
JOIN employee as emp
ON e.id = emp.managerId
GROUP BY e.id, e.name
HAVING COUNT(*) >= 5;