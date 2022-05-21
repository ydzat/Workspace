package demo.Implements.test;

public class PrinterChoise {
	public static Printer getPrinter(int flag) {
		Printer printer = null;
		if(flag == 0){
			printer = new HPPrinter();
		}
		else if(flag == 1){
			printer = new ConPrinter();
		}
		else if(flag == 2){
			printer = new QHPrinter();
		}
		return printer;
	}
}
