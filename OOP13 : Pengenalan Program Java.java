import java.util.Scanner;
import static java.lang.Math.*;
  
public class Hello {
      
    public static void main(String[] args) {
          
        Scanner s = new Scanner(System.in);
          
        double a = 0, b = 0, c = 0, suma = 0, sumb = 0;
          
        c = s.nextDouble();
          
        for(int i = 0; i < c; i++)
        {
            a += s.nextDouble();
            b += s.nextDouble();
        }
          
        a /= c;
        b /= c;
        System.out.printf("%.2f %.2f\n", a, b);
    }
}