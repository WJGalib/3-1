package akash;

public interface DigitalWallet {
    public String getNid();
    public double getBalance();

    public void send (DigitalWallet d, double amount);
    public void receive (DigitalWallet d, double amount);
}
