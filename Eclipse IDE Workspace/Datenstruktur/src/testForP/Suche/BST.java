/*
 * @Author: Dongze Yang
 * @LastEditors: Dongze Yang
 */
package testForP.Suche;

import java.util.ArrayList;

/**
 * @description: Binärer Suchbaum / Binary Search Tree: spanning a Tree, which: leftChild <= root <=RightChild
 * @param {type} 
 * @return {type} 
 */
public class BST {

    // Tree bst = new Tree();

    public boolean insert(Node root, Node insertNode, Node parent, String flag) {
        if (root == null) {
            root = insertNode;
            if(parent != null){
                parent.setChild(root, flag);
                
            }
            
        }
        else {

            if (root.getData() > insertNode.getData()) {
                return insert(root.getChild(0), insertNode, root, "l");
            } else {
                return insert(root.getChild(1), insertNode, root, "r");
            }
            // else {
            //     now.f
            // }

        }
        return true;
    
    }

    
    
}