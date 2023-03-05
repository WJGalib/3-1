package akash;

public class WalletAdapter implements DigitalWallet {
    ForeignWallet fw;

    public WalletAdapter (ForeignWallet fw) {
        this.fw = fw;
        //PayFren.printRed(getName() + " has started using the Crewmate Adapter as a disguise.");
    }

    public double getBalance() {
        return fw.getBalance();
    }

    public String getNid() {
        if (fw instanceof PayFren) return ((PayFren)(this.fw)).getSsn();
        if (fw instanceof Dharai) return ((Dharai)(this.fw)).getKojin();
        //if (fw instanceof Akash) return ((PayFren)(this.fw)).getKojin();
        return "";
    }

    public void send (DigitalWallet d, double amount) {
        if (fw instanceof PayFren) amount *= 100;
        if (fw instanceof Dharai) amount /= 2;
        fw.send (d, amount);
    }

    public void receive (DigitalWallet d, double amount) {
        if (fw instanceof PayFren) amount /= 100;
        if (fw instanceof Dharai) amount *= 2;
        fw.receive (d, amount);

    }
}
