# Write your MySQL query statement below
SELECT E1.employee_id, E1.name,
    COUNT(E2.reports_to) as reports_count, 
    ROUND(AVG(E2.age),0) as average_age
FROM Employees as E1
JOIN Employees as E2
ON E2.reports_to = E1.employee_id
GROUP BY E1.employee_id
ORDER BY E1.employee_id;