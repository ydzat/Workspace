//内部类可以随意调用外部类成员

package demo.innerClass.test;

class A {
	int i;
	class B{
		int j;
		int funB() {
			int result = i + j;		//此处完整写法为：int result = A.this.i + j; 此处A.this表示外部类的this，若单独的this.i，则表示内部类的this
			return result;
		}
	}
}
