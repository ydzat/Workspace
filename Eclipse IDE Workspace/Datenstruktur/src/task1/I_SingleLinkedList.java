package task1;

public interface I_SingleLinkedList {
    I_Node getHead();
    void addAtEnd(int value);
    void deleteSubList(int startNodeIndex, int nodesToDelete);
    @Override
    String toString();
}
