SELECT DISTINCT CC.CAR_ID
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY CH
JOIN CAR_RENTAL_COMPANY_CAR CC
    ON CH.CAR_ID = CC.CAR_ID AND CC.CAR_TYPE = '세단'
WHERE month(CH.START_DATE) = 10 
ORDER BY CC.CAR_ID DESC;
