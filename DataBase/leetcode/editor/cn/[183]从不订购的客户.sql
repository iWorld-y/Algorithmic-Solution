#某网站包含两个表，Customers 表和 Orders 表。编写一个 SQL 查询，找出所有从不订购任何东西的客户。 
#
# Customers 表： 
#
# +----+-------+
#| Id | Name  |
#+----+-------+
#| 1  | Joe   |
#| 2  | Henry |
#| 3  | Sam   |
#| 4  | Max   |
#+----+-------+
# 
#
# Orders 表： 
#
# +----+------------+
#| Id | CustomerId |
#+----+------------+
#| 1  | 3          |
#| 2  | 1          |
#+----+------------+
# 
#
# 例如给定上述表格，你的查询应返回： 
#
# +-----------+
#| Customers |
#+-----------+
#| Henry     |
#| Max       |
#+-----------+
# 
# Related Topics 数据库 👍 249 👎 0

#leetcode submit region begin(Prohibit modification and deletion)
# Write your MySQL query statement below
#leetcode submit region end(Prohibit modification and deletion)

# 2021-11-14 20:29:13
# drop database leetcode;
# create database leetcode;
# use leetcode;
# Create table If Not Exists Customers (id int, name varchar(255));
# Create table If Not Exists Orders (id int, customerId int);
# Truncate table Customers;
# insert into Customers (id, name) values ('1', 'Joe');
# insert into Customers (id, name) values ('2', 'Henry');
# insert into Customers (id, name) values ('3', 'Sam');
# insert into Customers (id, name) values ('4', 'Max');
# Truncate table Orders;
# insert into Orders (id, customerId) values ('1', '3');
# insert into Orders (id, customerId) values ('2', '1');

# SELECT Name Customers
# FROM Customers
# WHERE Id NOT IN (SELECT customerId FROM Orders);
SELECT name Customers
FROM Customers A
         LEFT JOIN Orders B ON A.id = B.customerId
WHERE customerId IS NULL;