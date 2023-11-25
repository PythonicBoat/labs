// calculator app

import javax.swing.*;
import java.awt.*;

public class p2 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("");
        frame.setSize(400, 250);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel = new JPanel(new GridLayout(4, 2));

        JLabel fnoLabel = new JLabel("Enter First Number : ");
        JTextField fnoField = new JTextField();

        JLabel snoLabel = new JLabel("Enter Second Number : ");
        JTextField snoField = new JTextField();

        JLabel submitLabel = new JLabel("Result : ");
        JTextField submitField = new JTextField();

        JButton submitButton = new JButton("Submit");

        panel.add(fnoLabel);
        panel.add(fnoField);  
        panel.add(snoLabel);
        panel.add(snoField);
        panel.add(submitLabel);
        panel.add(submitField);
        panel.add(submitButton);

        frame.add(panel);
        frame.setVisible(true);
    }
}
