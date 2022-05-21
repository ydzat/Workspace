public class Node{

    private int value;      //节点值
    private int eGrad;      //入度，初始值为0
    private int aGrad;      //出度，初始值为0
    private int grad;       //度，无向图专用，初始值为0
    private int group;      //所属组，二分图专用，初始值为0
    private String col; //设置遍历后的颜色，初值为weiss
    
    private Node pi;         //Tiefensuchwald, 值为第一个指向本节点的父节点。
    private int d;          //Beendezeit
    private int f;

    Node(int value, int eGrad, int aGrad, int grad){
        this.value = value;
        this.eGrad = eGrad;
        this.aGrad = aGrad;
        this.grad = grad;
        this.group = 0;
        this.col = new String("weiss");
        
    }

    public void setGroup(int group){
        this.group = group;
    }

    public void setEGrad(int eGrad){
        this.eGrad = eGrad;
    }

    public void setAGrad(int aGrad){
        this.eGrad = aGrad;
    }

    public void setGrad(int grad){
        this.eGrad = grad;
    }

    public void setCol(String col){
        this.col = col;
    }

    public void setPi(Node pi){
        this.pi = pi;
    }

    public void setD(int d) {
        this.d = d;
    }
    
    public void setF(int f){
        this.f = f;
    }

    public int getValue(){
        return this.value;
    }

    public int getEGrad(){
        return this.eGrad;
    }

    public int getAGrad(){
        return this.aGrad;
    }

    public int getGrad(){
        return this.grad;
    }

    public int getGroup(){
        return this.group;
    }

    public String getCol(){
        return this.col;
    }

    public Node getPi(){
        return this.pi;
    }

    public int getD() {
        return this.d;
    }
    
    public int getF(){
        return this.f;
    }


}