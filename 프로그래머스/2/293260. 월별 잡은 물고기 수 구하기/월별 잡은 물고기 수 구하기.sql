select count(*) as 'FISH_COUNT', month(time) as 'MONTH' from FISH_INFO 
group by month(time)
order by month(time)