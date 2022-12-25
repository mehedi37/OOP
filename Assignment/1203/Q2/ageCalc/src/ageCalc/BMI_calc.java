// Roll - 2003009

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.Console;

class myFrame extends JFrame implements ActionListener {    // r ekhane Jframe na JFrame, F capital
    JButton convert = new JButton("BMI Result");
    JTextField input1 = new JTextField();
    JTextField input2 = new JTextField();
    JLabel height = new JLabel("Enter Height in cm");
    JLabel weight = new JLabel("Enter Weight in kg");
    JLabel output = new JLabel("Here");
    Container c;

    myFrame() {
        c = this.getContentPane();
        c.setLayout(null);
        convert.setBounds(110, 190, 120, 20);
        convert.addActionListener(this);    // Action listener attached

        input1.setBounds(30, 155, 140, 20);
        input2.setBounds(180, 155, 140, 20);
        height.setBounds(50, 115, 140, 20);
        weight.setBounds(200, 115, 140, 20);
        output.setBounds(110, 230, 180, 50);

        c.add(convert);
        c.add(input1);
        c.add(input2);
        c.add(height);
        c.add(weight);
        c.add(output);
    }

    // Override kora lagbe Action listener er method ta, nahole run hobe na
    public void actionPerformed(ActionEvent e) {
// Jodi action perform kora hoy & shetar source hocche "convert" button ta then
// nicher if er under er kaj gulo trigger korbe
        if (e.getSource() == convert) {

            // get int value
            float Weight = Float.parseFloat(input2.getText());
            float Height = Float.parseFloat(input1.getText());

            // BMI formula
            float BMI = ( 100 * 100 * Weight) / ( Height * Height );

            //  New line er jonno '\n' support kore na
            // Tai <html> r line break er jonno <br/> use korlam
            if(BMI < 18.5)
                output.setText("<html>Your BMI is : " + BMI + "<br/>You are underweight!</html>");
            else if(BMI < 25)
                output.setText("<html>Your BMI is : " + BMI + "<br/>You are normal</html>");
            else if(BMI < 30)
                output.setText("<html>Your BMI is : " + BMI + "<br/>You are overweight!</html>");
            else
                output.setText("<html>Your BMI is : " + BMI + "<br/>You are obese!</html>");
        }
    }
}

public class BMI_calc {
    public static void main(String[] args) {
        myFrame m = new myFrame();
        m.setTitle("BMI CALCULATOR");
        m.setSize(400, 500);
        m.setVisible(true);
        m.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}