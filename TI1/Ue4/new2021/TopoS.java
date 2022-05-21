import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;


public class TopoS {

    private Graph g;
    private Stack<Node> pushList; //记录已经出栈的节点
    private Queue<Node> deleteList; //记录要删除的节点
    private Queue<Node> deleted; //记录已删除的节点
    private int kreis;

    //flag ==1 有向图，==0无向图
    TopoS(Graph g,int flag) {
        this.g = g;
        this.pushList = new Stack<Node>();
        this.deleteList = new LinkedList<Node>();
        this.deleted = new LinkedList<Node>();

        int lengthV = this.g.getNodes().length;

        for (Node u : this.g.getNodes()) {
            if (u == null) {
                continue;
            }
            if(u.getCol().equals("weiss")){
                //0为无向图
                if (flag == 0) {
                    //to do
                }
                //1为有向图
                if (flag == 1) {
                    System.out.print("u == " + u.getValue() + "\n");
                    this.topoSDFS(u);
                    //每一轮，删除一波节点
                    for (int i = 0; i < this.deleteList.size(); i++) {

                        

                        Node t = this.deleteList.poll();

                        this.deleted.offer(t);
                        this.g.deleteNode(t);
                        //判断是否有环
                        int flag2 = 0;
                        for (Node v : this.g.getNodes()) {
                            if (v == null) {
                                continue;
                            }
                            if (v.getEGrad() == 0) {
                                flag2 = 1;
                                break;
                            }
                        }
                        if (flag2 == 1) {
                            continue;
                        }
                        
                        if (this.deleted.size() != lengthV) {
                            System.out.print("deleted size = " + this.deleted.size() + " lengthV = " + lengthV + "\n");
                            this.kreis = 1;
                            break;
                        }
                    }
                    
                }
            }
        }

    }

    //有向图DFS拓扑排序(非递归)
    public void topoSDFS(Node v) {

        Stack<Node> s = new Stack<Node>(); //栈
        s.push(v); //根结点入栈

        while (!s.isEmpty()) {

            s.peek().setCol("grau"); //入栈后，变为grau

            if (this.pushList.search(s.peek()) == -1) {
                this.pushList.push(s.peek());
            }

            //判断当前栈顶元素的入度是否为0，若是，则记录该点，放入队列，准备删除
            if (s.peek().getEGrad() == 0) {
                this.deleteList.offer(s.peek());
                System.out.print("=======> "+s.peek().getValue()+"\n");
            }

            int lengthV = this.g.getNodes().length;
            int flag = 0;

            for (int i = 0; i < lengthV; i++) {
                if (this.g.getE()[s.peek().getValue() - 1][i] == 1 && 
                this.g.getNodes()[i].getCol().equals("weiss")) {

                    s.push(this.g.getNodes()[i]);

                    flag = 1;
                    break;
                }
            }

            if (flag == 0) {
                Node t = s.pop();
                t.setCol("schwarz"); //当某条路线走到终点时，出栈，表示加工完成，此时应当将其col修改为shwarz

            }
        }

    }
    
    public void showTopo() {
    
        if (this.kreis == 1) {
            System.out.print("es gibt Kreis\n");
        }
        else {
            System.out.print("es gibt keine Kreis\n");
            System.out.print("pushList is:");
            for (Node i : this.pushList) {
                System.out.print(i.getValue() + " ");
            }
            System.out.print("\n");
            // System.out.print("deleteList is:");
            // for (Node i : this.deleteList) {
            //     System.out.print(i.getValue() + " ");
            // }
            // System.out.print("\n");
        }
    
    }









}