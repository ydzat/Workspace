package task4;

import java.util.List;

public interface I_ProjectClass {
    String getName();
    int getEstimatedDevelopmentTime();
    void setDependencies(I_ProjectClass projectClass);
    List<I_ProjectClass> getDependencies();
}
