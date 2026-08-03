# Write your MySQL query statement below
select DATE_FORMAT(trans_date, '%Y-%m') as month,country,
count(*) as trans_count,
SUM(CASE WHEN state = 'approved' THEN 1 ELSE 0 END) AS approved_count,
sum(amount)as trans_total_amount,
sum(case when state='approved' then amount else 0 end) as approved_total_amount

from Transactions 
GROUP BY DATE_FORMAT(trans_date, '%Y-%m'), country;