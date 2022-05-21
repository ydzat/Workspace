package PVL8;
import java.util.List;

public interface Graph_II {
    Boolean setEdge(int source, int destin);
    List<List<Integer>> getEdges();
    Boolean hasWay(int source, int destin);
    Boolean isConnected();
    Boolean isConnected(List<Integer> nodes);
    List<List<Integer>> getBridges();
    List<Integer> getArticulations();
}

