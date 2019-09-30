import java.util.Scanner;
import java.io.*;


public class Euclid {

        public static void main(String[] args) {

                Euclid ec = new Euclid();

                Scanner sc = new Scanner(System.in);

                System.out.println("Enter numbers:");
                int n = sc.nextInt();
                int m = sc.nextInt();

                System.out.println(ec.GCD(m,n));

        }

        int GCD(int a, int b) {
                if(b == 0)
                        return a;
                else
                        return GCD(b, a%b);
        }
}

