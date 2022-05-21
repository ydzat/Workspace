/*
 * @Author: Dongze Yang
 * @LastEditors: Dongze Yang
 */
package testForP.Suche;
import java.util.ArrayList;
import java.util.List;
import java.math.*;
public class Tree {

    private ArrayList<Node> nodeList ; //[nodeRoot,node1,node2...]
    private ArrayList<List<Node>> randList = new ArrayList<List<Node>>(); //1--2,1--3 = [1,2,3]

    private int depth = 0;  //root = 1
    private int height = 0; //root = 0

    private int num = 0; //num of nodes
    
    private int max;

    //leer Baum
    public Tree() {
        nodeList = new ArrayList<Node>();
        
    }

    //Baum, wechle n mal Noten hat.
    public Tree(int n) {
        nodeList = new ArrayList<Node>();
        this.max = n;
    }

    //set a Node value
    public Tree setNode(int data){
        Node temp = new Node();
        temp.setData(data);
        if (find(data) != null) {
            System.out.println("Daten Vervielfältigung!");
            return this;
        }
        nodeList.add(temp);

        ArrayList<Node> edge = new ArrayList<Node>();
        edge.add(temp);
        randList.add(edge);
        num++;
        return this;
    }

    //ob eine Elemente mit Daten "data" schon in der nodeList
    public Node find(int data) {
        int n = this.num;
        //System.out.println(nodeList.size() + " " + n);
        if (nodeList.size() != 0) {
            while (n > 0) {
                if (nodeList.get(n-1).getData() == data) {
                    return nodeList.get(n-1);
                }
                n--;
            }
        }
        
        return null;
    }

    public Tree setEdge(int parent, int child, String side) {
        int n = this.num;
        while (n > 0) {
            if (randList.get(n - 1).get(0).getData() == parent) {
                randList.get(n-1).add(find(child));
                
                break;
            }
            n--;
        }
        nodeList.get(n - 1).setDegree(nodeList.get(n - 1).getDegree() + 1);
        
        nodeList.get(n-1).setChild(find(child),side);
        
        find(child).setParent(nodeList.get(n - 1));
        //System.out.println("--***--->" + side);
        find(child).setSide(side);
        return this;
    }

    public void getRandList() {
        aktRandList();
        System.out.print("------------vvvvvv--------\n");
        for (int i = 0; i < randList.size(); i++) {
            for (int j = 0; j < randList.get(i).size(); j++) {
                if (randList.get(i).get(j) == null) {
                    System.out.print("  ");
                    continue;
                }
                System.out.print(randList.get(i).get(j).getData() + " ");
            }
            System.out.print("\n");
        }
        System.out.print("-----------------------\n");
        for (int i = 0; i < randList.size(); i++) {
            int n = nodeList.get(i).getChildren().size();
            for (int j = 0; j < n; j++) {
                if (nodeList.get(i).getChildren().get(j) == null) {
                    System.out.print("  ");
                    continue;
                }
                System.out.print(nodeList.get(i).getChildren().get(j).getData());
            }
            System.out.print("\n");
        }
        System.out.print("------------AAAAA-----------\n");
        // System.out.print("-----------------------\n");
        // System.out.print(nodeList.get(4).getChildren().get(0).getData());
        // System.out.print(nodeList.get(4).getChildren().get(1).getData());
    }


    public ArrayList<Node> getNodeList() {
        return nodeList;
    }

            //global als lokale Var
    public void BSTspanning(int []arr,boolean AVL) {
        int arrLength = arr.length;
        for (int i = 0; i < arrLength; i++) {
            setNode(arr[i]);
        }

        
        //BST bst = new BST();
        insert(null, nodeList.get(0), null, "x",1,AVL);
        
        for (int i = 1; i < nodeList.size(); i++) {
            //insert(nodeList.get(0), nodeList.get(i), null, null,1);
            insert(getRoot(), nodeList.get(i), null, null,1,AVL);
        }
        
    }
    
    public boolean insert(Node root, Node insertNode, Node parent, String flag, int depth, boolean AVL) {
        if (root == null) {
            root = insertNode;
            root.setDepth(depth);
            root.setHeight(depth - 1);
            if (parent != null) {
                parent.setChild(root, flag);
                setEdge(parent.getData(), root.getData(), flag);
            }
            if (AVL == true && insertNode.getDepth()>=3) {
                
                boolean ob = rotationToAVL(insertNode.getParent().getParent(), insertNode);
                //System.out.println("------>"+ob+"<---------->"+getRoot().getData()+"<-----");
            }
            
            
        }
        else {
            depth = depth + 1;
            if (root.getData() > insertNode.getData()) {

                return insert(root.getChild(0), insertNode, root, "l", depth,AVL);
            } else {
                return insert(root.getChild(1), insertNode, root, "r", depth,AVL);
            }
        }
        
        aktDepthAndHeight();

        return true;
    }
    
    public Node findForBST(Node node, int value) {
        if (node == null) {
            return null;
        }
        if (node.getData() > value) {
            return findForBST(node.getChild(0), value);
        }
        if (node.getData() < value){
            return findForBST(node.getChild(1), value);
        }
        return node;
    }

    public boolean deleteBSTNode(Node del) {
        String side = del.whichSide();
        if (del.getChildren().size() == 0) {
            
            del.getParent().setChild(null, side);
            deleteBSTNodeInLists(del, side, 0);
            
        }
        else if (del.getChildren().size() == 1) {
            
            Node temp = (del.getChild(0) != null && del.getChild(1) == null) ? del.getChild(0) : del.getChild(1);
            temp.setParent(del.getParent());
            del.getParent().setChild(temp, side);
            deleteBSTNodeInLists(del, side,1);
        }
        else if (del.getChildren().size() == 2) {
            
            Node temp = findMin(del.getChild(1));
            //int tData = del.getData();
            del.setData(temp.getData());
            //temp.setData(tData);
            deleteBSTNode(temp);
            
        }
        else {
            return false;
        }

        return true;
    }

    
    private void deleteBSTNodeInLists(Node del, String side,int mode) {
        nodeList.remove(del);
        for (int i = randList.size() - 1; i >= 0; i--) {
            if (randList.get(i).get(0) == del) {
                randList.remove(i);

            }
        }
        for (int i = randList.size() - 1; i >= 0; i--) {
            if (randList.get(i) == del.getParent()) {
                
                if (side == "l") {
                    randList.get(i).set(1, null);
                }
                if (side == "r") {
                    randList.get(i).set(2, null);
                }
                
            }
        }
        del = null;
    }

    private Node findMin(Node del) {
        if (del.getChild(0) != null) {
            return findMin(del.getChild(0));
        }
        return del;
    }

    
    public void aktDepthAndHeight() {
        for (int i = 0; i < nodeList.size(); i++) {
            this.depth = (depth <= nodeList.get(i).getDepth()) ? nodeList.get(i).getDepth() : depth;
        }
        height = depth - 1;
        //System.out.println("tree depth = " + depth+ " height = "+height);
    }

    //AVL
    public boolean rotationToAVL(Node start, Node checkNode) {
        //check balance first
        boolean check = true;
        Node temp = null;
        temp = start;
        while(temp!=null){
            check = balanceCheck(temp);
            temp = temp.getParent();
        }
        
        if (check) {
            
            return true;
        }
        else {
            //LL--0
            int type = modeCheck(checkNode);
            System.out.println("type = " + type);
            if (type == 0) {
                ll(start.getParent());
            }
            //LR--1
            else if (type == 1) {
                //System.out.println("start = "+start.getParent().getData() );
                lr(start.getParent());
            }
            //RR--2
            else if (type == 2) {
                rr(start.getParent());
            }
            //RL--3
            else if (type == 3) {
                rl(start.getParent());
            }
            else {
                return false;
            }
        }
        return true;
    }

    private Node ll(Node start) {
        Node t1 = null;
        t1 = start.getChild(0);
        
        int startDepth = start.getDepth();
        int t1Depth = t1.getDepth();
        Node t0 = start.getParent();

        setEdge(start.getData(), t1.getChild(1).getData(), "l");
        setEdge(t1.getData(), start.getData(), "r");
        setEdge(t0.getData(), t1.getData(), "r");

        
        // start.setChild(t1.getChild(1), "l");
        // t1.setChild(start, "r");
        start.setDepth(t1Depth);
        t1.setDepth(startDepth);
        return t1;
    }
    
    private Node rr(Node start) {
        Node t1 = null;
        t1 = start.getChild(1);
        
        int startDepth = start.getDepth();
        int t1Depth = t1.getDepth();
        Node t0 = start.getParent();
        setEdge(start.getData(), t1.getChild(0).getData(), "r");
        setEdge(t1.getData(), start.getData(), "l");
        setEdge(t0.getData(), t1.getData(), "l");  

        start.setDepth(t1Depth);
        t1.setDepth(startDepth);

        return t1;
    }
    
    
    private Node lr(Node start) {
        //System.out.println("start === "+start.getData());
        start.setChild(rr(start.getChild(0)),"l");
        return ll(start);
    }
    
    private Node rl(Node start) {
        start.setChild(ll(start.getChild(1)), "r");
        return rr(start);
    }
    
    private int modeCheck(Node checkNode){
        String type = checkNode.getParent().getParent().whichSide() + checkNode.getParent().whichSide();
        System.out.println("type === " + type);
        if (type.equals("ll")) {
            return 0;
        }
        else if (type.equals("lr")) {
            return 1;
        }
        else if (type.equals("rr")) {
            return 2;
        }
        else if (type.equals("rl")) {
            return 3;
        }
        else {
            return -1;
        }
    }

    private boolean balanceCheck(Node root) {
        boolean res = true;
        System.out.println("root.getChild(0) = "+root.getChild(0).getData()+"  root.getChild(1)="+root.getChild(1).getData());
        switch (root.getChildren().size()) {
            case 0:
                res = true;
                break;
            case 1:
                if (root.getChild(0) == null) {
                    res = (Math.abs(root.getDepth() - balanceCheckLR(root.getChild(1))) >= 2) ? false : true;
                }
                if (root.getChild(1) == null) {
                    res = (Math.abs(balanceCheckLR(root.getChild(0)) - root.getDepth()) >= 2) ? false : true;
                }
                break;
            case 2:  
                res = (Math.abs(balanceCheckLR(root.getChild(0)) - balanceCheckLR(root.getChild(1))) >= 2) ? false : true;
                break;
            default:
                break;
        }
        
        return res;
    }
    
    private int balanceCheckLR(Node root) {
    
        Stack RandList = new Stack();
        
        RandList.push(root);
        
        int depth = root.getDepth();
        
        while (!RandList.isEmpty()) {
            Node node = RandList.pop();
            
            if (node.getChildren().size() != 0) {
                if (node.getChild(0) != null) {
                    
                    depth = (node.getDepth() >= depth) ? node.getChild(0).getDepth() : depth;
                    RandList.push(node.getChild(0));
                }
                if (node.getChild(1) != null) {
                    depth = (node.getDepth() >= depth) ? node.getChild(1).getDepth() : depth;
                    RandList.push(node.getChild(1));
                }
                
            }
            
            
        }
        
        return depth;
    }

    public Node getRoot(){
        for (int i = 0; i < nodeList.size(); i++) {
            if (nodeList.get(i).getDepth() == 1) {
                return nodeList.get(i);
            }
        }
        return null;
    }

    public void aktRandList(){
        randList = null;
        ArrayList<List<Node>> rd = new ArrayList<List<Node>>();
        for(int i =0;i<nodeList.size();i++){
            ArrayList<Node> temp = new ArrayList<Node>();
            temp.add(nodeList.get(i));
            if(nodeList.get(i).getChild(0) == null){
                temp.add(null);
            }
            else{
                temp.add(nodeList.get(i).getChild(0));
            }
            if(nodeList.get(i).getChild(1)==null){
                temp.add(null);
            }
            else{
                temp.add(nodeList.get(i).getChild(1));
            }
            rd.add(temp);
        }
        randList = rd;

    }





}

