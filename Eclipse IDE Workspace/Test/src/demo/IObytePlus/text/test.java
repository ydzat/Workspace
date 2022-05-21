// I/O输入输出流-字节流，用循环进行大量字符的输入输出
//思路：把源文件中的数据存储到中间数组buffer中，再将buffer数组中的数组输出到目标文件中
//这个中间数组buffer一般要小于源文件大小，因此才需要用到循环输入


package demo.IObytePlus.text;

import java.io.*;	//导入类

public class test {
	public static void main(String args[]) {
		FileInputStream fis = null; 	//声明代表输入流的引用
		FileOutputStream fos = null;	//声明代表输出流的引用
		
		try {	//因为在单纯使用输入流是会出现异常，因此在此使用try功能
			//声明输入流的对象
			fis = new FileInputStream("D:/Eclipse IDE Workspace/Test/bin/demo/IObytePlus/text/from.txt");
			//声明输出流的对象
			fos = new FileOutputStream("D:/Eclipse IDE Workspace/Test/bin/demo/IObytePlus/text/to.txt");
			//生成一个字节数组
			byte[] buffer = new byte[1024];
			
			
			/*调用输入流对象的read方法，读取数据。
			 此处的temp的值等于read()的返回值，其返回值等于输入数据的长度
			当read返回值为-1时，意味着数据读取完毕
			*/
			while(true) {
				int temp = fis.read(buffer,0,buffer.length);
				if(temp ==  -1) {
					break;
				}
				fos.write(buffer,0,temp);
			}
			
			
			/*此处是输出buffer数组，查看被流入的数据
			for(int i=0;i<buffer.length;i++){
				System.out.println(buffer[i]);
			}*/
			
			//因为在byte数组中存储的数据是数字，为了转换回对应字母
			String s = new String(buffer);
			
			//trim()是String的一个对象方法，用处是去除字符串首尾空格
			s = s.trim();
			System.out.println(s);
		}
		catch(Exception e) {
			System.out.println(e);
		}
		//当用完输入和输出流之后，需要关闭这两个流
		finally{
			//因为单独用close()时会产生异常，因此在此必须再用一个try-catch
			try {
				fis.close();
				fos.close();
			}
			catch(Exception e) {
				System.out.println(e);
			}
		}
		
		
		
	} 
}
