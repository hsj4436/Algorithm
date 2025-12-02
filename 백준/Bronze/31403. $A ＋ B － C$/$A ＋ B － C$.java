import java.io.*;
import java.util.*;

public class Main {

    static int A;
    static int B;
    static int C;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        A = Integer.parseInt(br.readLine());
        B = Integer.parseInt(br.readLine());
        C = Integer.parseInt(br.readLine());

        String s = "";
        s += A;
        s += B;

        System.out.println(A + B - C);
        System.out.println(Integer.valueOf(s) - C);
    }
}