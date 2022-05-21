/*
 * @Author: Dongze Yang
 * @LastEditors: Dongze Yang
 */
package testForP.Suche;

import java.util.ArrayList;

public class Stack{
    private ArrayList<Node> stack = new ArrayList<Node>();
    private int size = 0;
    private int topIndex;

    /*in*/
    public void push(Node data) {
        stack.add(data);
        this.size++;
        topIndex = size - 1;
    }

    /*out*/
    public Node pop() {
        if (!this.isEmpty()) {
            Node node = stack.get(topIndex);
            stack.remove(topIndex);
            size--;
            topIndex--;
            return node;
        }
        else {
            return null;
        }
    }
    
    public boolean isEmpty() {
        if (size == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    
    
    // void clear() {
    //     if (!this.isEmpty()) {
    //         stack.clear();
    //     }
        
    // }
    

    // public int length() {
    //     return size;
    // }
    

    public Node peek() {
        return stack.get(topIndex);
    }

    // public void getStack() {
    //     for (int i = 0; i < size; i++) {
    //         System.out.print(stack.get(i).getData() + " ");
    //     }
    //     //
    // }
    
}

