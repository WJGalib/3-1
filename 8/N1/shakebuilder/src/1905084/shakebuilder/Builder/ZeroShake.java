package shakebuilder.Builder;
import shakebuilder.Component.ChocolateIcecream;
import shakebuilder.Component.ChocolateSyrup;
import shakebuilder.Component.RegularMilk;
import shakebuilder.Shake.*;

public class ZeroShake extends IBuilder {

    private Shake pc = super.pc;

    public void addBaseComponents() {
        pc.setBasePrice(240);
        pc.addBaseComponent(new RegularMilk());
        pc.addBaseComponent(new ChocolateIcecream());
        pc.addBaseComponent(new ChocolateSyrup());
    }

    public void addBundledComponents() {
        pc.setName("Zero_shake");
    }

    public Shake getShake() {
        return pc;
    }  
}
