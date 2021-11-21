#Employee 表包含所有员工，他们的经理也属于员工。每个员工都有一个 Id，此外还有一列对应员工的经理的 Id。 
#
# +----+-------+--------+-----------+
#| Id | Name  | Salary | ManagerId |
#+----+-------+--------+-----------+
#| 1  | Joe   | 70000  | 3         |
#| 2  | Henry | 80000  | 4         |
#| 3  | Sam   | 60000  | NULL      |
#| 4  | Max   | 90000  | NULL      |
#+----+-------+--------+-----------+
# 
#
# 给定 Employee 表，编写一个 SQL 查询，该查询可以获取收入超过他们经理的员工的姓名。在上面的表格中，Joe 是唯一一个收入超过他的经理的员工。 
#
#
# +----------+
#| Employee |
#+----------+
#| Joe      |
#+----------+
# 
# Related Topics 数据库 👍 428 👎 0

#leetcode submit region begin(Prohibit modification and deletion)
# Write your MySQL query statement below
#leetcode submit region end(Prohibit modification and deletion)

# 2021-11-14 20:09:44
# drop database leetcode;
# create database leetcode;
# use leetcode;
# Create table If Not Exists Employee (id int, name varchar(255), salary int, managerId int);
# Truncate table Employee;
# insert into Employee (id, name, salary, managerId) values ('1', 'Joe', '70000', '3');
# insert into Employee (id, name, salary, managerId) values ('2', 'Henry', '80000', '4');
# insert into Employee (id, name, salary, managerId) values ('3', 'Sam', '60000', NULL);
# insert into Employee (id, name, salary, managerId) values ('4', 'Max', '90000', NULL);

SELECT A.name Employee
FROM Employee AS A,
     Employee AS B
WHERE A.managerId = B.id
  AND A.salary > B.salary;