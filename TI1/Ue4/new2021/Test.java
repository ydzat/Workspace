public class Test{
    public static void main(String[] args) {

        //有环有向图
        int[] v={1,2,3,4,5,6};
        int[][] e = { { 1, 2 }, { 2, 3 }, { 2, 4 }, { 3, 4 }, { 3, 6 }, { 5, 1 }, { 5, 6 }, { 6, 1 } };

        //无环有向图
        int[] v1 = { 1, 2, 3 };
        int[][] e1 = { { 1, 2 }, { 1, 3 }, { 2, 3 } };

        //无向图
        

        Graph g1 = new Graph(v, e, 1);
        g1.getGraph();

        // DFS dfs1 = new DFS(g1);
        // dfs1.choDFS(0);
        // dfs1.showDSF();

        // TopoS top1 = new TopoS(g1, 1);
        // top1.showTopo();

        // Graph g2 = new Graph(v1, e1, 1);
        // g2.getGraph();
        // TopoS top2 = new TopoS(g2, 1);
        // top2.showTopo();

    }
}