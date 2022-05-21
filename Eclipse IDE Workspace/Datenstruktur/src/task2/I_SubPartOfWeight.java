package task2;

public interface I_SubPartOfWeight extends I_Weight {
    @Override
    int getWeight();

    int getLeftDistance();
    int getRightDistance();

    int getLeftWeight();
    int getRightWeight();

    I_Weight getLeft();
    I_Weight getRight();
}
