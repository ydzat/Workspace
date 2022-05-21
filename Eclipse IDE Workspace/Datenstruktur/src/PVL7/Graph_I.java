package PVL7;
import java.util.List;

public interface Graph_I {
    Boolean setEdge(int from, int to);
    List<List<Integer>> getEdges();
    List<List<Integer>> getNGons(int n);
    List<Integer> getLongestPath(int from, int to);
    Boolean hasFullCircle();
}
