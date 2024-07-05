-- 코드를 작성해주세요
SELECT
    i.ITEM_ID, ITEM_NAME, RARITY
FROM
    ITEM_INFO AS i
    JOIN
    ITEM_TREE AS t
    ON
    i.ITEM_ID = t.ITEM_ID
WHERE
    t.PARENT_ITEM_ID IN (
        SELECT
            i.ITEM_ID
        FROM
            ITEM_INFO AS i
            JOIN
            ITEM_TREE AS t
            ON
            i.ITEM_ID = t.ITEM_ID
        WHERE
            RARITY = 'RARE'
    )
ORDER BY
    ITEM_ID DESC;