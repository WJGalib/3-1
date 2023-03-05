package akash;

public class Dharai implements ForeignWallet {
    String kojin;
    String currency;
    double balance;
    WalletAdapter adapter;

    public String getKojin() {
        return this.kojin;
    }
    public Dharai (String kojin) {
        this.kojin = kojin;
        this.balance = 1500;
        this.currency = "yen";
        //System.out.println(getName() + " has joined the voyage.");
    }

    public double getBalance() {
        return this.balance;
    }

    public void setBalance (double balance) {
        this.balance = balance;
    }

    public void setAdapter (WalletAdapter a) {
        this.adapter = a;
    }


    public void send (DigitalWallet d, double amount) {
        setBalance(getBalance() - amount);
        System.out.println(getKojin() + ": Sending " + amount + "yen to account (" + d.getNid() + ")...Current balance dollar " + amount);
        d.receive(adapter, amount);
    }

    public void receive (DigitalWallet d, double amount) {
        setBalance(getBalance() + amount);
        System.out.println(getKojin() + ": Received " + amount + "yen from account (" + d.getNid() + ")...Current balance dollar " + amount);
        //d.receive(this, amount);
    }
    
};
