//这是处理流，使用处理流是必用节点流。

//publicStringreadLine()
//一次性读入一行数据，会作为字符串返回给我们
//throwsIOException
//BufferedReader对象的生成方法：BufferedReader in = new BufferedReader(newFileReader("foo.in"));
//newFileReader("文件路径")表示：调用BufferedReader的构造函数，其参数是一个Reader类型的对象。

//这是用了一种   装饰者设计模式


package demo.IObuffered.test;

import java.io.*;

public class test {

	public static void main(String[] args) {
		//首先声明一个FileReader对象
		FileReader fileReader = null;
		//声明一个BufferedReader对象
		BufferedReader bufferedReader = null;
		try {
			//生成FileReader的对象，使用FileReader的对象读取文件数据。此处的FileReader相当于被装饰者。
			fileReader = new FileReader("D:/Eclipse IDE Workspace/Test/bin/demo/IObuffered/test/from.txt");
			//生成BufferedReader的对象，其参数为FileReader的对象fileReader。用BufferedReader的对象对数据进行处理。是装饰者。
			bufferedReader = new BufferedReader(fileReader);
			//建立一个中间变量line，用于存储被BufferedReader读取的对象
			String line = null;
			while(true) {
				//BufferedReader的对象的成员函数readLine()是用于处理节点的。
				line = bufferedReader.readLine();
				
				//readLine返回值为null时，表示已经读取到结尾。
				if(line == null) {
					break;
				}
				System.out.println(line);
			}
		}
		catch(Exception e) {
			System.out.println(e);
		}
		finally {
			try {
				bufferedReader.close();
				fileReader.close();
			}
			catch(Exception e) {
				System.out.println(e);
			}
		}

	}

}
