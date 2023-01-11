package vending.State;

import vending.VendingMachine;

public class StockOutState implements State {

    VendingMachine vendingMachine;

    public StockOutState (VendingMachine vendingMachine) {
        this.vendingMachine = vendingMachine;
    }

    public void insertLessMoney (int amount) {
        System.out.println("Cannot accept any requests, the machine is sold out.");
    }

    public void insertExactMoney (int amount) {
        System.out.println("Cannot accept any requests, the machine is sold out.");
    }

    public void insertExcessMoney (int excess) {
        System.out.println("Cannot accept any requests, the machine is sold out.");
    }

    public void returnMoney (int change) {
        System.out.println("Change is not currently due, and the machine is sold out.");
    }

    public void dispenseProduct() {
        System.out.println("No product dispensed. (Out of Stock)");
    }

    public void refillMachine (int count) {
        vendingMachine.refill(count);
        vendingMachine.setState (vendingMachine.getAwaitingMoneyState());
    }
    
}
