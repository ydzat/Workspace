public class Node{

    private int value;      //节点值
    private int eGrad;      //入度，初始值为0
    private int aGrad;      //出度，初始值为0
    private int grad;       //度，无向图专用，初始值为0
    private int group;      //所属组，二分图专用，初始值为0

    Node(int value, int eGrad, int aGrad, int grad){
        this.value = value;
        this.eGrad = eGrad;
        this.aGrad = aGrad;
        this.grad = grad;
        this.group = 0;
        
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




}