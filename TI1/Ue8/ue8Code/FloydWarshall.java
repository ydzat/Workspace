import java.util.ArrayList;
import java.util.Stack;
public class FloydWarshall {

    private int[][] Path = { { -1, -1, -1, -1 }, { -1, -1, -1, -1 }, { -1, -1, -1, -1 }, { -1, -1, -1, -1 } };

    private float[][] A;


    FloydWarshall(float[][] a) {

        this.A = a;

        fwCall();
        showAandP();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (i == j) {
                    continue;
                }

                showKW(i,j);
            }
        }
        //showKW(0,3);
    }
    
    public void fwCall() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (i == j) {
                    continue;
                }
                for (int k = 0; k < 4; k++) {
                    if (k == i || k == j) {
                        continue;
                    }
                    if(this.A[i][k] == Float.POSITIVE_INFINITY || this.A[k][j] == Float.POSITIVE_INFINITY ){
                        continue;
                    }
                    if (this.A[i][j] > this.A[i][k] + this.A[k][j]) {
                        this.A[i][j] = this.A[i][k] + this.A[k][j];
                        this.Path[i][j] = k;
                    }
                }
            }
        }
    }
    
    public void showAandP() {

        System.out.println("A = ");
        System.out.print("  s t u v\n");
        for (int i = 0; i < 4; i++) {
            if (i == 0) {
                System.out.print("s ");
            }
            if (i == 1) {
                System.out.print("t ");
            }
            if (i == 2) {
                System.out.print("u ");
            }
            if (i == 3) {
                System.out.print("v ");
            }
            
            for (int j = 0; j < 4; j++) {
                if (this.A[i][j] == Float.POSITIVE_INFINITY ) {
                    System.out.print("x ");
                    continue;
                }
                System.out.print((int)this.A[i][j] + " ");
            }
            System.out.print("\n");
        }
        System.out.print("\n");
        System.out.println("Path = ");
        System.out.print("  s t u v\n");
        for (int i = 0; i < 4; i++) {
            if (i == 0) {
                System.out.print("s ");
            }
            if (i == 1) {
                System.out.print("t ");
            }
            if (i == 2) {
                System.out.print("u ");
            }
            if (i == 3) {
                System.out.print("v ");
            }

            for (int j = 0; j < 4; j++) {
                
                System.out.print((int)this.Path[i][j] + " ");
            }
            System.out.println("\n");
        }
    }
    
    public void showKW(int i, int j) {
        
        Stack<Integer> t = new Stack<Integer>();
        
        int u = i, v=j;
        while (true) {
            t.push(v);
            if (this.Path[u][v] == -1) {
                break;
            }
            v = Path[u][v];
        }
        t.push(u);

        while (t.isEmpty() == false) {
            int k = t.pop();
            if (k == 0) {
                System.out.print("s ");
            }
            if (k == 1) {
                System.out.print("t ");
            }
            if (k == 2) {
                System.out.print("u ");
            }
            if (k == 3) {
                System.out.print("v ");
            }
        }
        System.out.print("\n");
        
        
        
    
    }



}