#有一个courses 表 ，有: student (学生) 和 class (课程)。 
#
# 请列出所有超过或等于5名学生的课。 
#
# 例如，表： 
#
# +---------+------------+
#| student | class      |
#+---------+------------+
#| A       | Math       |
#| B       | English    |
#| C       | Math       |
#| D       | Biology    |
#| E       | Math       |
#| F       | Computer   |
#| G       | Math       |
#| H       | Math       |
#| I       | Math       |
#+---------+------------+
# 
#
# 应该输出: 
#
# +---------+
#| class   |
#+---------+
#| Math    |
#+---------+
# 
#
# 
#
# 提示： 
#
# 
# 学生在每个课中不应被重复计算。 
# 
# Related Topics 数据库 👍 218 👎 0

#leetcode submit region begin(Prohibit modification and deletion)
# Write your MySQL query statement below
#leetcode submit region end(Prohibit modification and deletion)

# 2021-11-14 21:33:10
SELECT class
FROM (SELECT class,
             COUNT(DISTINCT student) AS num
      FROM Courses
      GROUP BY class) AS temp_table
WHERE num >= 5;
SELECT class, COUNT(DISTINCT student) AS num
FROM Courses
GROUP BY class;