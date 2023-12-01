// calculator app

import javax.swing.*;
import java.awt.*;

public class p2 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("");
        frame.setSize(400, 250);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel = new JPanel(new GridLayout(2, 4));

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
        // Create buttons for the operations
        JButton addButton = new JButton("Add");
        JButton subButton = new JButton("Subtract");
        JButton mulButton = new JButton("Multiply");
        JButton divButton = new JButton("Divide");

        // Add action listeners to the buttons
        addButton.addActionListener(e -> {
            int num1 = Integer.parseInt(fnoField.getText());
            int num2 = Integer.parseInt(snoField.getText());
            int result = num1 + num2;
            submitField.setText(String.valueOf(result));
        });

        subButton.addActionListener(e -> {
            int num1 = Integer.parseInt(fnoField.getText());
            int num2 = Integer.parseInt(snoField.getText());
            int result = num1 - num2;
            submitField.setText(String.valueOf(result));
        });

        mulButton.addActionListener(e -> {
            int num1 = Integer.parseInt(fnoField.getText());
            int num2 = Integer.parseInt(snoField.getText());
            int result = num1 * num2;
            submitField.setText(String.valueOf(result));
        });

        divButton.addActionListener(e -> {
            int num1 = Integer.parseInt(fnoField.getText());
            int num2 = Integer.parseInt(snoField.getText());
            if (num2 != 0) {
                int result = num1 / num2;
                submitField.setText(String.valueOf(result));
            } else {
                submitField.setText("Cannot divide by zero");
            }
        });

        // Add the buttons to the panel
        panel.add(addButton);
        panel.add(subButton);
        panel.add(mulButton);
        panel.add(divButton);

        // Add the panel to the frame
        frame.add(panel);

        // Make the frame visible
        frame.setVisible(true);
    }
}
