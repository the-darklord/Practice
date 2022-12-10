import java.util.*;
import javafx.application.*;
import javafx.stage.*;
import javafx.scene.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.event.*;

public class myApp extends Application
{
    public static void main(String[] args)
    {
        launch(args);
    }
    public void start(Stage main) throws Exception
    {
        FlowPane fp = new FlowPane(10,10);
        GridPane gp = new GridPane();
        Scene root = new Scene(gp,800,800);
        Label l1 = new Label("Enter Mark1 : ");
        TextField t1 = new TextField();
        Label l2 = new Label("Enter Mark2 : ");
        TextField t2 = new TextField();
        Label l3 = new Label("Enter Mark3 : ");
        TextField t3 = new TextField();
        Button b1 = new Button("Submit");
        TextField t4 = new TextField();
        Label l4 = new Label("Gender \t");
        RadioButton r1 = new RadioButton("Male \t");
        RadioButton r2 = new RadioButton("Female \t");
        ToggleGroup tg = new ToggleGroup();
        r1.setToggleGroup(tg);
        r2.setToggleGroup(tg);
        b1.setOnAction(new EventHandler<ActionEvent>()
        {
            public void handle(ActionEvent ae)
            {
                Double m1 = Double.parseDouble(t1.getText());
                Double m2 = Double.parseDouble(t2.getText());
                Double m3 = Double.parseDouble(t3.getText());
                Double res = (m1+m2+m3)/30;
                if(r1.isSelected())
                {
                    t4.setText("Gender is "+r1.getText()+"\tGrade is "+res.toString());
                }
                if(r2.isSelected())
                {
                    t4.setText("Gender is "+r2.getText()+"\tGrade is "+res.toString());
                }
            }
        });
        gp.addRow(0,l1,t1);
        gp.addRow(1,l2,t2);
        gp.addRow(2,l3,t3);
        gp.addRow(3,l4,r1,r2);
        gp.addRow(4,b1);
        gp.addRow(5,t4);
        main.setTitle("My App");
        main.setScene(root);
        main.show();
    }
}