select distinct FI.ID, FNI.FISH_NAME, FI.LENGTH
    from FISH_INFO FI
    join FISH_NAME_INFO FNI on FI.FISH_TYPE = FNI.FISH_TYPE
    where FI.LENGTH = 
        (select max(LENGTH) from FISH_INFO where FISH_TYPE = FI.FISH_TYPE)
    order by ID;