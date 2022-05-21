package pvl4_ver2;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;


public class HfmTree {
	
	private LinkedList<Node> NodeList = new LinkedList<Node>();
	private Node root;
	private char []charList;

	
	
	public void createHfmTree(float []probs) {
		
		charList = new char[probs.length];
		//0.根据传入的概率数组长度确定拥有的字符个数
		for(int i = 0 ; i < probs.length; i++) {
			char c = (char)(i + 97);
			charList[i] = c;
		}

		
		//1.创建节点
		createNodes(probs);
		
		//2.对节点根据概率进行升序排序
		Sort(NodeList);
		
		//3.取出概率最小的两个节点，生成一个父节点
		//4.删除权值最小的两个节点，将父节点放入列表中
		createTree();
		
		//5.重复3和4。
		//6.将最后一个节点赋给根节点
		root = NodeList.get(0);
	}
	
	private void createNodes(float []probs) {
		for(int i=0; i<probs.length;i++) {
			String data = charList[i] + "";
			Node node = new Node(data, probs[i]);
			NodeList.add(node);
		}
	}
	
	private void Sort(LinkedList<Node> nodeList2) {
		for(int i = 0 ; i < nodeList2.size() - 1; i++) {
			for(int j = i + 1 ; j < nodeList2.size(); j++) {
				Node temp;
				if(nodeList2.get(i).prob > nodeList2.get(j).prob) {
					temp = nodeList2.get(i);
					nodeList2.set(i, nodeList2.get(j));
					nodeList2.set(j, temp);
				}
			}
		}
	}
	
	private void createTree() {
		while(NodeList.size() > 1) {//当节点数目大于1时
			Node left = NodeList.poll();
			Node right = NodeList.poll();
			
			left.code = "1";
			right.code = "0";
			setCode(left);
			setCode(right);
			float parentProb = left.prob + right.prob;
			Node parent = new Node(parentProb, left, right);
			
			NodeList.addFirst(parent);
			Sort(NodeList);
		}
	}
	
	private void setCode(Node root) {
		if(root.lChild != null) {
			root.lChild.code = root.code + "1";
			setCode(root.lChild);
		}
		if(root.rChild != null) {
			root.rChild.code = root.code + "0";
			setCode(root.rChild);
		}
	}
	
	//////////////////////////////OUTPUT///////////////////////////////////
	
	private void output(Node node) {
		if (node.lChild == null && node.rChild == null) {
            System.out.println(node.data + ": " + node.code);
        }
        if (node.lChild != null) {
            output(node.lChild);
        }
        if (node.rChild != null) {
            output(node.rChild);
        }
	}
	
	public void output() {
        output(root);
    }
	
	////////////////////////////////encode//////////////////////////////////
	
	private String hfmStr = "";
	
	public String toHfmCode(String str) {
		for(int i = 0 ; i < str.length(); i++) {
			String c = str.charAt(i) + "";
			search(root , c);
		}
		return hfmStr;
	}
	
	private void search(Node root, String c) {
		if (root.lChild == null && root.rChild == null) {
            if (c.equals(root.data)) {
               // 找到字符，将其哈夫曼编码拼接到最终返回二进制字符串的后面
            	hfmStr += root.code; 
            }
        }
        if (root.lChild != null) {
            search(root.lChild, c);
        }
        if (root.rChild != null) {
            search(root.rChild, c);
        }

	}
	
}
