create database bigwork;

use bigwork;
drop table if exists bigwork.mealrating;

-- create table bigwork.mealrating
-- (
--     UserID     STRING   COMMENT "userid",
--     MealID     STRING   COMMENT "mealid",
--     Rating     FLOAT    COMMENT "rating",
--     ReviewTime INT      COMMENT "ReviewTime",
--     Review     STRING   COMMENT "Review"
-- ) row format delimited fields terminated by ',';

create table bigwork.mealrating
(
    UserID     STRING   COMMENT "userid",
    MealID     STRING   COMMENT "mealid",
    Rating     FLOAT    COMMENT "rating",
    ReviewTime INT      COMMENT "ReviewTime",
    Review     STRING   COMMENT "Review"
) stored as parquet;

load data local inpath '/data/mealrating_1.csv' into table bigwork.mealrating;
select *
from bigwork.mealrating
limit 10;

-- 导入 meal_list
drop table if exists bigwork.meal_list;
create table if not exists bigwork.meal_list
(
    Mon    int      comment "Mon",
    MealID string   comment "MealID",
    name   string   comment "mealname"
) row format delimited fields terminated by ',';
load data local inpath '/data/meal_list.txt' into table bigwork.meal_list;
select *
from bigwork.meal_list
limit 10;

-- 查找缺失值
select UserID, MealID, Rating, ReviewTime, Review
from mealrating
where UserID is null
   or MealID is null
   or Rating is null
   or ReviewTime is null
   or Review is null;

-- 删除空数据
insert overwrite table mealrating
select *
from mealrating
where Review is null;

-- 得出无重复值结论
select count(1) - count(DISTINCT UserID, MealID, Rating, ReviewTime, Review)
from mealrating;

/*
 * 已经无重复值了就不用再去重
*/
-- 去重
-- insert overwrite table mealrating
-- select distinct UserID, MealID, Rating, ReviewTime, Review
-- from mealrating;

-- 根据用户评分数据统计日销量和日用户量
-- 2017年五月一号日销量
select count(1)
from bigwork.mealrating
where ReviewTime between 1493654400 and 1498576000;

-- 2017年六月十号日用户量
select count(DISTINCT UserID)
from bigwork.mealrating
where ReviewTime between 1497024000 and 1497110399;

-- 统计同时有评分和评分内容的记录
select count(1)
from mealrating
where Rating is not null
  and Review is not null;

-- 分析用户的评分分布情况
select *,
       cast(Rating / (sum(Rating) over ()) as DECIMAL(8, 2)) as rat_percent
from (select Rating, count(1) rat_num, CAST(sum(Rating) / count(1) as DECIMAL(8, 2)) avg_rat
      from mealrating
      group by Rating) as p
ORDER BY rat_percent desc;

-- 统计10大热销菜品
select name, count(name) as frequency
from mealrating
         join meal_list on mealrating.MealID = meal_list.MealID
group by name
order by frequency desc
limit 10;

-- 统计10大评分为5的热销菜品
select name, Rating, count(name) as frequency
from mealrating
         join meal_list on mealrating.MealID = meal_list.MealID
where Rating = 5
group by name, Rating
order by frequency desc
limit 10;

-- 统计单日评分超过2次的用户数
select count(1)
from (select ReviewTime, UserID, count(1) from mealrating group by ReviewTime, UserID having count(1) > 2) as tmp;

-- 找出评分次数超过两次的用户中，每个用户评分最高的记录
select UserID, max(Rating)
from mealrating
group by UserID
having UserID in (select UserID from mealrating group by UserID HAVING count(MealID) > 2);
