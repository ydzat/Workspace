package pvl3_Ver_ydz;

import pvl3.Calculator;
import static java.lang.System.out;
import java.util.ArrayList;
import java.util.Collection;
import java.math.*;

public class Calculator_Group13 implements Calculator {
///////////////////////////////////////////////////////////////////////////////////////私有成员变量
	private ArrayList<Character> A;
	private ArrayList<Integer> B;
	private ArrayList<Character> C;
	private ArrayList<Character> sequence;
///////////////////////////////////////////////////////////////////////////////////////
	@Override
	public boolean isValidExpression(String expression) {
		// TODO 自动生成的方法存根
		
		boolean valid = true;
		
		setSeq(expression);
		
		ArrayList<Integer> leftBrackets = new ArrayList<Integer>();
		ArrayList<Integer> rightBrackets = new ArrayList<Integer>();;
		
		for(int i = 0 ; i < sequence.size()-1; i++) {
			//判断除了括号以外，是否有两个B或者两个A相连
			if((sequence.get(i) == sequence.get(i+1)) && ( sequence.get(i) !='C')) {
				valid = false;
			}
		}
		//判断左右括号是否正确
		for(int i = 0; i < expression.length(); i++) {
			if(expression.charAt(i) == '(') {
				leftBrackets.add(i);
			}
			if(expression.charAt(i) == ')') {
				rightBrackets.add(i);
			}
		}
		//先判断个数是否相等
		if(leftBrackets.size() != rightBrackets.size()) {
			valid = false;
		}
		else {
			//判断左右括号是否匹配(左括号在前，右括号在后), 判断左右括号是否直接相邻
			for(int i = 0 ; i < leftBrackets.size(); i++) {
				if((leftBrackets.get(i) > rightBrackets.get(i)) || (leftBrackets.get(i) == rightBrackets.get(i) -1 )) {
					valid = false;
					break;
				}
			}
			
			
		}
		
		
		//判断输入字符串中数字是否存在
		if(sequence.contains('B') == false) {
			valid = false;
		}
		
		//判断数字个数是否=加、乘个数 + 1
		/*if(A.size() != 0) {
			if(A.size() + 1 != B.size()) {
				valid = false;
			}
		}*/
		if(valid == true) {
			setA(expression);
			setB(expression);
		}
		
		return valid;
	}
///////////////////////////////////////////////////////////////////////////////////////判断是否为有效表达式的子函数
	private void setSeq(String expression) {
		
		int seqLength = (expression.length()+1)/2;
		sequence = new ArrayList<Character>(seqLength);
		for(int i = 0 ; i < expression.length(); i++) {
			if(expression.charAt(i) == ' ') {
				continue;
			}
			if((expression.charAt(i) == '+') || (expression.charAt(i) == '*') ) {
				sequence.add('A');
			}
			if(expression.charAt(i)<='9' && expression.charAt(i)>='0') {
				sequence.add('B');
			}
			if((expression.charAt(i) == '(') || (expression.charAt(i) == ')') ) {
				sequence.add('C');
			}
		}
		
		for(int i = sequence.size() - 1 ; i >0 ; i--) {
			if(sequence.get(i) != 'B') {
				continue;
			}
			
			if(sequence.get(i-1) == 'B') {
				sequence.remove(i);
			}
			
		}
		
		
	}
	
	private void setA(String expression) {
		A = new ArrayList<Character>();
		
		for(int i = 0; i < expression.length(); i++) {
			if(expression.charAt(i) == '+' || expression.charAt(i) == '*') {
				A.add(expression.charAt(i));
			}
		}
	}
	

	
	private void setB(String expression) {
		B = new ArrayList<Integer>();
		//System.out.println("表达式长度为："+ expression.length() );
		for(int i = 0; i < expression.length()-1; i++) {
			if(expression.charAt(i) == ' ') {
				continue;
			}
			if((Character.isDigit(expression.charAt(i)) == true) || (expression.charAt(i) == '-')) {
				ArrayList<Character> temp = new ArrayList<Character>();
				temp.add(expression.charAt(i));
				for(int j = i+1; j < expression.length(); j++) {
					
					if(!Character.isDigit(expression.charAt(j))) {
						break;
					}
					else {
						temp.add(expression.charAt(j));
						i = j;
					}	
				}
				
				//System.out.println("temp为"+ temp );
				
				
				int digits = 0;
				if(temp.get(0) != '-') {
					digits = temp.size();
					int sum = 0;
					for(int j = 0 ; j < digits; j ++) {
						sum = (int) (sum + Integer.parseInt(temp.get(j).toString())*(Math.pow(10,digits-j-1)));
					}
					B.add(sum);
				}
				else {
					digits = temp.size() - 1;
					int sum = 0;
					for(int j = 0 ; j < digits; j ++) {
						sum = (int) (sum + Integer.parseInt(temp.get(j+1).toString())*(Math.pow(10,digits-j-1)));
					}
					B.add(sum);
				}
				
			}
			
		}
		//System.out.println("当前B："+ B );
	}

	private void setC(String expression) {
	
	}

	public ArrayList<Character> getA() {
		return A;
	}
	
	public ArrayList<Integer> getB() {
		return B;
	}
	
	public ArrayList<Character> getC() {
		return C;
	}
	
///////////////////////////////////////////////////////////////////////////////////////
	@Override
	public int calculate(String expression) {
		// TODO 自动生成的方法存根
		return 0;
	}

}
