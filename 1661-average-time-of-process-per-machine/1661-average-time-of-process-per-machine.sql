# Write your MySQL query statement below
select a.machine_id ,Round(avg(b.timestamp-a.timestamp) ,3) as processing_time FROM Activity a
JOIN Activity b
ON a.machine_id = b.machine_id

WHERE a.activity_type = 'start'
  AND b.activity_type = 'end'
GROUP BY a.machine_id;