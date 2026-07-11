# Write your MySQL query statement below
SELECT A1.machine_id, ROUND(AVG(A1.timestamp - A2.timestamp),3) processing_time
FROM activity A1
JOIN activity A2
ON A1.machine_id = A2.machine_id AND A1.process_id = A2.process_id AND A1.activity_type = 'end' AND A2.activity_type = 'start'
GROUP BY A1.machine_id;