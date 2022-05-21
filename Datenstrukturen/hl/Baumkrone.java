/*
 * @Author: Dongze Yang
 * @LastEditors: Dongze Yang
 */
public class Baumkrone {

    private int hoehe;
    private int breite; //自身宽度
    private int leer;
    
    Baumkrone(int h, int b) {
        this.hoehe = h;
        this.breite = b;
        this.leer = h - b / 2;
    }


    public int getHoehe() {
        return this.hoehe;
    }
    
    public int getbreite() {
        return this.breite;
    }

    public String getKrone() {
        return this.krone(this.hoehe);
    }

    private String krone(int h) {
        
        if (h > this.hoehe - this.leer) {
            //System.out.println("1");
            return " " + krone(h - 1);
        }
        if (h <= this.hoehe - this.leer && h > 0) {
            //System.out.println("2");
            return "/" + krone(h - 1);
        }
        if (h <= 0 && h > -breite / 2) {
            //System.out.println("3");
            return "\\" + krone(h - 1);
        }
        return "";
    }
    

}