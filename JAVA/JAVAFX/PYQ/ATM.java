import java.util.*;
import javafx.application.*;
import javafx.stage.*;
import javafx.scene.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.event.*;
import javafx.scene.paint.*;
import javafx.scene.text.*;
import javafx.scene.canvas.*;
import javafx.scene.shape.*;
import javafx.geometry.*;
import javafx.collections.*;
import javafx.beans.value.*;

class Account
{
    long accnum;
    String name;
    Double balance;
    int pin;
    Account(long accnum,String name,Double balance,int pin)
    {
        this.accnum=accnum;
        this.name=name;
        this.balance=balance;
        this.pin=pin;
    }
    void Deposit(Double amount)
    {
        balance+=amount;
    }
    void WithDraw(Double amount)
    {
        if(balance>500&&balance>amount)
        {
            balance-=amount;
        }
        else
        {
            System.out.println("Can't WithDraw");
        }
    }
    void Display()
    {
        System.out.println("Name : "+name+"\nACC/No : "+accnum+"\nBalance : "+balance);
    }
}

public class ATM extends Application
{
    public static void main(String[] args)
    {
        launch(args);
    }
    public void start(Stage stage) throws Exception
    {
        Account a1 = new Account(7673916996L,"Mihir",10000.00,6996);
        Account a2 = new Account(6300961913L,"Hruthik",50000.00,2004);

        GridPane gp = new GridPane();
        gp.setHgap(10);
        gp.setVgap(10);
        gp.setAlignment(Pos.CENTER);

        Label l1 = new Label("Account Operations \n");
        Label l2 = new Label("Enter Account No : \t");
        Label l3 = new Label("Enter Your Pin : \t");
        Label l4 = new Label("Select Operation : \t");
        Label l5 = new Label("Enter Amount ; \t");
        Label l6 = new Label();

        TextField t1 = new TextField();
        PasswordField p1 = new PasswordField();
        TextField t2 = new TextField();
        RadioButton r1 = new RadioButton("Deposit");
        RadioButton r2 = new RadioButton("WithDraw");
        r1.fire();
        ToggleGroup tg = new ToggleGroup();
        r1.setToggleGroup(tg);
        r2.setToggleGroup(tg);
        Button b1 = new Button("SUBMIT");

        b1.setOnAction(new EventHandler<ActionEvent>(){
            public void handle(ActionEvent ae)
            {
                if(r1.isSelected())
                {
                    if(Long.parseLong(t1.getText())==a1.accnum)
                    {
                        if(Integer.parseInt(p1.getText())==a1.pin)
                        {
                            a1.Deposit(Double.parseDouble(t2.getText()));
                            l6.setText("Name : "+a1.name+"\tAccount Balance : "+a1.balance);
                        }
                        else
                        {
                            l6.setText("Incorrect Pin");
                        }
                    }
                    else if(Long.parseLong(t1.getText())==a2.accnum)
                    {
                        if(Integer.parseInt(p1.getText())==a2.pin)
                        {
                            a2.Deposit(Double.parseDouble(t2.getText()));
                            l6.setText("Name : "+a2.name+"\tAccount Balance : "+a2.balance);
                        }
                        else
                        {
                            l6.setText("Incorrect Pin");
                        }
                    }
                    else
                    {
                        l6.setText("Specified Account Not Found");
                    }
                }
                if(r2.isSelected())
                {
                    if(Long.parseLong(t1.getText())==a1.accnum)
                    {
                        if(Integer.parseInt(p1.getText())==a1.pin)
                        {
                            a1.WithDraw(Double.parseDouble(t2.getText()));
                            l6.setText("Name : "+a1.name+"\tAccount Balance : "+a1.balance);
                        }
                        else
                        {
                            l6.setText("Incorrect Pin");
                        }
                    }
                    else if(Long.parseLong(t1.getText())==a2.accnum)
                    {
                        if(Integer.parseInt(p1.getText())==a2.pin)
                        {
                            a2.WithDraw(Double.parseDouble(t2.getText()));
                            l6.setText("Name : "+a2.name+"\tAccount Balance : "+a2.balance);
                        }
                        else
                        {
                            l6.setText("Incorrect Pin");
                        }
                    }
                    else
                    {
                        l6.setText("Specified Account Not Found");
                    }
                }
            }
        });

        gp.addRow(0,l1);
        gp.addRow(1,l2,t1);
        gp.addRow(2,l3,p1);
        gp.addRow(3,l4,r1,r2);
        gp.addRow(4,l5,t2);
        gp.addRow(5,b1);
        gp.addRow(6,l6);

        stage.setTitle("Account Operations");
        Scene scene = new Scene(gp,800,800);
        stage.setScene(scene);
        stage.show();
    }
}