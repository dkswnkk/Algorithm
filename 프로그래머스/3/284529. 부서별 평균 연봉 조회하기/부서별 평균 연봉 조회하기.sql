select HD.DEPT_ID, HD.DEPT_NAME_EN, round(avg(HE.SAL)) as AVG_SAL
    from HR_DEPARTMENT HD
    join HR_EMPLOYEES HE on HD.DEPT_ID = HE.DEPT_ID
    group by HD.DEPT_ID, HD.DEPT_NAME_EN
    order by AVG_SAL desc;
    