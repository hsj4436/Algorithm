-- 코드를 입력하세요
SELECT
    FH.FLAVOR
FROM
    FIRST_HALF AS FH
    JOIN
    (
        SELECT 
            SHIPMENT_ID, FLAVOR, SUM(TOTAL_ORDER) AS TOTAL_ORDER 
        FROM
            JULY
        GROUP BY
            FLAVOR
    ) AS J
    ON
    FH.FLAVOR = J.FLAVOR
ORDER BY
    (FH.TOTAL_ORDER + J.TOTAL_ORDER) DESC
LIMIT
    3;