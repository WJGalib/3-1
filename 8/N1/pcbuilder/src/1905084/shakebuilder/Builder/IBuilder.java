package shakebuilder.Builder;

import shakebuilder.Shake.Shake;
import shakebuilder.Component.AlmondMilk;
import shakebuilder.Component.Cookies;
import shakebuilder.Component.Candy;



public abstract class IBuilder {
    
    protected Shake pc = new Shake();

    public abstract void addBaseComponents();
    public abstract void addBundledComponents();
    // public void addCustomComponents();

    public void addCookies() {
        pc.addCustomComponent(new Cookies());
    }

    public void addCandy() {
        pc.addCustomComponent(new Candy());
    }

    public void removeLactose() {
        pc.addCustomComponent(new AlmondMilk());
    }

    public abstract Shake getShake();
}
