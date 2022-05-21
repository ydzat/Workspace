package pvl4_ver2;

public class Node {
	public float prob;
	public Node lChild;
	public Node rChild;
	public String code = "";
	public String data = "";
	
	
	
	public Node(float prob) {
		this.prob = prob;
	}
	
	public Node(String data, float prob) {
        this.data = data;
        this.prob = prob;
    }
	
	public Node(float prob, Node lChild, Node rChild) {
		this.prob = prob;
	    this.lChild = lChild;
	    this.rChild = rChild;
	 }

}
