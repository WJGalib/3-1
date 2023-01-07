package vending.State;

public interface State {
    public void insertLessMoney (int amount);
    public void insertExactMoney (int amount);
    public void insertExcessMoney (int amount);
    public void returnMoney (int change);
    public void dispenseProduct();
    public void refillMachine (int count);
}
