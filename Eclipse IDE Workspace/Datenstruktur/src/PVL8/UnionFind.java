package PVL8;

import java.util.List;

public class UnionFind {
	private int []id;
	
	public UnionFind(int n) {
		id = new int[n];
		for(int i = 0; i < n; i++) {
			id[i] = i;
		};
	};
	
	private int root(int i) {
		while(i != id[i]) {
			i = id[i];
		};
		return i;
	};
	
	public boolean hasWay(int source, int destin) {
		return root(source) == root(destin);
	};
	
	
	public void union(int source, int destin) {
		int sourceRoot = root(source);
		int destinRoot = root(destin);
		id[sourceRoot] = destinRoot;
	};
	
}
