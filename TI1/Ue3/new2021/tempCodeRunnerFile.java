int[] v1 = {1,2,3,4,5,6,7};
        int[][] e1 = {{1,2},{2,3},{1,4},{4,3},{2,4},{1,5},{6,5},{7,5},{5,4}};
        
        uGraph ug1 = new uGraph(v1,e1);
        Farben fb1 = new Farben(ug1);
        fb1.getUgg();
        fb1.fb3();