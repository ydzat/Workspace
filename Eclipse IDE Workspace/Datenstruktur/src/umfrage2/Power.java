package umfrage2;

import java.util.ArrayList;

public class Power {

	
	
	public static void main(String[] args) {
		String seq = "GEEKSFORGEEKS";
		int n = seq.length();
		System.out.printf("%d",lps(seq.toCharArray(),0,n-1));
	}
	
	static int max(int x, int y) {
		return (x>y)? x:y;
	}
	
	static int lps(char seq[], int i , int j) {
		if(i == j) {
			return 1;
		}
		if(seq[i] == seq[j]&&i + 1==j) {
			return 2;
		}
		if(seq[i] == seq[j]) {
			return lps(seq, i+1,j-1)+2;
			
		}
		return max(lps(seq,i,j-1),lps(seq,i+1,j));
	}
	
	
}
