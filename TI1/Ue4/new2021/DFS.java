import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;


public class DFS{

    private Graph g;
    //private Stack s;
    private int time;
    private ArrayList<Integer> dList;       //Entdeckzeit,发现时刻，节点变grau的时候
    private ArrayList<Node> piList;      //Tiefensuchwald，指向本节点的时刻
    private ArrayList<Integer> fList;       //Beendezeit，变schwarz的时刻。
    private Stack<Node> pushList = new Stack<Node>();       //记录已经出栈的节点

    DFS(Graph g){
        this.g = g;
        this.time = 0;
        this.dList = new ArrayList<Integer>();
        this.piList = new ArrayList<Node>();
        this.fList = new ArrayList<Integer>();

        for (int i = 0; i < this.g.getNodes().length; i++) {
            this.dList.add(null);
            this.fList.add(null);
            this.piList.add(null);
        }


    }

    public void choDFS(int flag){
        for (Node u : this.g.getNodes()) {
            if(u.getCol().equals("weiss")){
                //0为非递归
                if (flag == 0) {
                    
                    this.rekFrei(u);
                }
                //1为递归
                if(flag == 1){
                    this.rek(u);
                }
            }
        }
    }

    public void rekFrei(Node v){

        Stack<Node> s = new Stack<Node>();                      //栈
        s.push(v); //根结点入栈
        
        while (!s.isEmpty()) {

            s.peek().setCol("grau"); //入栈后，变为grau
            s.peek().setD(this.time);
            this.time++;
            this.dList.set(s.peek().getValue() - 1, s.peek().getD());

            if (this.pushList.search(s.peek()) == -1) {
                this.pushList.push(s.peek());
            }

            int lengthV = this.g.getNodes().length;
            int flag = 0;

            for (int i = 0; i < lengthV; i++) {
                if (this.g.getE()[s.peek().getValue() - 1][i] == 1 && this.g.getNodes()[i].getCol().equals("weiss")) {
                    s.peek().setPi(s.peek());
                    s.push(this.g.getNodes()[i]);
                    this.piList.set(s.peek().getValue() - 1, s.peek().getPi());
                    flag = 1;
                    break;
                }
            }

            if (flag == 0) {
                Node t = s.pop();
                t.setCol("schwarz"); //当某条路线走到终点时，出栈，表示加工完成，此时应当将其col修改为shwarz
                t.setF(this.time);
                time++;
                this.fList.set(t.getValue() - 1, t.getF());
            }
        } 
    }

    public void rek(Node u){
        //to do
    }

    public void showDSF() {

        //翻转Stack pushList
        Queue<Node> t = new LinkedList<Node>();
        for (Node each : this.pushList) {
            t.offer(each);
        }

        System.out.print("DFS后的结果为：");
        for (Node each : t) {
            System.out.print(each.getValue() + " ");
        }
        System.out.print("\n");
    }
    
    //妈的就是不对
    // public void showRam() {
    //     int lengthV = this.g.getNodes().length;
    //     System.out.print("--------------------------------------------------\n  ");
       
    //     for (int i = 0; i < lengthV; i++) {
    //         System.out.print(i + 1 + " ");
            
    //     }
    //     System.out.print("\nd ");

    //     for (int i = 0; i < lengthV; i++) {
            
    //         if (this.dList.get(i) == null) {
    //             System.out.print("n ");
    //             break;
    //         }
    //         System.out.print(this.dList.get(i) + " ");
    //     }
    //     System.out.print("\nf ");

    //     for (int i = 0; i < lengthV; i++) {

    //         if (this.fList.get(i) == null) {
    //             System.out.print("n ");
    //             break;
    //         }
    //         System.out.print(this.fList.get(i) + " ");
    //     }
    //     System.out.print("\nc ");

    //     for (int i = 0; i < lengthV; i++) {
    //         String t = this.g.getNodes()[i].getCol();
    //         if (t.equals("weiss")) {
    //             System.out.print("w ");
    //         }
    //         if (t.equals("grau")) {
    //             System.out.print("g ");
    //         }
    //         if (t.equals("schwarz")) {
    //             System.out.print("s ");
    //         }
            
    //     }
    //     System.out.print("\np ");
    //     for (int i = 0; i < lengthV; i++) {
    //         if (this.piList.get(i) == null) {
    //             System.out.print("n ");
    //             break;
    //         }
    //         System.out.print(this.piList.get(i).getValue() + " ");
    //     }
    //     System.out.print("\n--------------------------------------------------\n");
    // }

}