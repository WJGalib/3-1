package vending;

import vending.State.AwaitingMoneyState;
import vending.State.SoldState;
import vending.State.State;
import vending.State.StockOutState;

public class VendingMachine {
    
    State stockOutState;
    State awaitingMoneyState;
    State soldState;

    State state = stockOutState;
    int count = 0, loadedAmount = 0;
    int productValue;

    public VendingMachine (int count, int productValue) {
        stockOutState = new StockOutState(this);
        awaitingMoneyState = new AwaitingMoneyState(this);
        soldState = new SoldState(this);
        this.count = count;
        this.productValue = productValue;
        if (count > 0) state = awaitingMoneyState;
    }

    public void setState (State state) {
        this.state = state;
        //System.out.println("\u001B[31m going to " + this.state.getClass().getSimpleName() + "\u001B[0m");
    }

    public State getStockOutState() {
        return this.stockOutState;
    }

    public State getAwaitingMoneyState() {
        return this.awaitingMoneyState;
    }
    
    public State getSoldState() {
        return this.soldState;
    }

    public int getCount() {
        return this.count;
    }

    public int getProductValue() {
        return this.productValue;
    }

    public int getLoadedAmount() {
        return this.loadedAmount;
    }



    public void insertMoney (int amount) {
        if (loadedAmount + amount < productValue) state.insertLessMoney(amount);
        else if (loadedAmount + amount > productValue) state.insertExcessMoney(amount);
        else state.insertExactMoney(amount);
    }

    public void dispenseProduct() {
        state.dispenseProduct();
    }

    public void refillMachine (int count) {
        state.refillMachine(count);
        //System.out.println(count + " " + this.count);
    }



    public void loadAmount (int amount) {
        this.loadedAmount += amount;
        System.out.println("You inserted " + amount + " taka.");
    }
    
    public void releaseChange() {
        int change = loadedAmount - productValue;
        loadedAmount -= change;
        System.out.println("\nTk. " + change + " change has been released from the cash return slot.");
    }

    public void releaseProduct() {
        if (loadedAmount != productValue) {
            System.out.println("\nSale completed with balance check, but internal balance mismatch error!");
        } else {
            System.out.println("\nProduct has been dispensed from the delivery slot!");
            loadedAmount -= productValue;
            if (count != 0 && loadedAmount == 0) count--;
            else System.out.println("Internal Error!");
        }
    }

    public void refill (int count) {
        if (this.count == 0) this.count = count;
        System.out.println("Machine refilled!");
    }
}
