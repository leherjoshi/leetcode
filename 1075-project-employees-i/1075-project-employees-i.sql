# Write your MySQL query statement below
select p.project_id,Round(avg(e.experience_years),2) as average_years
from Project  p join Employee e
ON p.employee_id = e.employee_id
GROUP BY p.project_id;