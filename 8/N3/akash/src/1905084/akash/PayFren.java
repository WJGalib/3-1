package akash;

public class PayFren implements ForeignWallet {
    String ssn;
    String currency;
    double balance;
    WalletAdapter adapter;

    public String getSsn() {
        return this.ssn;
    }
    public PayFren (String ssn) {
        this.ssn = ssn;
        this.balance = 10;
        this.currency = "dollar";
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
        System.out.println(getSsn() + ": Sending " + amount + "dollar to account (" + d.getNid() + ")...Current balance dollar " + amount);
        d.receive(adapter, amount);
    }

    public void receive (DigitalWallet d, double amount) {
        setBalance(getBalance() + amount);
        System.out.println(getSsn() + ": Received " + amount + "dollar from account (" + d.getNid() + ")...Current balance dollar " + amount);
        //d.receive(this, amount);
    }
    
};
