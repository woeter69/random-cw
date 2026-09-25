import java.util.Scanner;

public class ShiftStd {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();

        int d = a << 2;
        int e = b << 3;
        int f = a >> 4;
        int g = b >> 2;
        int h = c << 5;
        int i = c >> 6;
        
        byte j = (byte) h;
        int k = h >>> 2;
        
        int l = 0x0A >> 2;
        int m = 0xF1 >> 3;
        int n = 0xA4 << 2;

        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
        System.out.println(d);
        System.out.println(e);
        System.out.println(f);
        System.out.println(g);
        System.out.println(h);
        System.out.println(i);
        System.out.println(j);
        System.out.println(k);
        System.out.println(l);
        System.out.println(m);
        System.out.println(n);
    }
}
