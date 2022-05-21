package pvl4_ver2;

import java.util.ArrayList;

public class PVL4_Group13 implements HuffmanCode{
	private char[] alphabet = new char[] {'a','b','c'};
	private float[] probs = new float[]{0.25f, 0.5f, 0.25f};
	HfmTree hfm = new HfmTree();
	@Override
	public String getCodes() {
		// TODO 自动生成的方法存根
		return null;
	}

	
	public String encode(String plainText) {
		// TODO 自动生成的方法存根
		//已经给定了概率，那么可以直接由概率生成哈弗曼树
		//传入probs
		hfm.createHfmTree(probs);
		hfm.output(); //为每个字符根据概率分配编码check √
		
		//根据编码及字母顺序为plainText计算哈弗曼编码
		return hfm.toHfmCode(plainText);
		
		//return null;
	}

	@Override
	public String decode(String huffmanText) {
		// TODO 自动生成的方法存根
		return null;
	}

}
