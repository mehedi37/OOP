// Roll - 2003037
// Assignment 1203, topic 2
package ageCalc;


import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.time.*;

public class ageCalc_main  {


    public static void main(String[] args) {


        JFrame appFrame = new JFrame("Age Calculator By MeEk_0");

        appFrame.setSize(390, 550);
        appFrame.setLocation(100, 150);
        appFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        appFrame.setBackground(Color.DARK_GRAY);

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
        OutputText.setEditable(false);

        //Horoscope Field
        JLabel HoroscopeLabel = new JLabel("Your Horoscope Is:");
        HoroscopeLabel.setBounds(10, 260, 200, 30);
        JTextField HoroscopeText = new JTextField();
        HoroscopeText.setBounds(125, 260, 235, 30);
        HoroscopeText.setEditable(false);


        //Horoscope Field
        JLabel HorResLabel = new JLabel("Horoscope Result:");
        HorResLabel.setBounds(10, 300, 200, 30);
        TextArea HorResText = new TextArea();
        HorResText.setBounds(125, 300, 235, 200);
        HorResText.setEditable(false);
        HorResText.setColumns(10);



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
        appFrame.add(HoroscopeText);
        appFrame.add(HoroscopeLabel);
        appFrame.add(HorResText);
        appFrame.add(HorResLabel);


        //Settings
        appFrame.setLayout(null);
        appFrame.setVisible(true);
        appFrame.setResizable(false);


        //Our Submit button
        JButton appButton = new JButton("Calculate Age");
        appButton.setBounds(50, 170, 120, 30);
        appFrame.add(appButton);
        // clear Button
        JButton appClear = new JButton("Clear");
        appClear.setBounds(180, 170, 120, 30);
        appFrame.add(appClear);

        // Press enter to submit
        appFrame.getRootPane().setDefaultButton(appButton);


        // appButton.addActionListener(this);
        appButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                    // Bttn set
                    appButton.setBackground(new java.awt.Color(76, 112, 176));
                    appButton.setForeground(Color.WHITE);
                    appClear.setBackground(null);
                    appClear.setForeground(null);

                    // Horoscope part
                    String hor[] = {"Capricorn", "Aquarius", "Pisces", "Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn"};
                    String horRes[] = {
                                        "Your generous attitude would be a blessing in disguise as you are likely to be liberated from many vices like doubt, disloyalty, depression, lack of faith, greed, attachment, egoism, and jealousy.\n Those who have borrowed money from anyone may have to repay the loan under any circumstances.\n In such a manner, it can weaken your economic situation.\n Festive atmosphere at home would ease your tension.\n Make sure you also participate in this and not remain like a silent spectator.\n Your presence makes this world a worthy place to be for your beloved.\n Outstation travel will not be comfortable-but will help build important contacts.\n Your parents might bless your spouse with something really wonderful today, which will eventually enhance your married life.\n If you do not have much to do today, you may invest your time in repairing things at your home.\n",
                                        "Your health and energy conservation habit will benefit you immensely as you plan to go on a long journey.\n Despite a busy schedule you will be easily able to cope up with the tiredness.\n You will make substantial gains if you invest on long-term basis.\n Your brother will be more supportive to your needs than you had thought.\n No hope for romance today The day is good.\n Hence, along with others, you will be able to make some quality time for yourself.\n The behavior of your spouse might disturb your professional relations today.\n Do not be upset over the thought that entire day has been wasted, rather think about utilizing rest of the day in the best way possible.\n ",
                                        "A special day today as good health will enable you to do something extraordinary.\n If you are planning on hanging out with your friends, then spend money thoughtfully, as you are likely to suffer from money loss.\n You will expand your base of friends and acquaintances if you participate in social functions and events.\n Exciting day as you receive gifts/presents from your beloved.\n A distant relative can visit your house without any prior notice, which can consume most of your time.\n Your life-partner will put a lot many efforts today for you to make you the happiest.\n A friend of yours can praise you wholeheartedly today.\n ",
                                        "Keep your patience as your continuous effort coupled with common sense and understanding will guarantee your success.\n Visiting the house of close relatives can add to your financial troubles.\n Take the help of your family when you feel lonely.\n It would save you from depression.\n It will also help you in taking sensible decisions.\n Mental turmoil and turbulence as work pressure builds up.\n Relax towards the later half of the day.\n Some of you will undertake a distant journey-which will be hectic-but highly rewarding.\n Laziness of your partner might disturb many of your tasks today.\n You may not be able to rest properly as some of your not-so-friendly friends or relatives just might not let you.\n However, every cloud has a silver lining use this opportunity to create stronger bonds, as it is going to be very useful later.\n",
                                        "Health will remain fine despite a busy schedule.\n Today, investing in land or any property can be fatal for you.\n Avoid making such decisions as much as possible.\n This is the perfect day to attract the attention of others without doing much on your side.\n Opportunities for a romance are apparent- but will be short lived.\n You can spend a good day reading an interesting magazine or novel.\n Your life-partner will give you extra special time today.\n You can go out with your younger brother and have a lot of fun.\n This will strengthen your bond and intensify your relationship.\n ",
                                        "A special day today as good health will enable you to do something extraordinary.\n Use your innovative idea to make some extra money.\n Your children would do their best to keep you happy.\n Be careful somebody may flirt you.\n Amidst your busy life, you will get enough time for yourself today and be able to do your favorite things.\n Rude behavior of your spouse might take a toll on you today.\n A day for doing nothing, just enjoying existence and feeling a sense of gratitude if you do not force yourself in doing unnecessary things.\n",
                                        "Involve yourself in paying some sport as it is the secret of perpetual youth.\n Today, you are likely to attain economic benefits due to your children.\n This will make you very happy.\n You should avoid controversial issues that could cause arguments with loved ones.\n Your love partner will surprise you with something really beautiful today.\n Travel undertaken for business purpose will prove to be beneficial in the long run.\n You will have a stressful relationship with your spouse and there might be serious discord that will last longer than it should.\n Small business companies can treat their employees with a small party to lift up their mood.\n ",
                                        "Friends supportive and will keep you happy.\n If you want to become financially strong in the future, then you have to start saving money from today.\n Younger brother or sister may seek your advice.\n Only by clearly understanding you can give emotional support to your wife.\n Today, you can spend most of your time on things that are not necessary or important.\n You are going to experience a beautiful change in your erotic married life.\n You might feel lazy during the first half of the day, but a lot can be done if you muster the courage to step out of your home.\n",
                                        "Fitness and weight loss programs will help you get into better shape.\n\nLong pending arrears and dues will finally be recovered.\n\nGuests crowd your house for a pleasant and wonderful evening.\n Don't say some mushy things to your sweetheart today.\n Today, you will have ample time to spend with your spouse.\n Your lover will feel overwhelmed at the attention and love s/he will get.\n You might get stressed due to the decrementing health of your spouse today.\n Today, you may feel bugged because of any conflict.\n You should talk to your family members about this and seek a solution.\n ",
                                        "Children will brighten your evening.\n Plan a nice dinner to adieu a dull and hectic day.\n Their company would recharge your body.\n Your financial life will prosper today.\n Along with that, you can get rid of your debts or ongoing loans.\n Do not be erratic in your behaviour-especially with your spouse-otherwise it may mar the peace at home.\n Your day today will be immersed in the colors of love, but you can argue with your beloved over something old during the night.\n Amidst your busy life, you will take out time to spend with your children.\n Spending time with them will make you realize about the things you are missing on.\n Today, you will experience that the love of your partner forgets you about the pains of life.\n An elderly senior at home can impart some knowledge with you today.\n You will like their preaching and try to follow them.\n",
                                        "Sort out your tension for mental peace.\n By spending money on essential household items, you will definitely face financial distress today, but this will save you from many future troubles.\n Evening at the movie-theatre or dinner with your spouse seems to keep you in a relaxed and wonderful mood.\n You would meet the person who loves you more than his life.\n After completing household chores, housewives of this zodiac sign can watch a movie on TV or get engaged in their mobile phones in the free time today.\n Your married life is all about fun, pleasure, and bliss today.\n Do not mind the words of those who are not important in your life.\n ",
                                        "Your childlike nature will surface and you will be in a playful mood.\n Although your financial position improves but the outflow of money will still create hindrance in executing your projects.\n New look- new outfit- new friends could be for you today.\n Unable to cross the social barriars.\n Today, you should drive your vehicle carefully while coming back home from the office at night, otherwise an accident may occur and you may fall ill for several days.\n Your spouse might get too busy with his/her friends today, which might upset you.\n You can have a small party or get-together at home today without telling anyone.\n "
                                    };
                    // Horoscope formatting ends

                    int birthMonth = Integer.parseInt(MonthText.getText());
                    int birthDate = Integer.parseInt(DayText.getText());
                    int birthYear = Integer.parseInt(YearText.getText());

                    LocalDate dob = LocalDate.of(birthYear, birthMonth, birthDate);
                    LocalDate curDate = LocalDate.now();
                    Period period = Period.between(dob, curDate);

                    int Mon = period.getMonths();
                    int Dy = period.getDays();

                    // Horoscope index setting
                    int idx = 0;
                    if (birthMonth == 1) {
                        idx = (birthDate < 20 ? 0 : 1);
                    }
                    else if (birthMonth == 2) {
                        idx = (birthDate < 19 ? 1 : 2);
                    }
                    else if (birthMonth == 3) {
                        idx = (birthDate < 21 ? 2 : 3);
                    }
                    else if (birthMonth == 4) {
                        idx = (birthDate < 20 ? 3 : 4);
                    }
                    else if (birthMonth == 5) {
                        idx = (birthDate < 21 ? 4 : 5);
                    }
                    else if (birthMonth == 6) {
                        idx = (birthDate < 21 ? 5 : 6);
                    }
                    else if (birthMonth == 7) {
                        idx = (birthDate < 23 ? 6 : 7);
                    }
                    else if (birthMonth == 8) {
                        idx = (birthDate < 23 ? 7 : 8);
                    }
                    else if (birthMonth == 9) {
                        idx = (birthDate < 23 ? 8 : 9);
                    }
                    else if (birthMonth == 10) {
                        idx = (birthDate < 23 ? 9 : 10);
                    }
                    else if (birthMonth == 11) {
                        idx = (birthDate < 22 ? 10 : 11);
                    }
                    else if (birthMonth == 12) {
                        idx = (birthDate < 22 ? 11 : 0);
                    }

                    OutputText.setText(String.valueOf(period.getYears()) + " years, " + String.valueOf(Mon) + " months and " + String.valueOf(Dy) + " Days");

                    //
                    HoroscopeText.setText(hor[idx]);
                    HorResText.setText(horRes[idx]);
            }
        });
        appClear.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                OutputText.setText(null);
                HoroscopeText.setText(null);
                HorResText.setText(null);
                DayText.setText(null);
                MonthText.setText(null);
                YearText.setText(null);

                appClear.setBackground(new java.awt.Color(219, 68, 76));
                appClear.setForeground(Color.WHITE);
                appButton.setBackground(null);
                appButton.setForeground(null);
            }
        });
    }


}