-- 코드를 입력하세요
SELECT 
    p.PT_NAME, p.PT_NO, p.GEND_CD, p.AGE, IFNULL(p.TLNO, 'NONE') as TLNO
FROM
    PATIENT p
WHERE
    p.AGE <= 12 AND p.GEND_CD = 'W'
ORDER BY
    p.AGE DESC, p.PT_NAME ASC;