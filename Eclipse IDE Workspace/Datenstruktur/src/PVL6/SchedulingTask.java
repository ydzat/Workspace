package PVL6;

public interface SchedulingTask {
    int createProcess(int arrivalTime, int executionTime, int priority);
    boolean deleteProcess(int pid);
    String execute();
}
