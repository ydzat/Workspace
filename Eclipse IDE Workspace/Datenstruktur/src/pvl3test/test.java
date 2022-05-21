package pvl3test;

import pvl3_Ver_ydz.Calculator_Group13;

public class test {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Calculator_Group13 cal = new Calculator_Group13();
		
		String richtig[] = {
				"( 12 + ( 4 * 3 ) + 5 * 10 )",
				"( 10 )",
				"10",
				"10 + ( 2 * 12 ) + 8",
				"5 + ( ( 8 + 4 ) * 6 )",
				"5 + 5",
				"( 10 ) + ( 10 )",
				"-4",
				"-4 + 5",
				"-4 + ( 6 )"
				
		};
		
		String falseAusdruck[] = {
			"( 12 + 4",
			"12 + + 4",
			"12 + * 2",
			"+",
			"()()()",
			"",
			")10(",
			"(+1)",
			"()(1)"
		};
		
		for(int i = 0 ; i < richtig.length; i++) {
			System.out.println("exp = " + richtig[i] + " = " + cal.isValidExpression(richtig[i]));
		}
		
		System.out.println("///////////////////////////////////////");
		for(int i = 0 ; i < falseAusdruck.length; i++) {
			System.out.println("exp =  " + falseAusdruck[i] + " = " + cal.isValidExpression(falseAusdruck[i]));
		}
		
		
		
		
		
	}

}
