// 3. image slection and paste on panel label using actionevent

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.filechooser.FileNameExtensionFilter;

public class p3 extends JFrame {
    private JLabel imageLabel;
    private JButton button;

    public p3() {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 400);
        setLayout(new BorderLayout());

        imageLabel = new JLabel();
        button = new JButton("Select Image");

        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JFileChooser fileChooser = new JFileChooser();
                fileChooser.setFileFilter(new FileNameExtensionFilter("Image files", "jpg", "png", "gif", "bmp"));
                int returnValue = fileChooser.showOpenDialog(null);
                if (returnValue == JFileChooser.APPROVE_OPTION) {
                    try {
                        ImageIcon imageIcon = new ImageIcon(fileChooser.getSelectedFile().getPath());
                        imageLabel.setIcon(imageIcon);
                    } catch (Exception ex) {
                        ex.printStackTrace();
                    }
                }
            }
        });

        add(button, BorderLayout.NORTH);
        add(imageLabel, BorderLayout.CENTER);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new p3().setVisible(true);
            }
        });
    }
}