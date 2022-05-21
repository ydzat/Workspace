/*
 * @Author: Dongze Yang
 * @LastEditors: Dongze Yang
 */
package testForP.Suche;
import java.util.ArrayList;
public class Node {

    private int data;
    private Node parent;    //for tree
    private ArrayList<Node> children = new ArrayList<Node>(); //for tree
    private String side; //for 2 Banche tree
    
    private int depth;  //root = 1
    private int height; //root = 0
    
    private int degree=0; //for ungerichtete Graph
    private int indegree=0, outdegree=0;//for gerichtete Graph
    
    //--------------get-----------------
    public int getData() {
        return data;
    }

    public Node getParent() {
        return parent;
    }

    public ArrayList<Node> getChildren() {
        return children;
    }
    
    public Node getChild(int index) {
        if (index >= children.size()) {
            return null;
        }
        return children.get(index);
    }

    public int getDegree() {
        return degree;
    }

    public int getIndegree() {
        return indegree;
    }

    public int getOutdegree() {
        return outdegree;
    }

    public String whichSide() {
        return this.side;
    }

    public int getDepth() {
        return this.depth;
    }

    public int getHeight() {
        return this.height;
    }

    //-------------------set------------------------
    public Node setData(int data) {
        this.data = data;
        return this;
    }
    
    public Node setParent(Node parent) {
        this.parent = parent;
        return this;
    }
    
    public Node setChild(Node child) {
        this.children.add(child);
        return this;
    }

    public Node setChild(Node child, String flag) {
        if (this.children.size() == 0) {
            if (flag == "l") {
                this.children.add(child);
            }
            if (flag == "r") {
                this.children.add(null);
                this.children.add(child);
            }
        }
        if (this.children.size() == 1) {
            if (flag == "l") {
                this.children.set(0,child);
            }
            if (flag == "r") {
                this.children.add(child);
            }
        }
        else {
            if (flag == "l") {
                this.children.set(0,child);
            }
            if (flag == "r") {
                this.children.set(1,child);
            }
        }
        
        return this;
    }

    public Node setDegree(int degree) {
        this.degree = degree;
        return this;
    }

    public Node setIndegree(int indegree) {
        this.indegree = indegree;
        return this;
    }

    public Node setOutdegree(int outdegree) {
        this.outdegree = outdegree;
        return this;
    }

    public Node setSide(String side) {
        this.side = side;
        return this;
    }
    
    public Node setDepth(int depth) {
        this.depth = depth;
        return this;
    }

    public Node setHeight(int height) {
        this.height = height;
        return this;
    }
    













}