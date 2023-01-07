package vending.State;

import vending.VendingMachine;

public class AwaitingMoneyState implements State {

    VendingMachine vendingMachine;

    public AwaitingMoneyState (VendingMachine vendingMachine) {
        this.vendingMachine = vendingMachine;
    }

    public void insertLessMoney (int amount) {
        vendingMachine.loadAmount(amount);
        int additional = vendingMachine.getProductValue() - vendingMachine.getLoadedAmount();
        System.out.println("To get a product, please insert additional " + additional + " taka.");
    }

    public void insertExactMoney (int amount) {
        vendingMachine.loadAmount(amount);
        vendingMachine.setState (vendingMachine.getSoldState());
        System.out.println("You may press the dispense button now.");
    }

    public void insertExcessMoney (int amount) {
        vendingMachine.loadAmount(amount);
        vendingMachine.releaseChange();
        vendingMachine.setState (vendingMachine.getSoldState());
        System.out.println("You may press the dispense button now.");
    }

    public void returnMoney (int change) {
        System.out.println("Cannot return money because not enough money inserted yet.");
    }

    public void dispenseProduct() {
        System.out.println("Payment needed before delivery");
    }

    public void refillMachine (int count) {
        System.out.println("Machine is currently operational and still not empty");
    }

}
