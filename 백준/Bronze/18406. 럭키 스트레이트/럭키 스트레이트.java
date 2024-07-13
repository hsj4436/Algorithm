import java.io.*;
import java.util.*;

public class Main {

    static String N;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = br.readLine();
        int leftSum = 0, rightSum = 0;
        for (int left = 0, right = N.length() / 2; left < N.length() / 2; left++, right++) {
            leftSum += N.charAt(left) - '0';
            rightSum += N.charAt(right) - '0';
        }

        if (leftSum == rightSum) {
            System.out.println("LUCKY");
        } else {
            System.out.println("READY");
        }
    }
}