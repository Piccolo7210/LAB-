-- @E:\sql\grad\ex.sql
-- SELECT distinct student 
-- FROM taken T
-- where T.course in (select course
-- 		   from required);

-- SELECT Student FROM Taken
-- EXCEPT
-- SELECT Student FROM (
--     SELECT Student,Course
--     FROM (select Student FROM Taken), Required
--     EXCEPT
--     SELECT Student,Course FROM Taken
-- );

-- SELECT Student
-- From Taken
-- WHERE Course IN (SELECT Course FROM Required)
-- GROUP BY Student
-- HAVING COUNT(*) = (SELECT COUNT(*) FROM Required);

-- select CUSTOMER_NAME
-- from DEPOSITOR D,ACCOUNT A
-- where D.ACCOUNT_NUMBER = A.ACCOUNT_NUMBER and
-- BRANCH_NAME 
-- select BRANCH_NAME
-- from BRANCH
-- where BRANCH_CITY = 'Brooklyn'

select distinct CUSTOMER_NAME
from DEPOSITOR
minus 
(select CUSTOMER_NAME
from
(select distinct CUSTOMER_NAME, BRANCH_NAME
from DEPOSITOR D, BRANCH B
where BRANCH_CITY = 'Brooklyn'
minus
select CUSTOMER_NAME, BRANCH_NAME
from DEPOSITOR D, ACCOUNT A
where D.ACCOUNT_NUMBER = A.ACCOUNT_NUMBER));