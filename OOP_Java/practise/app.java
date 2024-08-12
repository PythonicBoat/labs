import java.io.*;
import java.util.*;
import javax.swing.*;
import java.awt.*;
import javax.swing.*;

public class app {
    JFrame f = new JFrame();
    JButton b = new JButton("click");

    app() {
        b.setBounds(130, 100, 100, 40);
        f.add(b);
        f.setSize(400, 500);
        f.setLayout(null);
        f.setVisible(true);
    }

    public static void main(String[] args) {
        new app();
    }
}
