import java.util.List;

class Policy extends BasePolicy {

    /*
    class Event {
        Task task;
        int time;
        EventType type;
    }
    class Task {
        int arrivalTime;
        int deadline;
        PriorityType priority;
        int taskId;
    }
    enum EventType {
        Timer,
        TaskArrival,
        TaskFinish,
        IoRequest,
        IoEnd;
    }
    enum PriorityType {
        High,
        Low;
    }
    class Action {
        int cpuTask;
        int ioTask;
    }
    */

    @Override
    protected Action policy(List<Event> events, int currentCpuTask, int currentIoTask) {
        /*
          TODO - your schedule strategy here
         */
        return new Action(0, 0);
    }
}
