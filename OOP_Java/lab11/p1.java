// 1.  Desingn a Form - containig Fname, lastname address Qualifcation, Skillset, hobbies, gender, image , submitbutton and other field

import javax.swing.*;
import java.awt.*;

public class p1 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Form Example");
        frame.setSize(400, 500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel = new JPanel(new GridLayout(9, 2));

        JLabel fnameLabel = new JLabel("First Name:");
        JTextField fnameField = new JTextField();

        JLabel lnameLabel = new JLabel("Last Name:");
        JTextField lnameField = new JTextField();

        JLabel addressLabel = new JLabel("Address:");
        JTextField addressField = new JTextField();

        JLabel qualificationLabel = new JLabel("Qualification:");
        JTextField qualificationField = new JTextField();

        JLabel skillsetLabel = new JLabel("Skillset:");
        JTextField skillsetField = new JTextField();

        JLabel hobbiesLabel = new JLabel("Hobbies:");
        JTextField hobbiesField = new JTextField();

        JLabel genderLabel = new JLabel("Gender:");
        JRadioButton maleButton = new JRadioButton("Male");
        JRadioButton femaleButton = new JRadioButton("Female");
        JLabel sectionBreak1 = new JLabel(" ");
        
        ButtonGroup genderGroup = new ButtonGroup();
        genderGroup.add(maleButton);
        genderGroup.add(femaleButton);

        // add a break here;
        JLabel sectionBreak = new JLabel(" ");
        JButton submitButton = new JButton("Submit");

        panel.add(fnameLabel);
        panel.add(fnameField);  
        panel.add(lnameLabel);
        panel.add(lnameField);
        panel.add(addressLabel);
        panel.add(addressField);
        panel.add(qualificationLabel);
        panel.add(qualificationField);
        panel.add(skillsetLabel);
        panel.add(skillsetField);
        panel.add(hobbiesLabel);
        panel.add(hobbiesField);
        panel.add(genderLabel);
        panel.add(sectionBreak1);
        panel.add(maleButton);
        panel.add(femaleButton);
        panel.add(sectionBreak);
        panel.add(submitButton);

        frame.add(panel);
        frame.setVisible(true);
    }
}