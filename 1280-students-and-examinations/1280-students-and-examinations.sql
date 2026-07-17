# Write your MySQL query statement below
SELECT cp.student_id, 
        cp.student_name, 
        cp.subject_name, 
        COUNT(e.student_id) as attended_exams
FROM (SELECT * FROM students CROSS JOIN subjects) as cp
LEFT JOIN examinations as e
ON cp.student_id = e.student_id AND cp.subject_name = e.subject_name
GROUP BY cp.student_id, cp.student_name, cp.subject_name
ORDER BY cp.student_id, cp.subject_name;