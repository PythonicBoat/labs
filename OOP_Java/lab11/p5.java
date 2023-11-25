// 5. take 3 combokd of range 0 to 255 (RGB), selct differnent range from differnet combox and while clicking on button. pandl backlground will be change

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class p5 extends JFrame {
    private JComboBox<Integer> redComboBox, greenComboBox, blueComboBox;
    private JButton changeColorButton;
    private JPanel colorPanel;

    public p5() {
        setTitle("Color Changer App");
        setSize(400, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        redComboBox = new JComboBox<>(createRangeArray());
        greenComboBox = new JComboBox<>(createRangeArray());
        blueComboBox = new JComboBox<>(createRangeArray());

        // Creating JButton for changing color
        changeColorButton = new JButton("Change Color");
        changeColorButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                changeBackgroundColor();
            }
        });

        // Creating JPanel for displaying color
        colorPanel = new JPanel();
        colorPanel.setPreferredSize(new Dimension(400, 150));

        // Setting up the layout
        setLayout(new FlowLayout());
        add(new JLabel("Red:"));
        add(redComboBox);
        add(new JLabel("Green:"));
        add(greenComboBox);
        add(new JLabel("Blue:"));
        add(blueComboBox);
        add(changeColorButton);
        add(colorPanel);

        // Displaying the JFrame
        setVisible(true);
    }

    private Integer[] createRangeArray() {
        Integer[] range = new Integer[256];
        for (int i = 0; i < 256; i++) {
            range[i] = i;
        }
        return range;
    }

    private void changeBackgroundColor() {
        int red = redComboBox.getItemAt(redComboBox.getSelectedIndex());
        int green = greenComboBox.getItemAt(greenComboBox.getSelectedIndex());
        int blue = blueComboBox.getItemAt(blueComboBox.getSelectedIndex());

        colorPanel.setBackground(new Color(red, green, blue));
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new p5();
            }
        });
    }
}
