package PVL7;

public class dfsStack{
	private int size;
	private int[] st;
	private int top;
	
	public dfsStack(int size) {
		this.size = size;
		st = new int[size];
		top = -1;
	};
	
	public void push(int i) {
		st[++top] = i;
	};
	
	public int pop() {
		return st[top--];
	};
	
	public int getThis() {
		return st[top];
	};
	
	public boolean isEmpty() {
		return (top == -1);
	};
	
};
