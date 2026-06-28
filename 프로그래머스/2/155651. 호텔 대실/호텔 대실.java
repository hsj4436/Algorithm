import java.util.*;

class Solution {
    public int solution(String[][] book_time) {
        int[][] bookTime = new int[book_time.length][2];
        convert(book_time, bookTime);
        Arrays.sort(bookTime, (bt1, bt2) -> {
            if (bt1[0] == bt2[0]) {
                return Integer.compare(bt1[1], bt2[1]);
            } else {
                return Integer.compare(bt1[0], bt2[0]);
            }
        });
        
        List<int[]> rooms = new ArrayList<>();
        rooms.add(bookTime[0]);
        for (int i = 1; i < bookTime.length; i++) {
            boolean isAdded = false;
            for (int j = 0; j < rooms.size(); j++) {
                if (rooms.get(j)[1] + 10 <= bookTime[i][0]) {
                    rooms.set(j, bookTime[i]);
                    isAdded = true;
                    break;
                }
            }
            if (!isAdded) {
                rooms.add(bookTime[i]);
            }
        }
        
        return rooms.size();
    }
    
    private static void convert(String[][] book_time, int[][] bookTime) {
        for (int i = 0; i < book_time.length; i++) {
            bookTime[i][0] = Integer.parseInt(book_time[i][0].substring(0, 2)) * 60 + Integer.parseInt(book_time[i][0].substring(3));
            bookTime[i][1] = Integer.parseInt(book_time[i][1].substring(0, 2)) * 60 + Integer.parseInt(book_time[i][1].substring(3));
        }
    }
}