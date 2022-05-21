/*
 * @Author: Dongze Yang
 * @LastEditors: Dongze Yang
 */
public class XT {

    public static void main(String[] args) {
        int n =In.readInt("Please give a number.");     
        //System.out.println(n);
        XmasTree xt = new XmasTree(n);
        xt.printTree();
    }

}