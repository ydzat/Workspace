/*
 * @Author: Dongze Yang
 * @LastEditors: Dongze Yang
 */
package DongzeYang.task2;

public class test {

    public static void main(String[] args) {
    
        Weight weight1 = new Weight(4);
        System.out.println(weight1.isBalanced());
    
        I_Weight w2 = new SubPartOfWeight(4, new Weight(3), 3, new Weight(4));
        
        System.out.println(w2.isBalanced());
    
        I_Weight weight3 = new SubPartOfWeight(3, new Weight(3), 4, new Weight(5));
    
        System.out.println(weight3.isBalanced());
    
        I_Weight weight4 = new SubPartOfWeight(3, w2, 21, 1);
        System.out.println(weight4.isBalanced());
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    }








}