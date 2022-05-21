//字节法
//字节输入流：Reader	<-- FileReader
//int read(byte [] c, int off, int len)
//字节输出流：Writer	<-- FileWriter
//void write(char [] c, int off, int len)
//char [] c 要输入/出的数据；int off 偏移量，即要从哪里开始；int len要执行输入/出到哪个长度
//这个中间数组buffer一般要小于源文件大小，因此当需要输入/出大文件时，要用到循环。
//此文件未使用循环，可以进一步修改。

package demo.IOchar.test;

import java.io.*;

public class test {
	public static void main(String args []) {
		FileReader fr = null;
		FileWriter fw = null;
		try{
			fr = new FileReader("D:/Eclipse IDE Workspace/Test/bin/demo/IOchar/test/from.txt");
			fw = new FileWriter("D:/Eclipse IDE Workspace/Test/bin/demo/IOchar/test/to.txt");
			char [] buffer = new char[200];
			int temp = fr.read(buffer,0,buffer.length);
		
			fw.write(buffer,0,temp);
		}
		catch(Exception e) {
			System.out.println(e);
		}
		finally {
			try {
				fr.close();
				fw.close();
			}
			catch(Exception e) {
				System.out.println(e);
			}
		}
	}
}
