package ue1.aufgabe2;

import java.util.ArrayList;

public class Revout {

	//a
	public static String rev(String str) {
		StringBuffer buffer = new StringBuffer(str);
		return buffer.reverse().toString();
	}
	
	
	//b
	public static void revArr(String[] arr) {
		int arrLong = arr.length;
		for(int i = arrLong-1; i >=0; i--) {
			System.out.println(arr[i]);
		}
	}
	
	
	public static void main(String[] args) {
		
		//a
		String str = "Datenstrukturen";
		System.out.println(rev(str));
		
		//b
		String[] fruechte = {"Banane","Apfel","Erdbeere","Orange"};
		revArr(fruechte);
	}

}
