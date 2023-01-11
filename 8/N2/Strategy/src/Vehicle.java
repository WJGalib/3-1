public abstract class Vehicle
{
    /*A context object contains reference variable/s for the strategy
    object/s interface type.*/
    TransportMedium transportMedium;
    public Vehicle()
    {
    }
    public void showTransportMedium()
    {
//Delegate the task to the //corresponding behavior class.
        transportMedium.transport();
    }
    //The code that does not vary.
    public void commonJob()
    {
        System.out.println("We all can be used to transport");
    }
    public abstract void showMe();
}