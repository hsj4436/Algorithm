import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N;
    static List<String> words = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; i++) {
            words.add(br.readLine());
        }

        int answer = 0;
        for (int i = 0; i < N; i++) {
            String left = words.get(i);
            for (int j = i + 1; j < N; j++) {
                Map<Character, Character> convert = new HashMap<>();
                boolean[] used = new boolean[27];
                String right = words.get(j);
                boolean isConvertable = true;
                for (int k = 0; k < left.length(); k++) {
                    if (Objects.isNull(convert.get(left.charAt(k)))) {
                        if (!used[right.charAt(k) - 'a']) {
                            convert.put(left.charAt(k), right.charAt(k));
                            used[right.charAt(k) - 'a'] = true;
                        } else {
                            isConvertable = false;
                            break;
                        }
                        continue;
                    }
                    if (!convert.get(left.charAt(k)).equals(right.charAt(k))) {
                        isConvertable = false;
                        break;
                    }
                }

                if (isConvertable) {
                    answer++;
                }
            }
        }

        System.out.println(answer);
    }
}