package ageCalc;


import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.time.*;

public class ageCalc_main  {


    public static void main(String[] args) {


        JFrame appFrame = new JFrame("Age Calculator By MeEk_0");

        appFrame.setSize(390, 300);
        appFrame.setLocation(100, 150);
        appFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        //Label and TextField
        JLabel Day = new JLabel("Day Born:");
        Day.setBounds(10, 10, 200, 30);
        JTextField DayText = new JTextField();
        DayText.setBounds(85, 10, 200, 30);



        //Month Label and TextField
        JLabel Month = new JLabel("Month Born:");
        Month.setBounds(10, 50, 200, 30);
        JTextField MonthText = new JTextField();
        MonthText.setBounds(85, 50, 200, 30);




        //Year Label and TextField
        JLabel Year = new JLabel("Year Born:");
        Year.setBounds(10, 90, 200, 30);
        JTextField YearText = new JTextField();
        YearText.setBounds(85, 90, 200, 30);


        //Output Field
        JLabel OutputLabel = new JLabel("Your Current Age Is:");
        OutputLabel.setBounds(10, 220, 200, 30);
        JTextField OutputText = new JTextField();
        OutputText.setBounds(125, 220, 235, 30);



        //Formatting the System's current time
        DateFormat dateFormat = new SimpleDateFormat(("yyyy"));
        Date date = new Date();
        JLabel CurrentYear = new JLabel("Current Year: ");
        CurrentYear.setBounds(10, 135, 200, 30);



        //Printing that current time
        JTextField DateText = new JTextField(dateFormat.format(date));
        DateText.setBounds(87, 135, 200, 30);


        //Adding objects to our Frame
        appFrame.add(Day);
        appFrame.add(Month);
        appFrame.add(Year);
        appFrame.add(CurrentYear);
        appFrame.add(DayText);
        appFrame.add(YearText);
        appFrame.add(MonthText);
        appFrame.add(DateText);
        appFrame.add(OutputText);
        appFrame.add(OutputLabel);


        //Settings
        appFrame.setLayout(null);
        appFrame.setVisible(true);
        appFrame.setResizable(false);


        //Our Submit button
        JButton appButton = new JButton("Calculate Age");
        appButton.setBounds(120, 170, 120, 30);
        appFrame.add(appButton);

        // Press enter to submit
        appFrame.getRootPane().setDefaultButton(appButton);


        // appButton.addActionListener(this);
        appButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                int birthMonth = Integer.parseInt(MonthText.getText());
                int birthDate = Integer.parseInt(DayText.getText());
                int birthYear = Integer.parseInt(YearText.getText());

                LocalDate dob = LocalDate.of(birthYear, birthMonth, birthDate);
                LocalDate curDate = LocalDate.now();
                Period period = Period.between(dob, curDate);

                OutputText.setText(String.valueOf(period.getYears()) + " years, " + String.valueOf(period.getMonths()) + " months and " + String.valueOf(period.getDays()) + " Days");
                // OutputLabel.setText("MeEk_0");
            }
        });
    }


}