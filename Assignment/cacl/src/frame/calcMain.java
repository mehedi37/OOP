package frame;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

class myFrameCalc extends JFrame implements ActionListener, MouseListener {
// New lable, aligned to right
    JLabel lbl = new JLabel("Display Here", SwingConstants.RIGHT);

// Array of button
    JButton bx[] = new JButton[16];


// Inputs here
    /*
    * Str1 is first number before operation
    * str2 is second number after operation sign
    */
    String str1 = "", str2 = "";

    // Operation char saved here
    String op = "";

    // values in integer form from str1 & str 2
    int val1 = 0, val2 = 0;


// Display font changed
    Font disFont = new Font("DigifaceWide", Font.ITALIC, 22);

// Container created, which will contain all buttons and display
    Container c;

// Function constructor
    myFrameCalc(String s) {
        this.setTitle(s);
        c = this.getContentPane();
        lbl.setBounds(5, 7, 275, 40);
        lbl.setBackground(Color.white);
        lbl.setOpaque(true);
        c.setLayout(null);
        c.setBackground(Color.DARK_GRAY);

        // Button starts 1-9
        int i = 1, k = 1, j = 1, xStart = 20, xIncrement = 62, yStart = 65,  yIncrement = 65;
        for (i = 1; i < 10; i++) {
            bx[i] = new JButton(Integer.toString(i));
            bx[i].setBounds(xStart+(j-1)*xIncrement, yStart+(k-1)*yIncrement, 60, 60);
            c.add(bx[i]);

            // action listener
            bx[i].addActionListener(this);
            bx[i].addMouseListener(this);
            j++;
            if (i%3 == 0) {
                k++;
                j = 1;
            }

        }
        // For zero
        bx[0] = new JButton("0");
        bx[0].setBounds(xStart, yStart+(k-1)*65, 60, 60);
        bx[0].addActionListener(this);
        bx[0].addMouseListener(this);
        c.add(bx[0]);


        // Operational buttons
        String btnChar[] = {"+", "-", "=", "x", "/", "C"};

        for (i = 10, j = 1; i < 16; i++, j++) {
            bx[i] = new JButton(btnChar[i-10]);
            bx[i].setBounds(xStart+j*xIncrement, yStart+(k-1)*yIncrement, 60, 60);
            bx[i].addActionListener(this);
            bx[i].addMouseListener(this);
            c.add(bx[i]);
            if (i > 11) {
                k--;
                j = 2;
            }
            if (i == 12) {      // For equal button
                bx[i].setBackground(Color.yellow);
            }
            if (i == 15) {  // For Clear button
                bx[i].setBackground(Color.red);
            }
        }
        lbl.setFont(disFont);
        c.add(lbl);


    }

    @Override
    public void actionPerformed(ActionEvent e) {

        // To clear the display
        if (e.getSource() == bx[15]) {
            str1 = "";
            str2 = "";
            op = "";
            lbl.setText(str1);
        } else if (op != "") {          // get the str2
            for (int j = 0; j < 10; j++) {
                if (e.getSource() == bx[j]) {
                    str2 += Integer.toString(j);
                    lbl.setText(str2);
                }
            }
            val1 = Integer.parseInt(str1);
            val2 = Integer.parseInt(str2);
            switch(op) {
                case "+": str1 = Integer.toString(val1+val2); break;
                case "-": str1 = Integer.toString(val1-val2); break;
                case "x": str1 = Integer.toString(val1*val2); break;
                case "/": str1 = (val2 != 0 ? Double.toString(Math.floor(((double)(val1)/val2) * 1000000) / 1000000) : "Math Error"); break;
                case "=": lbl.setText(str1); op = ""; break;
            }

            // Reseting values
            op = "";
            str2 = "";
            val1 = 0;
            val2 = 0;
        } else {        // If any operation key is pressed (+, -, /, *)
            for (int i = 10; i < 16; i++) {
                if (e.getSource() == bx[i]) {
                    System.out.println("OP triggered");
                    switch(i) {
                        case 10: op = "+"; break;
                        case 11: op = "-"; break;
                        case 12: op = str1; break;
                        case 13: op = "x"; break;
                        case 14: op = "/"; break;
                    }
                }
            }
            lbl.setText(op);
            for (int i = 0; i < 10; i++) {
                if (e.getSource() == bx[i]) {
                    str1 += Integer.toString(i);
                    lbl.setText(str1);
                }
            }
        }
    }

    @Override
    public void mouseClicked(MouseEvent e) {

    }

    @Override
    public void mousePressed(MouseEvent e) {

    }

    @Override
    public void mouseReleased(MouseEvent e) {

    }

    @Override
    public void mouseEntered(MouseEvent e) {

        for (int i = 0; i < 16; i++) {
            if (e.getSource() == bx[15]) {
                bx[15].setForeground(Color.WHITE);
            } else if (e.getSource() == bx[i]) {
                bx[i].setForeground(Color.red);
            }
        }
    }

    @Override
    public void mouseExited(MouseEvent e) {
        for (int i = 0; i < 16; i++) {
            if (e.getSource() == bx[i]) {
                bx[i].setForeground(null);
            }
        }
    }
}
public class calcMain {
    public static void main(String[] args) {
        myFrameCalc meek = new myFrameCalc("Meek's calc");
        meek.setBounds(100, 50, 300, 400);
        meek.setVisible(true);
        meek.setResizable(false);
        meek.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
