/*
 * @Author: Dongze Yang
 * @LastEditors: Dongze Yang
 */
package DongzeYang.task1;
import java.util.ArrayList;
import task1.I_CleanupList;
import task1.I_SingleLinkedList;

public class CleanupList implements I_CleanupList {
    private int listLength=0;
    private ArrayList<I_Node> temp = new ArrayList<I_Node>();
    private ArrayList<ArrayList<I_Node>> subList = new ArrayList<ArrayList<I_Node>>();
    private int sum = 0;

    public CleanupList() {
    }

    public I_SingleLinkedList deleteSublistSuccessive(I_SingleLinkedList list) {
       
        I_Node start = list.getHead();

        while(true){
            temp.add(start);
            if(start.getNext()==null){
                break;
            }
            start = start.getNext();
        }
        
        listLength = temp.size();

        for(int i = 0 ; i< listLength;i++){

            for(int deep = listLength -1 - i; deep > 0 ; deep --){
                
                if(getSum(temp.get(i),deep) == 0){

                    list.deleteSubList(i,deep+1);
                    for(int k = deep; k >= i;k--){
                        temp.remove(temp.get(k));
                    }
                    listLength = temp.size();
                    break;
                }
                
            }
        }
        return null;
    }

    
    public int getSum(I_Node start, int deep){
        if(deep == 0){
            return start.getValue();
        }
        else{
            deep --;
            sum = start.getValue() + getSum(start.getNext(), deep);
            
        }
        return sum;
    }

}
