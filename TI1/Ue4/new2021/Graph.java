//package TI1.Ue3.new2021.uGraph;

public class Graph{

    private int[] v;            //默认节点从1开始，顺序递增，即1,2,...
    private int[][] e;          //初始化为空，若存在节点，则变为1。储存格式为二维数组，横纵角标对应节点编号，0为1,1为2...
    private Node[] nodes;       //储存所有节点，默认index = value - 1

    //双模式，flag = 0则是无向图，flag = 1则是有向图
    Graph(int[] vt, int[][] et, int flag){
        this.v = vt;
        this.e = new int[v.length][v.length];
        for(int[] i : et){
            this.e[i[0]-1][i[1]-1] = 1;
            if(flag == 0){
                this.e[i[1]-1][i[0]-1] = 1;     //对于无向图来说，需要此行，若是有向图，则需要删除此行。
            }
            
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
            this.nodes = new Node[vt.length];
            
            for(int i = 0; i < vt.length; i++){
                int eGrad = 0;
                int aGrad = 0;
                for(int j = 0 ; j < vt.length; j++){
                    //获取出度，即一行中，为1的元素的个数
                    aGrad = aGrad + e[i][j];
                    //获取入度，即一列中，为1的元素的个数
                    eGrad = eGrad + e[j][i];
                }
                this.nodes[i] = new Node(this.v[i],eGrad,aGrad,eGrad+aGrad);
            }
            
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

    public Node[] getNodes() {
        return this.nodes;
    }
    
    public void deleteNode(Node u) {
        //检查要删除的节点
        //System.out.print("值为：" + u.getValue() + "\n");

        /*
        private int[] v;            //默认节点从1开始，顺序递增，即1,2,...
        private int[][] e;          //初始化为空，若存在节点，则变为1。储存格式为二维数组，横纵角标对应节点编号，0为1,1为2...
        private Node[] nodes;       //储存所有节点，默认index = value - 1
        */

        int lengthV = this.v.length;

        //更新入度
        for (int i = 0; i < lengthV; i++) {
            if (this.e[u.getValue() - 1][i] == 1) {
                this.getNodes()[i].setEGrad(this.getNodes()[i].getEGrad()-1);
            }
        }

        //v 对应要删除的节点的值修改为-1
        //e 对应要删除的边的值修改为0，注：此时表示那个顶点为孤点
        //nodes中删除此节点，对应位置置为null
        this.v[u.getValue()-1] = -1;
        for (int i = 0; i < lengthV; i++) {
            this.e[u.getValue()-1][i] = 0;
            this.e[i][u.getValue()-1] = 0;
        }
        this.nodes[u.getValue() - 1] = null;

        
        //检查是否删除正确
        //getGraph();
    
    }
}