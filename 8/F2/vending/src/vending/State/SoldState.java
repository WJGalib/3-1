package vending.State;

import vending.VendingMachine;

public class SoldState implements State {

    VendingMachine vendingMachine;

    public SoldState (VendingMachine vendingMachine) {
        this.vendingMachine = vendingMachine;
    }

    public void insertLessMoney (int amount) {
        System.out.println("A sale was just made and product is being dispensed, cannot insert money now");
    }

    public void insertExactMoney (int amount) {
        System.out.println("A sale was just made and product is being dispensed, cannot insert money now");
    }

    public void insertExcessMoney (int excess) {
        System.out.println("A sale was just made and product is being dispensed, cannot insert money now");
    }

    public void returnMoney (int change) {
        System.out.println("Change is not currently due, or has already been released.");
    }

    public void dispenseProduct() {
        vendingMachine.releaseProduct();
        if (vendingMachine.getCount() > 0) {
            vendingMachine.setState (vendingMachine.getAwaitingMoneyState());
        } else {
            System.out.println("\nThe machine just ran out of products!");
            vendingMachine.setState (vendingMachine.getStockOutState());
        }
    }

    public void refillMachine (int count) {
        System.out.println("Machine is currently operational and still not empty");
    }
    
}
