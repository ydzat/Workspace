	/**
  	 * @description: A method which decodes the huffman text in plain text.
  	 * @author: Julian Nico Pielmaier (591773)
  	 * @return: decoded huffman text
     */ 
public static String decode(String huffmanText) {
		
		StringBuilder tempPlainText = new StringBuilder();
		Node temp = root;


		for (int i = 0; i < huffmanText.length(); i++) {
			int j = Integer.parseInt(String.valueOf(huffmanText.charAt(i)));

			if (j == 1) 
			{
				temp = temp.lChild;
				if (temp.lChild == null && temp.rChild == null) {
					tempPlainText.append(temp.data);
					temp = root;
				};
			};
			if (j == 0) 
			{
				temp = temp.rChild;
				if (temp.lChild == null && temp.rChild == null) {
					tempPlainText.append(temp.data);
					temp = root;
				};
			};
		};
		
		
		String PlainText = tempPlainText.toString();
		
		
		
		return PlainText;

	};
