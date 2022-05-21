package demo.Interface.test;

public class Phone implements USB,WiFi,WiFi4G{
	public void read() {
		System.out.println("USBPhone read");
	}
	
	public void write() {
		System.out.println("USBPhone write");
	}
	
	public void open() {
		System.out.println("WiFi open");
	}
	public void close() {
		System.out.println("WiFi close");
	}
	
	public void data() {
		System.out.println("WiFi4G data");
	}
	
	public void data4G() {
		System.out.println("WiFi4G data4G");
	}
}
