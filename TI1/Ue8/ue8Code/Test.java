public class Test {
    public static void main(String[] args) {
    
        float f_infty = Float.POSITIVE_INFINITY;

        float[][] a = { { 0, 4, 2, f_infty }, { f_infty, 0, 5, -3 }, { f_infty, f_infty, 0, 1 }, { f_infty, f_infty, f_infty, 0 } };

        FloydWarshall fw1 = new FloydWarshall(a);

    
    
    
    }



}