SELECT month(START_DATE) AS MONTH, CAR_ID, COUNT(CAR_ID) AS RECORDS
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
WHERE CAR_ID IN (
                    SELECT CAR_ID
                    FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
                    WHERE (month(START_DATE) >= 8 AND month(START_DATE) <= 10)
                    GROUP BY CAR_ID
                    HAVING COUNT(CAR_ID) >= 5
                )
AND (month(START_DATE) >= 8 AND month(START_DATE) <= 10)
GROUP BY month(START_DATE), CAR_ID
HAVING RECORDS != 0
ORDER BY MONTH ASC, CAR_ID DESC;
