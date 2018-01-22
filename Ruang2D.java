import java.io.*;
import java.util.*;

class Pair<F, S> {
    private F first;
    private S second;

    public Pair(F first, S second) {
        this.first = first;
        this.second = second;
    }

    public void setFirst(F first) {
        this.first = first;
    }

    public void setSecond(S second) {
        this.second = second;
    }

    public F getFirst() {
        return first;
    }

    public S getSecond() {
        return second;
    }
}

class Segitiga {
   Pair<Double,Double> t1;
   Pair<Double,Double> t2;
   Pair<Double,Double> t3;
   public Segitiga(Double x1, Double y1, Double x2, Double y2, Double x3, Double y3) {
      t1=new Pair<Double,Double>(x1,y1);
      t2=new Pair<Double,Double>(x2,y2);
      t3=new Pair<Double,Double>(x3,y3);
   }
   public double luas() {
      double a=t2.getFirst()*t3.getSecond()+t1.getFirst()*t2.getSecond()+t3.getFirst()*t1.getSecond();
      double b=t2.getFirst()*t1.getSecond()+t3.getFirst()*t2.getSecond()+t1.getFirst()*t3.getSecond();
      return Math.abs(a-b)/2.0;
   }
}

class Lingkaran {
   Pair<Double,Double> pusat;
   Double radius;
   public Lingkaran(Double x, Double y, Double r) {
      pusat = new Pair<Double, Double>(x, y);
      radius = r;
   }
   
   public double luas() {
      return 3.14*radius*radius;
   }

}

public class Main{
   public static void main(String[] args){
       BufferedReader dataIn = new BufferedReader(new InputStreamReader(System.in));
       String inp = "";
       String delim="[ ]+";
       String[] temp;
       Segitiga[] segitiga=new Segitiga[100];
       Lingkaran[] lingkaran=new Lingkaran[100];
       Scanner in = new Scanner(System.in);
       int n = in.nextInt(); int m = in.nextInt();
       
       double rataling = 0;
       for(int i=0; i<n; i++) {
       	double x = in.nextDouble(), y = in.nextDouble(), r = in.nextDouble();
       	lingkaran[i] = new Lingkaran(x, y, r);
       	rataling += lingkaran[i].luas();
       }
       rataling /= n;
       
       int hitling = 0;
       for(int i=0; i<n; i++) {
       	if (lingkaran[i].luas() < rataling) {
       	    hitling += 1;	
       	}
       }
       
       double rataseg = 0;
       for(int i=0; i<m; i++) {
       	double x1 = in.nextDouble(), y1 = in.nextDouble();
       	double x2 = in.nextDouble(), y2 = in.nextDouble();
       	double x3 = in.nextDouble(), y3 = in.nextDouble();
       	
       	segitiga[i] = new Segitiga(x1, y1, x2, y2, x3, y3);
       	rataseg += segitiga[i].luas();
       }
       rataseg /= m;
       
       int hitseg = 0;
       for(int i=0; i<m; i++) {
       	if (segitiga[i].luas() < rataseg) {
       	    hitseg += 1;
       	}
       }
       
       System.out.print("Lingkaran "); System.out.printf("%.2f", rataling); System.out.println(" " + hitling + " " + (n - hitling));
       System.out.print("Segitiga "); System.out.printf("%.2f", rataseg); System.out.println(" " + hitseg + " " + (m - hitseg));
   }
}
