// 6. one program using mouseadapter class

import javax.swing.*;
import java.awt.event.*;

public class p6 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("MouseAdapter Demo");
        JLabel label = new JLabel("Hover and click me!");

        label.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseEntered(MouseEvent e) {
                label.setText("Mouse entered!");
            }

            @Override
            public void mouseExited(MouseEvent e) {
                label.setText("Mouse exited!");
            }

            @Override
            public void mouseClicked(MouseEvent e) {
                label.setText("Mouse clicked!");
            }
        });

        frame.add(label);
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}