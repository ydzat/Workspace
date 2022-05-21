/*
 * @Author: Dongze Yang
 * @LastEditors: Dongze Yang
 */
package DongzeYang.task1;

import java.util.ArrayList;

import task1.I_Node;
import task1.I_SingleLinkedList;

public class SingleLinkedList implements I_SingleLinkedList {

    ArrayList<Node> nodelist;
    
    public SingleLinkedList(){
        nodelist = new ArrayList<Node>();
    }


    public Node getHead() {
        return nodelist.get(0);
    }

    
    public void addAtEnd(int value) {
        Node temp = new Node(value);
        if (nodelist.size() != 0) {
            nodelist.get(nodelist.size()-1).setNext(temp);
        }
        nodelist.add(temp);
    }

    
    public void deleteSubList(int startNodeIndex, int nodesToDelete) {
        if (startNodeIndex + nodesToDelete < nodelist.size() && startNodeIndex != 0) {
            nodelist.get(startNodeIndex - 1).setNext(nodelist.get(startNodeIndex + nodesToDelete));
        }
        if(startNodeIndex + nodesToDelete == nodelist.size()){
            nodelist.get(startNodeIndex - 1).setNext(null);
        }
        for (int i = startNodeIndex + nodesToDelete - 1; i >= startNodeIndex; i--) {
            nodelist.remove(i);
        }
    }
    
    public String toString() {
        String temp = "";
        for (int i = 0; i < nodelist.size(); i++) {
            if(i == 0){
                temp = temp + Integer.toString(nodelist.get(i).getValue());
            }
            else{
                temp = temp + "," + Integer.toString(nodelist.get(i).getValue());
            }
            
        }
        return temp;
    }

}
