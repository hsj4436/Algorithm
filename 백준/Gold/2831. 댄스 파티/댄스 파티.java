import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int[] men;
    static int[] women;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        men = new int[N];
        women = new int[N];
        StringTokenizer stk = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            men[i] = Integer.parseInt(stk.nextToken());
        }
        stk = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            women[i] = Integer.parseInt(stk.nextToken());
        }

        Arrays.sort(men);
        Arrays.sort(women);
        int answer = 0;
        int wIndex = N - 1;
        for (int i = 0; i < N; i++) {
            if (wIndex == -1) {
                break;
            }
            if (men[i] < 0) {
                if (women[wIndex] < 0) {
                    continue;
                }
                while (Math.abs(men[i]) <= women[wIndex]) {
                    wIndex--;
                    if (wIndex == -1 || women[wIndex] < 0) {
                        break;
                    }
                }
                if (wIndex == -1) {
                    break;
                }
                if (women[wIndex] < 0) {
                    continue;
                }
                if (Math.abs(men[i]) > women[wIndex]) {
                    answer++;
                    wIndex--;
                }
            } else {
                if (women[wIndex] > 0) {
                    while (women[wIndex] > 0) {
                        wIndex--;
                        if (wIndex == -1) {
                            break;
                        }
                    }
                    if (wIndex == -1) {
                        break;
                    }
                }
                while (Math.abs(women[wIndex]) <= men[i]) {
                    wIndex--;
                    if (wIndex == -1) {
                        break;
                    }
                }
                if (wIndex == -1) {
                    break;
                }
                if (Math.abs(women[wIndex]) > men[i]) {
                    answer++;
                    wIndex--;
                }
            }
        }
        System.out.println(answer);
    }
}