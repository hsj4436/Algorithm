import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int[][] arr;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        arr = new int[N][2];
        int[] minArr = new int[N];
        int[] maxArr = new int[N];
        for (int i = 0; i < N; i++) {
            StringTokenizer stk = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(stk.nextToken());
            arr[i][1] = Integer.parseInt(stk.nextToken());
            minArr[i] = arr[i][0] - arr[i][1];
            maxArr[i] = arr[i][0] + arr[i][1];
        }

        Arrays.sort(minArr);
        Arrays.sort(maxArr);

        for (int i = 0; i < N; i++) {
            int min = arr[i][0] - arr[i][1];
            int minIndex = lowerBound(maxArr, min) + 1;
            System.out.print(minIndex + " ");
            int max = arr[i][0] + arr[i][1];
            int maxIndex = upperBound(minArr, max) + 1;
            System.out.println(maxIndex);
        }
    }

    private static int lowerBound(int[] arr, int target) {
        int left = 0, right = arr.length - 1;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }

    private static int upperBound(int[] arr, int target) {
        int left = 0, right = arr.length - 1;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (arr[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right;
    }

}