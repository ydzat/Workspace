package ue2.aufgabe3;
import java.io.IOException;
import java.util.*;
public class Bank {
	ArrayList<String> Accounts; //账户列表
	
	//某个账户的账户余额
	ArrayList<Float> Bargeldvermoegen;
	
	//手续费，比如取款需要扣除手续费
	private Float Buchungsgebuehr;

	Account[] usr;
	
	Bank(){
		
		usr = new Account[100];
		Accounts = new ArrayList<String>();
		Bargeldvermoegen = new ArrayList<Float>();
		Buchungsgebuehr = 12f;
	}
	
	public synchronized void setAccount() {
		
		if(Accounts.size()<100) {
			Scanner scan = new Scanner(System.in);
			System.out.println("plz input ur first Name:");
			
			String firstName = scan.nextLine();
			
			System.out.println("plz input ur last Name:");
			
			String lastName = scan.nextLine();
			
			System.out.println("plz input ur Password:");
			
			int password = Integer.parseInt(scan.nextLine());
			
			
			
			usr[Accounts.size()]= new Account(Accounts.size(),firstName, lastName, password);
			Accounts.add(usr[Accounts.size()].getOwner());
			System.out.println("Ihre Kontonummer:" + (Accounts.size()-1));
		}
		else {
			System.out.println("Die Registrierung ist begrenzt");
		}
		
		
	}
	
	public void getAllAccount() {
		for(int i = 0; i < Accounts.size(); i++) {
			Bargeldvermoegen.add(usr[i].getBalance());
			System.out.println("Kontoinhabe: " + Accounts.get(i) + " Bargeldvermögen: " +  Bargeldvermoegen.get(i));
		}
	}
	
	public int geldtransfer() {
		if(Accounts.size()>1) {
			Scanner scan = new Scanner(System.in);
			System.out.println("Bitte geben Sie Ihre Kontonummer ein:");
			
			int KontoNr;
			while(!scan.hasNextInt()) {
				scan.next();
			}
			KontoNr = scan.nextInt();
			System.out.println("Bitte geben Sie das Passwort ein:");
			Integer Password = scan.nextInt();
			if(usr[KontoNr].verification(Password) == false) {
				
				System.out.println("falsch Password!");
				return 1;
			}
			else {
				System.out.println("access is granted...");
			}
			System.out.println("Bitte geben Sie die empfangende Kontonummer ein:");
			int empKN = scan.nextInt();
			
			System.out.println("Bitte geben Sie den Überweisungsbetrag ein:");
			Float uberweisungsGeld = scan.nextFloat();
			
			if(usr[KontoNr].payOff(uberweisungsGeld)==false) {
				System.out.println("keine genug Geld");
				return 1;
			}
			else {
				
				usr[empKN].deposit(uberweisungsGeld);
				
				System.out.println("Aktuelle Balance:" + usr[KontoNr].getBalance());
				//System.out.println("empKN:" + usr[empKN].getBalance());
			}
			
		}
		else {
			System.out.println("Nicht genug Konten");
		}
		return 0;
	}
	
	public int geldAuszahl() {
		Scanner scan = new Scanner(System.in);
		System.out.println("Bitte geben Sie Ihre Kontonummer ein:");
		
		int KontoNr;
		while(!scan.hasNextInt()) {
			scan.next();
		}
		KontoNr = scan.nextInt();
		System.out.println("Bitte geben Sie das Passwort ein:");
		Integer Password = scan.nextInt();
		if(usr[KontoNr].verification(Password) == false) {
			
			System.out.println("falsch Password!");
			return 1;
		}
		else {
			System.out.println("access is granted...");
		}
		System.out.println("Wie viel möchten Sie abheben:");
		Float geld = scan.nextFloat();
		
		if(usr[KontoNr].payOff(geld+geld*Buchungsgebuehr)==false) {
			System.out.println("keine genug Geld");
			return 1;
		}
		else {
			System.out.println("Bitte nehmen Sie die Währung: Euro " + geld);
			System.out.println("Aktuelle Balance:" + usr[KontoNr].getBalance());
		}
		
		
		
		return 0;
	}
	
	public int geldEinzahl() {
		Scanner scan = new Scanner(System.in);
		System.out.println("Bitte geben Sie Ihre Kontonummer ein:");
		
		
		int KontoNr;
		while(!scan.hasNextInt()) {
			scan.next();
		}
		KontoNr = scan.nextInt();
		
		
		if(KontoNr>=Accounts.size()) {
			System.out.println("Keine solche Nummer!");
		
			return 1;
		}
		
		System.out.println("Bitte geben Sie das Passwort ein:");
		Integer Password = scan.nextInt();
		if(usr[KontoNr].verification(Password) == false) {
			
			System.out.println("falsch Password!");
			return 1;
		}
		else {
			System.out.println("access is granted...");
		}
		
		
		System.out.println("Bitte zahlen Sie Ihr Geld ein:");
		Float geld = scan.nextFloat();
		
		usr[KontoNr].deposit(geld);
		
		System.out.println("Aktuelle Balance:" + usr[KontoNr].getBalance());
		
		return 0;
		
	}
	
	public void clean() {
		try {
			System.in.close();
		} catch (IOException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
	}
	
}
