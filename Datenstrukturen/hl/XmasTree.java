public class XmasTree {

    private int hoehe;
    private int breite;

    private String[] baum;


    XmasTree(int n) {
        this.hoehe = n;
        this.breite = 2 * n;
        this.baum = new String[n + 1];
        buildBaumkrone(this.hoehe, 2,0);
    }

    //
    public void printTree(){
        int i = 0;
        while (i <= this.hoehe) {
            System.out.println(this.baum[i]);
            i++;
        }
    }

    //创建树枝
    private int buildBaumkrone(int h, int b,int pos) {
        
        if (pos <= this.hoehe) {
            Baumkrone bk = new Baumkrone(h, b);
            this.baum[pos] = bk.getKrone();
            return buildBaumkrone(h, b+2, pos+1);
        }
        else {
            this.baum[this.hoehe] = buildKofferraum(this.hoehe-1);
        }
        //System.out.println(bk.getKrone());
        return 0;
    }

    private String buildKofferraum(int h) {
        if (h > 0) {
            return " " + buildKofferraum(h - 1);
        }
        if (h <= 0 && h >= -1) {
            return "|" + buildKofferraum(h - 1);
        }
        return "";
    }

























}