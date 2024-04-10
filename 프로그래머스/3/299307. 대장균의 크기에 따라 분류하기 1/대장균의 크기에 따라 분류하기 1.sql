select id, 
    case  
         when SIZE_OF_COLONY > 1000 then 'HIGH'
         when SIZE_OF_COLONY > 100 and SIZE_OF_COLONY <= 1000 then 'MEDIUM'
         else 'LOW'
         end
    as SIZE
    from ECOLI_DATA
    order by id;