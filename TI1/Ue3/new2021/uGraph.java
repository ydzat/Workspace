//package TI1.Ue3.new2021.uGraph;

public class uGraph{

    private int[] v;            //默认节点从1开始，顺序递增，即1,2,...
    private int[][] e;          //初始化为空，若存在节点，则变为1。储存格式为二维数组，横纵角标对应节点编号，0为1,1为2...
    private int group;
    private Node[] nodes;       //储存所有节点，默认index = value - 1

    //双模式，flag = 0则是无向图，flag = 1则是有向图
    uGraph(int[] vt, int[][] et, int flag){
        this.v = vt;
        this.e = new int[v.length][v.length];
        for(int[] i : et){
            this.e[i[0]-1][i[1]-1] = 1;
            this.e[i[1]-1][i[0]-1] = 1;     //对于无向图来说，需要此行，若是有向图，则需要删除此行。
        }

        //对于无向图
        if(flag == 0){
            this.nodes = new Node[vt.length];
            for(int i = 0; i < vt.length; i++){
                //得到一行的grad
                int grad = 0;
                for(int j = 0 ; j < vt.length; j++){
                    grad = grad + e[i][j];
                }
                //录入节点
                //int value, int eGrad, int aGrad, int grad
                this.nodes[i] = new Node(this.v[i],0,0,grad);
            }
        }
        //对于有向图
        if(flag == 1){
            //to do
        }
    }

    public void getGraph(){
        System.out.print("  ");
        for(int i = 1; i <= v.length; i++){
            System.out.print(i + " ");
        }
        System.out.print("\n");
        for(int i = 0; i < v.length; i++){
            System.out.print(i+1 + " ");
            for(int j = 0; j < v.length; j++){
                System.out.print(this.e[i][j] + " " );
            }
            System.out.print("\n" );
        }
    }

    public int[] getV(){
        return this.v;
    }

    public int[][] getE(){
        return this.e;
    }

    public Node[] getNodes(){
        return this.nodes;
    }
}