/*
 * @Author: Dongze Yang
 * @LastEditors: Dongze Yang
 */
package testForP.Suche;

import java.util.ArrayList;

public class Queue {

    ArrayList<BiTree> queue = new ArrayList<BiTree>();
    private int size = 0;
    
    
    public boolean offer(BiTree data) {
        queue.add(data);
        size++;
        return true;
    }

    public BiTree poll() {
        if (size != 0) {
            BiTree node = queue.get(0);
            queue.remove(0);
            size--;
            return node;
        }
        else {
            return null;
        }
    }

    public BiTree peek(){
        if(size !=0){
            return queue.get(0);
        }
        else{
            return null;
        }
    }

    public boolean isEmpty(){
        if(size == 0){
            return true;
        }
        else{
            return false;
        }
    }

    public void getQueue() {
        for (int i = 0; i < size; i++) {
            System.out.print(queue.get(i).getData() + " ");
        }
    }














}