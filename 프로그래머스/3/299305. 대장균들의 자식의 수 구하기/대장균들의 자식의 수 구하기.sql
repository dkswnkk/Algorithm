select ED1.ID, count(ED2.ID) as CHILD_COUNT
    from ECOLI_DATA ED1
    left join ECOLI_DATA ED2 on ED1.ID = ED2.PARENT_ID
    group by ED1.ID
    order by ED1.ID