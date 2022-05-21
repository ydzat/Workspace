/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| HfmTree.java:                                                                |
|      PVL4_Group13                                                            |
|                                                                              |
| V1.0.0-en_GB // (20200521/20200521)                                                         |
| (C)  Dongze Yang (574145)                                                    |
|                                                                              |
\******************************************************************************/

/*CHANGELOG********************************************************************\
|                                                                              |
|                                                                              |
|                                                                              |
|                                    CAPTION                                   |
|                                                                              |
| + feature added                                                              |
| - feature removed                                                            |
| > feature imported                                                           |
| ! bugfix                                                                     |
| ? feature udea left for future version                                       |
| * information                                                                |
|   (editing periods in brackets behind version                                |
|                                                                              |
|                                                                              |
|                                                                              |
|==============================================================================|
|                                                                              |
|                                                                              |
|                                                                              |
| V1.0.0-en_GB // (20200521/20200521):                                                         |
| + made it work as it should and not only as it was coded                     |
|                                                                              |
|                                                                              |
|                                                                              |
\******************************************************************************/

/*TODO*************************************************************************\
|                                                                              |
| Nothing left to do!                                                          |
|                                                                              |
\******************************************************************************/

/*TESTING INFORMATION**********************************************************\
|                                                                              |
|                                                                              |
|                                                                              |
\******************************************************************************/



/*SECTION**********************************************************************\
|                                                                              |
| Package                                                                      |
|                                                                              |
\******************************************************************************/
package PVL4_Group13;
// .



/*SECTION**********************************************************************\
|                                                                              |
| Resources                                                                    |
|                                                                              |
\******************************************************************************/
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
// .



/*SECTION**********************************************************************\
|                                                                              |
| Class definition (I)                                                         |
|                                                                              |
\******************************************************************************/

/**
 * PVL4_Group13
 *
 * @author	Dongze Yang
 * @version	V1.0.0-en_GB // (20200521/20200521)
 */
public class HfmTree
{



/*SECTION**********************************************************************\
|                                                                              |
| Instance variables                                                           |
|                                                                              |
\******************************************************************************/

	/**
  	 * @description: Required member variables
     * @param NodeList: Used to store all node information
	 *        root: Store root node information
	 		  charList: Store all the letters that will be involved
  	 * 
  	 */
	private LinkedList<Node> NodeList = new LinkedList<Node>();
	private Node root;
	private char []charList;

/*SECTION**********************************************************************\
|                                                                              |
| Instance methods                                                             |
|                                                                              |
\******************************************************************************/

	/**
  	 * @description: Create a Huffman tree
 	 * @param probs: Data from PVL4_Group13.encode()
  	 * @return: no return
  	 */
	public void createHfmTree(float []probs) {
		
		/**
   		 * @description: 0.Determine the number of characters according to the length of the incoming probability array 
  		 */
		charList = new char[probs.length];
		
		for(int i = 0 ; i < probs.length; i++) {
			char c = (char)(i + 97);
			charList[i] = c;
		}

		

		/**
  		 * @description: 1. Create Node
  		 */
		createNodes(probs);
		
		/**
  		 * @description: 2. Sort nodes in ascending order according to probability
  		 */
		Sort(NodeList);
		
		/**
  		 * @description: 3.Take the two nodes with the smallest probability and generate a parent node
		   		4. Delete the two nodes with the smallest probability and put the parent node in the list
  		 */
		createTree();
		
		//5. Repeat 3 and 4
		
		/**
  		 * @description: 6. Assign the last node to the root node
  		 */
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
		while(NodeList.size() > 1) {
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
	/**
  	 * @description: Used to output all nodes, for testing
	 *   The content of this piece can be deleted!
   	 */
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
	/**
   	 * @description: Through traversal, use the recursive method to find the characters 
		of the leaf node, and stitch together with the "current node" code each time
   	 * @param {type} 
  	 * @return: 
   	 */
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
               // splice
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

};



/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| EOF                                                                          |
|                                                                              |
\******************************************************************************/
