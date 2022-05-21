/*
 * @Author: Dongze Yang
 * @LastEditors: Dongze Yang
 */
package DongzeYang.task2;
import task2.I_SubPartOfWeight;
import task2.I_Weight;
public class SubPartOfWeight implements I_SubPartOfWeight {
    private int leftDistance;
    private int rightDistance;
    private I_Weight left;
    private I_Weight right;
    private int weight;

    public SubPartOfWeight(int lDis, I_Weight left, int rDis, I_Weight right) {
        this.leftDistance = lDis;
        this.rightDistance = rDis;
        this.left = left;
        this.right = right;
        this.weight = left.getWeight() + right.getWeight();
    }

    public SubPartOfWeight(int lDis, int left, int rDis, int right) {
        this.leftDistance = lDis;
        this.rightDistance = rDis;
        this.left = new Weight(left);
        this.right = new Weight(right);
        this.weight = left + right;
    }

    public SubPartOfWeight(int lDis, I_Weight left, int rDis, int right) {
        this.leftDistance = lDis;
        this.rightDistance = rDis;
        this.left = left;
        this.right = new Weight(right);
        this.weight = left.getWeight() + right;
    }

    public SubPartOfWeight(int lDis, int left, int rDis, I_Weight right) {
        this.leftDistance = lDis;
        this.rightDistance = rDis;
        this.left = new Weight(left);
        this.right = right;
        this.weight = left + right.getWeight();
    }

    public int getWeight() {
        return weight;
    }

    public int getLeftDistance(){
        return leftDistance;
    }
    public int getRightDistance(){
        return rightDistance;
    }

    public int getLeftWeight(){
        return left.getWeight();
    }
    public int getRightWeight(){
        return right.getWeight();
    }

    public I_Weight getLeft(){
        return left;
    }

    public I_Weight getRight() {
        return right;
    }
    
    public boolean isBalanced() {
        if (left == null && right == null) {
            
            return true;
        }
        if (left.getWeight()*leftDistance == right.getWeight()*rightDistance) {
            return true;
        }
        return false;
    }
}