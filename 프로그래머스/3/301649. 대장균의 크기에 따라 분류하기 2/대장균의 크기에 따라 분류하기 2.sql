-- 코드를 작성해주세요

SELECT A.ID
     , CASE WHEN A.R <= 0.25 THEN 'CRITICAL'
            WHEN A.R > 0.25 AND A.R <= 0.5 THEN 'HIGH'
            WHEN A.R > 0.5 AND A.R <= 0.75 THEN 'MEDIUM'
            ELSE 'LOW'
       END AS COLONY_NAME
  FROM (SELECT PERCENT_RANK() OVER (ORDER BY ED.SIZE_OF_COLONY DESC) AS R
             , ED.ID
          FROM ECOLI_DATA AS ED
       ) AS A
 ORDER
    BY A.ID