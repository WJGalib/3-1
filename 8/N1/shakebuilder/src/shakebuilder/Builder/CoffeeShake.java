package shakebuilder.Builder;
import shakebuilder.Component.ChocolateIcecream;
import shakebuilder.Component.ChocolateSyrup;
import shakebuilder.Component.Milk;
import shakebuilder.Component.RegularMilk;
import shakebuilder.Component.Sugar;
import shakebuilder.Shake.*;

public class CoffeeShake extends IBuilder {

    private Shake pc = super.pc;

    public void addBaseComponents() {
        pc.setBasePrice(230);
        pc.addBaseComponent(new RegularMilk());
        pc.addBaseComponent(new Sugar());
        pc.addBaseComponent(new ChocolateIcecream());
        pc.addBaseComponent(new ChocolateSyrup());
    }

    public void addBundledComponents() {
        pc.setName("Coffee_shake");
    }

    public Shake getShake() {
        return pc;
    }  
}
