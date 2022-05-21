import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class Farben{

    Graph ugg;

    Farben(Graph ug){
        this.ugg = ug;
    }

    public void getUgg(){
        this.ugg.getGraph();
    }

    //ob 3-färbbar sein
    public void fb3(){

        int lengthV = this.ugg.getV().length;
        //System.out.print("length = " + lengthV);
        int[] deleteList = new int[lengthV];
        int last = 0;       //last每次指向最新为空的下标
        int top = 0;        //top每次指向当前需要操作的序列的开头元素
        int flag = 0;       //若图中存在任一一个节点是小于等于2，则为1，否则为0

        while(true){
            //检索第一次，找出当前图中所有度数小于2的节点，记录在deleteList中
            //若当前图中所有节点的度都大于2，则退出循环
            //若last == lengthV，则退出循环
            if(last == lengthV){
                break;
            }
            for(int i = 0; i < lengthV; i++){
                //System.out.print("i = " + i + " last = "+ last + "\n");
                int sum = 0;
                for(int j : this.ugg.getE()[i]){
                    sum = sum + j;
                }
                if (sum <= 2 && sum != 0){
                    deleteList[last] = i;
                    last ++;
                    flag = 1;
                }
            }
            if(flag == 0){
                break;
            }

            //第一轮删除，删除deleteList中指向的节点与边。即，置为0
            for(int i = top; i < last; i++){
                for(int j = 0; j < lengthV; j++){
                    this.ugg.getE()[deleteList[i]][j] = 0;
                    this.ugg.getE()[j][deleteList[i]] = 0;      //有向图中删去此行
                }
            }
            int t = top;
            top = last;

            //输出1次当前的G'
            System.out.print("///////////////////////////////////\n");
            //此时的deleteList
            System.out.print("deleteList is: ");
            for(int i = t; i < last; i++){
                System.out.print(deleteList[i]+1 + " ");
            }
            System.out.print("\n");
            this.ugg.getGraph();
            System.out.print("///////////////////////////////////\n");
        }

        //判断当前的G'中是否还有剩余，实际上判断last的值是否与lengthV相等即可
        if(last == lengthV){
            System.out.print("G ist 3-färbbar\n\n");
        }
        else{
            System.out.print("weiß nicht\n\n");
        }
    }

    //ob 2-färbbar / bipartit  sein, 二分图
    //思路：BFS或DFS，此处用BFS
    public void bipartit(){

        //要从每个结点为起始点，均进行一次BFS，因此一共需进行this.ugg.getV().length次。
        int lengthV = this.ugg.getV().length;

        for(int i = 0; i < lengthV; i++){
            //i+1的值为节点的实际值value
            System.out.print("von " + (i+1) + " starten:\n");

            //将.getE()更改行的位置，让第i行变为第0行，依次变换。
            int[][] eTemp = new int[lengthV][lengthV];
            for(int j = 0; j < lengthV; j++){
                eTemp[j] = this.ugg.getE()[(i+j)%lengthV];
            }

            //BFS
            //建立一个等待队列
            Queue<Node> warteSchlange = new LinkedList<Node>();
            //建立一个已遍历栈
            Stack<Node> expansion = new Stack<Node>();

            //BFS准备：先将当前初始节点入队
            warteSchlange.offer(ugg.getNodes()[i]);       //默认index = value - 1
            System.out.print("初始节点为："+ ugg.getNodes()[i].getValue() + "\n");
            ugg.getNodes()[i].setGroup(0);
            int lauf = 0;

            while(true){
                //判断队列是否为空，若为空，则退出循环
                if(warteSchlange.isEmpty()){
                    break;
                }

                //将第一个元素出队，并放进已遍历栈中，并判断其相邻的节点
                //若本身group=0，则相邻节点的group = 1；否则=0。
                expansion.push(warteSchlange.poll());
                int groupTemp = expansion.peek().getGroup();

                for(int j = 0; j < lengthV; j++ ){
                    if(eTemp[lauf][j] == 1 && expansion.search(ugg.getNodes()[j]) == -1){
                        warteSchlange.offer(ugg.getNodes()[j]);     //若有边，则入队
                        if(groupTemp == 0){
                            ugg.getNodes()[j].setGroup(1);
                        }
                        else{
                            ugg.getNodes()[j].setGroup(0);
                        }
                    }
                }
                lauf++;
            }

            //输出遍历顺序：
            System.out.print("遍历顺序为：");
            for(Node j : expansion){
                System.out.print( j.getValue() + " ");
            }
            System.out.print("\n");

            //从i开始的一次遍历完成后，判断是否为二分图
            //即遍历所有边，看是否存在边的两端节点同属一个group，若是，则“不是二分图”
            //否则“是二分图”
            int flag = 0;
            for(int j = 0; j < lengthV; j++){
                for(int k = j+1; k < lengthV; k++){
                    if(this.ugg.getE()[j][k] == 1){
                        if(this.ugg.getNodes()[j].getGroup() == this.ugg.getNodes()[k].getGroup() ){
                            System.out.print("nicht 2-färbbar / bipartit\n");
                            flag = 1;
                            break;
                        }
                    }
                }
                if(flag == 1){
                    break;
                }
            }

            if(flag == 0){
                System.out.print("G ist 2-färbbar / bipartit !\n");

                //输出分组：
                Queue<Node> nodesGroup0 = new LinkedList<Node>();       //该组存储组0的节点
                Queue<Node> nodesGroup1 = new LinkedList<Node>();       //该组存储组1的节点
                
                //先分组
                for(Node j : this.ugg.getNodes()){
                    if(j.getGroup() == 0){
                        nodesGroup0.offer(j);
                    }
                    else{
                        nodesGroup1.offer(j);
                    }
                }

                //然后输出
                System.out.print("Group 0 hat:\n  ");
                for(Node j : nodesGroup0){
                    System.out.print(j.getValue() + " ");
                }
                System.out.print("\nGroup 1 hat:\n  ");
                for(Node j : nodesGroup1){
                    System.out.print(j.getValue() + " ");
                }
                System.out.print("\n");
            }
        }
    }
}