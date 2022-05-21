/*
 * @Author: Dongze Yang
 * @LastEditors: Dongze Yang
 */
package testForP.Suche;
/**
 * @description: actually, this is only a "NODE", not a Tree
 * @param {type} 
 * @return {type} 
 */
public class BiTree {

    private int data;
    private BiTree leftChild;
    private BiTree rightChild;
    private BiTree parent;
    private BiTree rightBrother = null;

    public int getData() {
        return data;
    }

    public BiTree setData(int data) {
        this.data = data;
        return this;
    }
    
    public BiTree getLeftChild() {
        return this.leftChild;
    }

    public BiTree getRightChild() {
        return this.rightChild;
    }

    public BiTree setLeftChild(BiTree leftChild) {
        //leftChild = new BiTree();
        this.leftChild = leftChild;
        return this;
    }
    
    public BiTree setRightChild(BiTree rightChild) {
        //rightChild = new BiTree();
        this.rightChild = rightChild;
        return this;
    }

    public BiTree getParent() {
        return this.parent;
    }

    public BiTree setParent(BiTree parent) {
        //parent = new BiTree();
        this.parent = parent;
        return this;
    }

    public BiTree setRightBrother(BiTree brother) {
        this.rightBrother = brother;
        return this;
    }

    public BiTree getRightBrother() {
        return this.rightBrother;
    }

    public int getChildNr() {
        int count = 0;
        if (this.leftChild != null) {
            count++;
        }
        if(this.rightChild != null){
            count++;
        }
        return count;
    }
}