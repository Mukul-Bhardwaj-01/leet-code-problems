# Write your MySQL query statement below
SELECT R.contest_id,
    ROUND(COUNT(R.user_id) * 100/(SELECT COUNT(user_id) FROM Users), 2) as percentage
FROM Register as R
GROUP BY R.contest_id
ORDER BY percentage desc, R.contest_id asc;