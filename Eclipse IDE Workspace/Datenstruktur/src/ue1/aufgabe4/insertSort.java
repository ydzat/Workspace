package ue1.aufgabe4;

public class insertSort {

	public static void insertS(Integer [] arr) {
		
		int arrLong = arr.length;
		
		for(int i = 0; i < arrLong-1; i++) {
			for(int j =i+1; j >0; j-- ) {
				if(arr[j]<arr[j-1]) {
					Integer temp = arr[j-1];
					arr[j-1] = arr[j];
					arr[j] = temp;
				}
				else {
					break;
				}
			}
		}
		
		for(int i = 0; i< arrLong; i++) {
			System.out.println(arr[i]);
		}
		
		
	}
	
	public static void main(String[] args) {

		Integer [] arr = {3,7,5,10,6,2,8};
		insertS(arr);
	}

}
