select count(FI.FISH_TYPE) as FISH_COUNT, FNI.FISH_NAME
    from FISH_INFO FI
    join FISH_NAME_INFO FNI on FI.FISH_TYPE = FNI.FISH_TYPE
    group by FNI.FISH_NAME
    order by FISH_COUNT desc;