/*
 * @Author: Dongze Yang
 * @LastEditors: Dongze Yang
 */
package DongzeYang.task1;

public class Node implements I_Node{

    int data;
    I_Node next;
    
    
    public Node(int value){
        this.data = value;
    }

    
    public int getValue() {
        return data;
    }

    
    public void setNext(I_Node node) {
        this.next = node;
    }

    
    public I_Node getNext() {
        return this.next;
    }
    
}