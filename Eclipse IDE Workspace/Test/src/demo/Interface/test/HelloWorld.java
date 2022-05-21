package demo.Interface.test;



public class HelloWorld {
	public static void main(String []args) {
		Phone phone = new Phone();
		USB usb = phone;
		usb.read();
		usb.write();
		
		WiFi wifi = phone;
		wifi.open();
		wifi.close();
		
		WiFi4G wifi4G = phone;
		wifi4G.data();
		wifi4G.data4G();
		
	}
}
