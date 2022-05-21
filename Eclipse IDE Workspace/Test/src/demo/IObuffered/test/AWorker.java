package demo.IObuffered.test;

public class AWorker implements Worker{
	private Worker worker;
	public AWorker(Worker worker) {
		this.worker = worker;
	}
	public void work() {
		System.out.println("你好");
		worker.work();
	}
}
