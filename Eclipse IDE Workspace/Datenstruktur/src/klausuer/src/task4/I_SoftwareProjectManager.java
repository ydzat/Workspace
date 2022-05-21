package task4;

import java.util.List;

public interface I_SoftwareProjectManager {
    I_ProjectClass addProjectClass(String nameOfClass, int estimatedDevelopmentTime);

    boolean canBeFinished();
    List<I_ProjectClass> possibleProcessingSequence();
    List<List<I_ProjectClass>> developmentWithNDevelopers(int numberOfDevelopers);
}
