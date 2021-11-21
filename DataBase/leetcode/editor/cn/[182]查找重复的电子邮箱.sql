#编写一个 SQL 查询，查找 Person 表中所有重复的电子邮箱。 
#
# 示例： 
#
# +----+---------+
#| Id | Email   |
#+----+---------+
#| 1  | a@b.com |
#| 2  | c@d.com |
#| 3  | a@b.com |
#+----+---------+
# 
#
# 根据以上输入，你的查询应返回以下结果： 
#
# +---------+
#| Email   |
#+---------+
#| a@b.com |
#+---------+
# 
#
# 说明：所有电子邮箱都是小写字母。 
# Related Topics 数据库 👍 312 👎 0

#leetcode submit region begin(Prohibit modification and deletion)
# Write your MySQL query statement below
#leetcode submit region end(Prohibit modification and deletion)

# 2021-11-14 20:17:11
# drop database leetcode;
# create database leetcode;
# use leetcode;
#
SELECT Email
FROM Person
GROUP BY Email
HAVING COUNT(Email) > 1;