# Write your MySQL query statement below
SELECT Id
FROM Weather today
WHERE Temperature > (
  SELECT Temperature
  FROM Weather yesterday
  WHERE TO_DAYS(today.RecordDate) - TO_DAYS(yesterday.RecordDate) = 1
)