package PVL6;

public class ProcessImplementation implements Process{

	private int pid, arrivalTime, executionTime, priority;
	
	public ProcessImplementation(int pid, int arrivalTime, int executionTime, int priority) {
		this.pid = pid;
		this.arrivalTime = arrivalTime;
		this.executionTime = executionTime;
		this.priority = priority;
		
	};
	
	
	@Override
	public int getPID() {
		// TODO 自动生成的方法存根
		return this.pid;
	}

	@Override
	public int getArrivalTime() {
		// TODO 自动生成的方法存根
		return 0;
	}

	@Override
	public int getExecutionTime() {
		// TODO 自动生成的方法存根
		return 0;
	}

	@Override
	public int getPriority() {
		// TODO 自动生成的方法存根
		return 0;
	}

}
