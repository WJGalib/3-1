package akash;

public class Akash implements DigitalWallet {
    String nid;
    String currency;
    double balance;

    public String getNid() {
        return this.nid;
    }
    public Akash (String nid) {
        this.nid = nid;
        this.balance = 1000;
        this.currency = "taka";
        //System.out.println(getName() + " has joined the voyage.");
    }

    public double getBalance() {
        return this.balance;
    }

    public void setBalance (double balance) {
        this.balance = balance;
    }

    public void send (DigitalWallet d, double amount) {
        setBalance(getBalance() - amount);
        System.out.println(getNid() + ": Sending " + amount + "taka to account (" + d.getNid() + ")...Current balance taka " + amount);
        d.receive(this, amount);
    }

    public void receive (DigitalWallet d, double amount) {
        setBalance(getBalance() + amount);
        System.out.println(getNid() + ": Received " + amount + "taka from account (" + d.getNid() + ")...Current balance taka " + amount);
        //d.receive(this, amount);
    }
    
};
