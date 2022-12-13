package shakebuilder.Builder;

import shakebuilder.Component.Cookies;
import shakebuilder.Component.Candy;


public class Director {
    IBuilder builder;

    public void construct (IBuilder builder) {
        this.builder = builder;
        this.builder.addBaseComponents();
        this.builder.addBundledComponents();
    }

    public void addCookies() {
        this.builder.addCookies();
    }

    public void addCandy() {
        this.builder.addCandy();;
    }

    public void removeLactose() {
        this.builder.removeLactose();
    }
}
