select name
from (select managerId, count(*) as cnt
      from employee
      group by managerId) as tm
         join employee
              on tm.managerId = employee.id
where tm.cnt >= 5