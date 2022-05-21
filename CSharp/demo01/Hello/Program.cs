using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

//命名空间/名字空间
namespace Hello
{
    //类型class

    public class Human {

        private int age;
        private string name;
        private static bool canFly = false;
        public Human(string name, int age) {
            this.age = age;
            this.name = name;
        }

        public Tuple<string, int> getData() { 
            Tuple<string, int> t = new Tuple<string, int>(name, age);
            return t;
        }

        //属性Property，看起来像变量的函数
        //通过get和set来实现 可读/可写 的封装
        //尽管Age是public的，但其操作的数据age，是private的——当然，这要求private int age
        public int Age
        {
            get {
                return age;
            }
            set {
                age = value;
            }
        }

        public string Name
        {
            get
            {
                return name;
            }
            set
            {
                name = value;
            }
        }

        //简写
        public bool CanFly {
            get => canFly;
            set => canFly = value;
        }

    }

    //继承
    //Attribute属性，可以给函数、变量、类型等添加额外的用户自定义信息，方便对语言扩展。配合反射来用
    //反射：用于获取代码信息：信息类型、变量、函数
    
    public abstract partial class Actor {
        
        private static string true_name = "Savior";
        public string nick_name;
        
        public int health;
        public int mona;
        
        protected Dictionary<string,int> attrs;
        protected Dictionary<string, int> skills;

        public string True_name {
            get => true_name;
            set => true_name = value; 
        }

        public Dictionary<string, int> Attrs { get => attrs; }

        public Actor() {
            attrs = new Dictionary<string, int>() {
                { "pow" , 50},
                { "str", 50},
                { "san", 50}
            };
        }

        public virtual void Fist_Attack() {
            Random rd = new Random();
            int damage;
            int roll = rd.Next(0, 100);
            Console.WriteLine("roll = "+roll);
            if (roll > 3 && roll <= attrs["pow"])
            {
                damage = rd.Next(1, 6);
                Console.WriteLine("造成"+damage+"点伤害");
            }
            else if (roll <= 3)
            {
                damage = 6;
                Console.WriteLine("造成" + damage + "点伤害");
            }
            else if (roll > attrs["pow"] && roll < 98)
            {
                damage = 0;
                Console.WriteLine("我们未能击穿敌人的装甲");
            }
            else {
                damage = rd.Next(0, 2);
                Console.WriteLine("大失败，损失" + damage + "点血量");
            }
        }
        public virtual void Update() { }

    }

    public class Knight : Actor {
        
        public override void Update() {
            attrs["pow"] += 10;
            Console.WriteLine("力量+"+10+ " = "+attrs["pow"]);
        }
        public Knight() {
            Update();
        }
    }




    //泛型，用于简化代码：
    /*
     对于几个类，若他们的区别仅仅是类型不同，那么可以用泛型来一次性实现
     */
    public partial class IntVector {
        public int x;
        public int y;
        public IntVector(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    public partial class FloatVector
    {
        public float x;
        public float y;
        public FloatVector(float x, float y)
        {
            this.x = x;
            this.y = y;
        }
    }
    
    //以上两个类仅有类型不同，因此可以变化为：
    /*
     在主类中的调用：
    Vector<int> v1 = new Vector<int>(0,1);
    Vector<float> v2 = new Vector<float>(0,0f, 1,0f);

    此外，泛型要求必须实现构造函数，才能使用new 
     */
    public class Vector<T> { 
        public T x;
        public T y;
        public Vector(T x, T y) { this.x = x; this.y = y; }
    }


    //除了泛型类，还有泛型函数
    public class Shooter :Actor{
        public static void Attack<T>(T a, T b) 
        where T: Actor{     //这一行表示，T受Actor约束，即T继承自Actor
            a.Fist_Attack();
            b.Fist_Attack();
        }
    }

    //表示约束继承自哪些类，哪些接口
    public class Vector2<T1, T2>
        where T1 : class, IComparable<T1>
        where T2 : class{

        public T1 x;
        public T2 y;
    }


    //class拓展
    /*
    可以拓展一些已经存在的class，而无需修改源码。
    增加额外的接口，方便调用。
    必须是静态类，函数前面使用this关键字
     */
    //例如，为float类型添加直接变成int的方法
    public static class Float_toInt_Ext {
        public static int toInt(this float val) {
            return (int)val;
        }
    }
    //那么，在主类中，就可以有以下操作：
    /*
    float valf = 1.5f;
    int valI = valf.toInt();
     */


    //主类
    internal class Program
    {
        //函数/方法
        //函数
        //返回值类型 函数名(参数列表){代码块; return 返回值;}
        static void PrintSomething(string val)
        {
            Console.Write(val);
        }

        //ref关键字可以是变量在函数内被修改，类似于指针
        static int selfPlusOne(ref int val) {
            val++;
            return val;
        }

        //函数指针
        /*
        delegate: 可以保存多个函数指针，使用+=, -=进行操作
        匿名函数：方便编写
        Action: 无返回值的delegate
        Func: 有返回值的delegate
        监听者模式
         */
        delegate float Calculation(float val1, float val2);
        static float sum(float val1, float val2)
        {
            return val1 + val2;
        }
        static float minu(float val1, float val2)
        {
            return val1 - val2;
        }


        //主函数
        static void Main(string[] args)
        {


            //输入与输出
            string inputStr = null;
            inputStr = Console.ReadLine();
            string outputStr = "Hi, " + inputStr;
            Console.WriteLine(outputStr);

            //数组
            int[] arr = new int[10];
            for (int i = 0; i < arr.Length; i++) {
                arr[i] = i;
            }
            foreach (int i in arr) { 
                Console.Write(i + " ");
            }
            PrintSomething("\n");

            //强制类型转换
            float valFloat = 3.14f;
            int valInt = (int)valFloat;

            string valStr = "5";
            int valInt2 = int.Parse(valStr);
            long valLong = long.Parse(valStr);
            string valStr2 = valLong.ToString();

            //字符串格式化
            int result = 3;
            string inputStr2 = "val";
            string str1 = inputStr2 + " antwort: " + result;
            string str2 = $"{inputStr2} antwort: {result}";
            
            //函数调用
            PrintSomething(str1);
            PrintSomething("\n");
            PrintSomething(str2);
            PrintSomething("\n");


            //字符串子串查找
            string str3 = "Hello,ydz";
            //返回子串的第一个字符的下标，此处index = 2
            int index = str3.IndexOf("llo,");
            //替换子串，Replace(所要替换的子串，用于替换的内容)
            //此处替换后结果为：你好,ydz
            string str4 = str3.Replace("Hello", "你好");
            //根据下标切片，Substring(起始下标，切片长度)
            //结果为：ydz
            string str5 = str3.Substring(6, 3);

            int val = 5;
            selfPlusOne(ref val);
            PrintSomething(val.ToString());
            PrintSomething("\n");

            Human p1 = new Human("杨东泽", 27);

            var p = p1.getData();
            PrintSomething(p.Item1);
            PrintSomething(" ");
            PrintSomething(p.Item2.ToString());
            PrintSomething("\n");

            p1.Age = 28;
            p1.Name = "刘悦";
            PrintSomething(p1.Name);
            PrintSomething(" ");
            PrintSomething(p1.Age.ToString());
            PrintSomething("\n");



            Knight stupid_face = new Knight();
            stupid_face.nick_name = "Astral";
            
            foreach(int i in Enumerable.Range(0, 5)) {
                stupid_face.Fist_Attack();
                Thread.Sleep(100);
            }
            Console.WriteLine("我的pow = " + stupid_face.Attrs["pow"]);

            //容器

            //List 动态数组，自动增长
            List<int> list = new List<int>();
            list.Add(1);
            list.Add(2);
            list.Add(3);
            list.Insert(0, 4);
            list.Remove(3);
            list[1] = 12;
            list.Sort();

            //字典Dictionary
            Dictionary<string, int> dict = new Dictionary<string, int> { 
                { "pow",0 },
                { "str",0},
                { "san",0}
            };

            dict.Add("spd", 0);
            dict["pow"] = 1;
            dict.Remove("str");
            var keys = dict.Keys;
            var vals = dict.Values;

            //HashSet 保证存储元素是唯一的
            HashSet<int> set = new HashSet<int>();
            set.Add(1);
            set.Add(2);
            set.Add(3);
            set.Add(4);
            set.Add(4);     //因为是唯一的，所以添加失败，返回false
            set.Add(4);
            set.Remove(3);
            set.Contains(2);    //是否存在

            //队列Queue
            Queue<int> fifo = new Queue<int>();
            fifo.Enqueue(1);
            fifo.Enqueue(2);
            fifo.Enqueue(3);
            fifo.Dequeue(); //输出1
            fifo.Dequeue(); //2
            fifo.Dequeue(); //3

            //栈Stack
            Stack<int> filo = new Stack<int>();
            filo.Push(1);
            filo.Push(2);
            filo.Push(3);
            filo.Push(4);
            filo.Pop(); //4
            filo.Pop(); //3

            
            

            
            Calculation listenerFunc = sum;
            listenerFunc(1, 2); //返回值是3
            listenerFunc += minu;   //此时同时指向sum和minu
            listenerFunc(8, 9); //返回值是 3 和 -1
            listenerFunc -= sum;    //将指向的sum去掉，此时仅指向minu
            listenerFunc(5, 2); //返回值是3
            
            //匿名函数1，用Action的对象closure指向一个无名称函数，该函数的功能是val3+=10
            int val3 = 10;
            Action closure = () =>
            {
                val3 += 10;
            };
            closure();
            //匿名函数2
            Func<int,int> f = (int x) =>
            {
                return x ^ 2;
            };



            //异常处理try...catch
            void TestException()
            {
                try
                {
                    //something
                }
                catch (NullReferenceException e)       //e的类型是错误类型，有很多
                {
                    Console.WriteLine(e.ToString());
                    throw;      //抛出异常

                }
                catch (Exception e)
                {       //指全部异常
                    Console.WriteLine(e.ToString());
                    //或者自定义抛出异常
                    throw new Exception("异常~~~~~");
                }
                finally { 
                    //最终一定执行的语句
                }

            }




        }

        
    }




}



