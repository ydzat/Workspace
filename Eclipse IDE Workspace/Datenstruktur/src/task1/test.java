/*
 * @Author: Dongze Yang
 * @LastEditors: Dongze Yang
 */
package DongzeYang.task1;
 
public class test {
    public static void main(String [] args) {
        SingleLinkedList lists = new SingleLinkedList();
        lists.addAtEnd(4);
        lists.addAtEnd(2);
        lists.addAtEnd(1);
        lists.addAtEnd(-3);
        lists.addAtEnd(-2);
        lists.addAtEnd(-2);
        lists.addAtEnd(4);
        // lists.addAtEnd(1);
        // lists.addAtEnd(2);
        // System.out.println(lists.toString());
        
        // System.out.println(lists.getHead().getValue());
        // lists.deleteSubList(7,2);
        // System.out.println(lists.toString());
        
        //lists.getData();

        // lists.addAtEnd(1);
        // lists.addAtEnd(2);
        // lists.addAtEnd(-2);

        CleanupList te = new CleanupList();
        te.deleteSublistSuccessive(lists);
        
        System.out.println(lists.toString());
    
    
    
    
    
    
    
    }
    
}