# Write your MySQL query statement below
SELECT ROUND(SUM(
    CASE 
        WHEN DATE_ADD(first_activity.first_login, INTERVAL 1 DAY) = A.event_date
            THEN 1
            ELSE 0
    END
)/COUNT(DISTINCT A.player_id), 2) as fraction
FROM Activity as A
INNER JOIN (
    SELECT player_id, MIN(event_date) as first_login FROM Activity GROUP BY player_id
    ) as first_activity
ON A.player_id = first_activity.player_id;