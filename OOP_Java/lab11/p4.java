// 4. desing 5 button and change the panel background color with click of differnet button

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class p4 extends JFrame {
    private JPanel panel;
    
    public p4() {
        setTitle("Button Color Change");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        panel = new JPanel();
        add(panel);

        createButtons();

        setVisible(true);
    }

    private void createButtons() {
        String[] buttonNames = {"RED", "BLUE", "GREEN", "YELLOW", "ORANGE"};

        for (String name : buttonNames) {
            JButton button = new JButton(name);
            button.addActionListener(new ButtonClickListener());
            panel.add(button);
        }
    }

    private class ButtonClickListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            JButton sourceButton = (JButton) e.getSource();
            String buttonText = sourceButton.getText();

            switch (buttonText) {
                case "RED":
                    panel.setBackground(Color.RED);
                    break;
                case "BLUE":
                    panel.setBackground(Color.BLUE);
                    break;
                case "GREEN":
                    panel.setBackground(Color.GREEN);
                    break;
                case "YELLOW":
                    panel.setBackground(Color.YELLOW);
                    break;
                case "ORANGE":
                    panel.setBackground(Color.ORANGE);
                    break;
                default:
                    panel.setBackground(Color.WHITE);
            }
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new p4());
    }
}
