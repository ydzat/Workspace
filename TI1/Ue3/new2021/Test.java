//package TI1.Ue3.new2021.uGraph;


public class Test{
    public static void main(String[] args){
        //3-färbbar (a)
        int[] v1 = {1,2,3,4,5,6,7};
        int[][] e1 = {{1,2},{2,3},{1,4},{4,3},{2,4},{1,5},{6,5},{7,5},{5,4}};
        
        uGraph ug1 = new uGraph(v1,e1,0);
        Farben fb1 = new Farben(ug1);
        fb1.getUgg();
        fb1.fb3();

        //3-färbbar (b)
        int[] v2 = {1,2,3,4,5,6};
        int[][] e2 = {{1,4},{1,5},{1,6},{2,4},{2,5},{2,6},{3,4},{3,5},{3,6}};

        uGraph ug2 = new uGraph(v2,e2,0);
        Farben fb2 = new Farben(ug2);
        fb2.getUgg();
        fb2.fb3();

        //3-färbbar (a), ja
        int[] v3 = {1,2,3,4};
        int[][] e3 = {{1,2},{2,3},{3,4},{4,1}};

        uGraph ug3 = new uGraph(v3,e3,0);
        Farben fb3 = new Farben(ug3);
        fb3.getUgg();
        fb3.bipartit();


        //3-färbbar (a), nein
        int[] v4 = {1,2,3,4,5};
        int[][] e4 = {{1,2},{2,3},{3,4},{4,5},{5,1}};

        uGraph ug4 = new uGraph(v4,e4,0);
        Farben fb4 = new Farben(ug4);
        fb4.getUgg();
        fb4.bipartit();
    }
}