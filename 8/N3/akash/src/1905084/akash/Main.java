package akash;

import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class Main {


    public static void main(String[] args) throws Exception {

        Random rand = new Random();
        

        DigitalWallet a0 = new Akash("NID0");
        DigitalWallet a1 = new Akash("NID1");
        PayFren p0 = new PayFren("SSN0");
        Dharai d0 = new Dharai("KB0");

        DigitalWallet pa0 = new WalletAdapter(p0);
        DigitalWallet da0 = new WalletAdapter(d0);
        p0.setAdapter((WalletAdapter)pa0);
        d0.setAdapter((WalletAdapter)da0);


        a0.send (a1, 500);
        a1.send (pa0, 200);
        a1.send (da0, 800);


        System.exit(0);
    }
}
