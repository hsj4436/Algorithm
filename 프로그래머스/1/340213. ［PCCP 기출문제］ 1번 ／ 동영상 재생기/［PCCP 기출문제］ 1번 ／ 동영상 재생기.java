class Solution {
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        String answer = "";
        int videoLength = Integer.parseInt(video_len.substring(0, 2)) * 60 + Integer.parseInt(video_len.substring(3));
        int position = Integer.parseInt(pos.substring(0, 2)) * 60 + Integer.parseInt(pos.substring(3));
        int opStart = Integer.parseInt(op_start.substring(0, 2)) * 60 + Integer.parseInt(op_start.substring(3));
        int opEnd = Integer.parseInt(op_end.substring(0, 2)) * 60 + Integer.parseInt(op_end.substring(3));
        
        if (opStart <= position && position <= opEnd) {
            position = opEnd;
        }
        
        for (String command : commands) {
            if (command.equals("prev")) {
                if (position - 10 < 0) {
                    position = 0;
                } else {
                    position -= 10;
                }
            } else if (command.equals("next")) {
                if (position + 10 > videoLength) {
                    position = videoLength;
                } else {
                    position += 10;
                }
            }
            
            if (opStart <= position && position <= opEnd) {
                position = opEnd;
            }
        }
        
        answer += String.format("%02d",position / 60) + ":" + String.format("%02d", position % 60);
        
        return answer;
    }
}