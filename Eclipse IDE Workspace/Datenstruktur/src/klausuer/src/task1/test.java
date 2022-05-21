/*
 * @Author: Dongze Yang
 * @LastEditors: Dongze Yang
 */
package klausuer.src.task1;
 
public class test {
    public static void main() {
        SingleLinkedList lists = new SingleLinkedList();
        lists.addAtEnd(4);
        lists.addAtEnd(2);
        lists.addAtEnd(1);
        lists.addAtEnd(-3);
        lists.addAtEnd(-2);
        lists.addAtEnd(-2);
        lists.addAtEnd(4);
        lists.addAtEnd(1);
        lists.addAtEnd(2);
        System.out.println(lists.toString());
    }
}