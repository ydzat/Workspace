package demo.Implements.test;

public class Text {
	public static void main(String args[]) {
		
		//根据用户的选择，生成相应的打印机对象，并且向上转型为Printer类型
		int flag = 2;
		Printer printer = PrinterChoise.getPrinter(flag);
		//////////////////////////////
		
		
		printer.open();
		printer.print("ABC");
		printer.close();
	}
}
