package demo.Implements.test;

public class ConPrinter implements Printer{
	public void open() {
		
		System.out.println("Con open");
	}
	public void close() {
		this.clean();
		System.out.println("Con close");
	}
	public void print(String s) {
		System.out.println("Con print --->" + s);
	}
	
	private void clean() {
		System.out.println("clean");
	}
}
