/*
 * @Author: Dongze Yang
 * @LastEditors: Dongze Yang
 */
package DongzeYang.task2;
import task2.I_Weight;
public class Weight implements I_Weight {

    private int weight;
    // private Weight left;
    // private Weight right;

    public Weight(int weight) {
        this.weight = weight;
    }

    public int getWeight() {
        return this.weight;
    }

    public boolean isBalanced() {
    //     if (left == null && right == null) {
    //         return true;
    //     }

    //     if (left.getWeight() == right.getWeight()) {
    //         return true;
    //     }
    //     return false;
    
        return true;
    }
        
    

}