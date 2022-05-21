/*
 * @Author: Dongze Yang
 * @LastEditors: Dongze Yang
 */
package testForP.Suche;

import java.util.ArrayList;

//import org.graalvm.compiler.graph.NodeList;

public class test {

    public static void main(String[] args) {
    
        //Suche b = new Suche();
        
        //------------------------------------------------------
        int arr[];
        //arr = new int[] {6,7,2,1,4,3};
        arr = new int[] { 43, 55, 22, 75, 23, 15 };
        //System.out.println(b.BS(arr, 7));
    
        //System.out.println(b.InsertionSuche(arr, 4, 0, arr.length-1));
    
        //public static int BS(int[] arr, int key, int low, int high){

        // ArrayList<BiTree> bi = new ArrayList<BiTree>();
        
        // for (int i = 0; i < 9; i++) {
        //     BiTree tempNode = new BiTree();
        //     tempNode.setData(i + 1);
        //     bi.add(tempNode);
        // }

        
        // bi.get(0).setLeftChild(bi.get(1)).setRightChild(bi.get(2)).setParent(bi.get(0));
        // bi.get(1).setLeftChild(bi.get(3)).setRightChild(bi.get(4)).setParent(bi.get(0)).setRightBrother(bi.get(2));
        // bi.get(2).setLeftChild(bi.get(5)).setRightChild(bi.get(6)).setParent(bi.get(0));
        // bi.get(3).setParent(bi.get(1)).setRightBrother(bi.get(4)).setRightBrother(bi.get(5)).setRightBrother(bi.get(6));
        // bi.get(4).setRightChild(bi.get(7)).setParent(bi.get(1));
        // bi.get(5).setParent(bi.get(2));
        // bi.get(6).setLeftChild(bi.get(8)).setParent(bi.get(2));
        // bi.get(7).setData(8).setParent(bi.get(4)).setRightBrother(bi.get(8));
        // bi.get(8).setData(9).setParent(bi.get(6));
        // if (bi.get(4).getChildNr() != 0) {
        //     BiTree lineStart = (bi.get(4).getLeftChild()==null && bi.get(4).getRightChild()!=null) ? bi.get(4).getRightChild(): bi.get(4).getLeftChild();
        //     System.out.println("it has "+bi.get(4).getChildNr()+" child(ren), the one is---> " + lineStart.getData());
        // }
        
        //b.DFS(bi.get(0),9);
        //b.BFS(bi.get(0), 5);

        // for (int i = 0; i < 9; i++) {
        //     System.out.println(bi.get(i).getData() + " ");
        // }
        //System.out.println(bi.get(0).getLeftChild().getData());

        //-------------------------------------------------------
        
        //Tree

        ////////////////////////////////////BFS
        Tree tr = new Tree(arr.length);
        // for (int i = 0; i < 9; i++) {
        //     tr.setNode(i + 1);
        // }

       
        // tr.setEdge(1, 2,"l");
        // tr.setEdge(1,3,"r" );
        // tr.setEdge(2,4,"l");
        // tr.setEdge(2,5,"r" );
        // tr.setEdge(5,8,"r" );
        // tr.setEdge(3, 6,"l");
        // tr.setEdge(3, 7,"r");
        // tr.setEdge(7, 9,"l");

           
        // tr.getRandList();

        ////////////////////////////////////BST
        tr.BSTspanning(arr,true);
        tr.getRandList();
        //System.out.println("---+++->" + tr.deleteBSTNode(tr.find(2)));
        //tr.getRandList();
        
        // for (int i = 0; i < tr.getNodeList().size(); i++) {
        //     for (int j = 0; j < 2; j++) {
        //         System.out.print(tr.getNodeList().get(i).getChild(j).getData() + " ");
        //     }
        //     System.out.print("\n");
        // }























































































        
    }











}