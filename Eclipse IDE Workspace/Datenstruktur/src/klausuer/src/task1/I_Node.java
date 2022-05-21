package task1;

public interface I_Node {
    int getValue();
    void setNext(I_Node node);
    I_Node getNext();
    @Override
    String toString();
}
