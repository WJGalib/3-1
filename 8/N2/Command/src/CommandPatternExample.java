//Client
public class CommandPatternExample {
    public static void main(String[] args) {
        System.out.println("***Command Pattern Demo***\n");
        /*Client holds both the Invoker and Command Objects*/
        Receiver intendedReceiver = new Receiver();
        MyUndoCommand undoCmd = new MyUndoCommand(intendedReceiver);
//If you use parameterized constructor of Invoker
//use the following line of code.
//Invoker invoker = new Invoker(undoCmd);
        Invoker invoker = new Invoker();
        invoker.setCommand(undoCmd);
        invoker.invokeCommand();
        MyRedoCommand redoCmd = new MyRedoCommand(intendedReceiver);
        invoker.setCommand(redoCmd);
        invoker.invokeCommand();
    }
}