package PVL6;

import java.util.ArrayList;

public class PVL6_Group13 implements SchedulingTask{

	private int kernelNumber;
	
	ArrayList<ProcessImplementation> process = new ArrayList<ProcessImplementation>();
	
	
	PVL6_Group13(int kernelNumber){
		this.kernelNumber = kernelNumber;
	};
	

	
	@Override
	/*
	 * 创建一个进程，该进程含有传递进来的3个参数，并分配PID
	 * PID应在[1,255]之间，获取的值始终为最小值，若PID不可用，则返回-1，否则返回PID
	 * */
	public int createProcess(int arrivalTime, int executionTime, int priority) {
		
		if(process.size() == 0) {
			ProcessImplementation temp = new ProcessImplementation(1, arrivalTime, executionTime, priority);
			process.add(temp);
			return process.get(process.size()-1).getPID();
		}
		else {
			//先判断PID是否可用
			int tPID = process.get(process.size()-1).getPID();
			if( tPID == 255) {
				return -1;
			}
			else {
				ProcessImplementation temp = new ProcessImplementation(tPID+1, arrivalTime, executionTime, priority);
				process.add(temp);
				return process.get(process.size()-1).getPID();
			}
		}
		
	}

	@Override
	public boolean deleteProcess(int pid) {
		// TODO 自动生成的方法存根
		return false;
	}

	@Override
	public String execute() {
		// TODO 自动生成的方法存根
		return null;
	}

}
