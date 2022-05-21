// I/O输入输出流-字节流，适用于少量字符数据
//思路：把源文件中的数据存储到中间数组buffer中，再将buffer数组中的数组输出到目标文件中
//字符输入流：Reader	<-- FileInputStream
//int read(byte [] c, int off, int len)
//字符输出流：Writer	<-- FileOutputStream
//void write(byte [] c, int off, int len)
//byte [] c 要输入/出的数据；int off 偏移量，即要从哪里开始；int len要执行输入/出到哪个长度

//这个中间数组buffer一般要小于源文件大小


package demo.IObyte.test;

import java.io.*;	//导入类

public class Test {
	public static void main(String args[]) {
		FileInputStream fis = null; 	//声明代表输入流的引用
		FileOutputStream fos = null;	//声明代表输出流的引用
		
		try {	//因为在单纯使用输入流是会出现异常，因此在此使用try功能
			//声明输入流的对象
			fis = new FileInputStream("D:/Eclipse IDE Workspace/Test/bin/de/runoob/test/from.txt");
			//声明输出流的对象
			fos = new FileOutputStream("D:/Eclipse IDE Workspace/Test/bin/de/runoob/test/to.txt");
			//生成一个字节数组
			byte[] buffer = new byte[100];
			//调用输入流对象的read方法，读取数据。此处的temp的值等于read()的返回值，其返回值等于输入数据的长度
			int temp = fis.read(buffer,0,buffer.length);
			
			//这个0表示从头开始，temp为录入长度。
			//比如for.write(buffer,5,temp-5)就意味着从第5个元素开始
			fos.write(buffer,0,temp);
			
			//此处是输出buffer数组，查看被流入的数据
			for(int i=0;i<buffer.length;i++){
				System.out.println(buffer[i]);
			}
			
			//因为在byte数组中存储的数据是数字，为了转换回对应字母
			String s = new String(buffer);
			
			//trim()是String的一个对象方法，用处是去除字符串首尾空格
			s = s.trim();
			System.out.println(s);
		}
		catch(Exception e) {
			System.out.println(e);
		}
	} 
}
