select ID,
    case
        when PERCENT_RANK() OVER (order by SIZE_OF_COLONY desc) <= 0.25 then 'CRITICAL'
        when PERCENT_RANK() OVER (order by SIZE_OF_COLONY desc) > 0.25 
            and PERCENT_RANK() OVER (order by SIZE_OF_COLONY desc) <= 0.5 then 'HIGH'
        when PERCENT_RANK() OVER (order by SIZE_OF_COLONY desc) > 0.5 
            and PERCENT_RANK() OVER (order by SIZE_OF_COLONY desc) <= 0.75 then 'MEDIUM'
        else 'LOW'
    end as 'COLONY_NAME'
from ECOLI_DATA
order by id;