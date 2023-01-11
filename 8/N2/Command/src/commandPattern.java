interface Command
{
    //Typically this method does not take any argument.
//Some of the reasons are:
//1.We supply all the information when it is created.
//2.Invoker may reside in different address space.etc.
    void executeCommand();
}
class MyUndoCommand implements Command
{
    private Receiver receiver;
    public MyUndoCommand(Receiver receiver)
    {
        this.receiver=receiver;
    }
    @Override
    public void executeCommand()
    {
//Perform any optional task prior to UnDo
        receiver.doOptionalTaskPriorToUndo();
//Call UnDo in receiver now
        receiver.performUndo();
    }
}
class MyRedoCommand implements Command
{
    private Receiver receiver;
    public MyRedoCommand(Receiver receiver)
    {
        this.receiver=receiver;
    }
    @Override
    public void executeCommand()
    {
//Perform any optional task prior to ReDo
        receiver.doOptionalTaskPriorToRedo();
//Call ReDo in receiver now
        receiver.performRedo();
    }
}
//Receiver Class
class Receiver
{
    public void performUndo()
    {
        System.out.println("Performing an undo command in Receiver.");
    }
    public void performRedo()
    {
        System.out.println("Performing an redo command in Receiver.");
    }
    /*Optional method-If you want to perform
    any prior tasks before undo operations.*/
    public void doOptionalTaskPriorToUndo()
    {
        System.out.println("Executing -Optional Task/s prior to execute undo command.");
    }
    /*Optional method-If you want to perform
    any prior tasks before redo operations*/
    public void doOptionalTaskPriorToRedo()
    {
        System.out.println("Executing -Optional Task/s prior to execute redo command.");
    }
}
//Invoker class
class Invoker
{
    Command commandToBePerformed;
    //Alternative approach:
//You can also initialize the invoker with a command object
/*public Invoker(Command command)
{
this.commandToBePerformed = command;
}*/
//Set the command
    public void setCommand(Command command)
    {
        this.commandToBePerformed = command;
    }
    //Invoke the command
    public void invokeCommand()
    {
        commandToBePerformed.executeCommand();
    }
}
