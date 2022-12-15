import java.util.*;
import javafx.application.*;
import javafx.stage.*;
import javafx.scene.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.scene.paint.*;
import javafx.scene.text.*;
import javafx.scene.canvas.*;
import javafx.scene.shape.*;
import javafx.geometry.*;
import javafx.event.*;
import javafx.collections.*;
import javafx.beans.value.*;

public class exam extends Application
{
    public static void main(String[] args)
    {
        launch(args);
    }
    public void start(Stage stage) throws Exception
    {
        // FlowPane fp = new FlowPane(10,10);
        GridPane gp = new GridPane();
        gp.setHgap(10);
        gp.setVgap(10);

        stage.setTitle("Practice");
        gp.setAlignment(Pos.CENTER);

        Label l1 = new Label("Detail Form\n");
        Label l2 = new Label("\nEnter Name");
        TextField t1 = new TextField();
        t1.setPromptText("Enter Name ");
        Button b1 = new Button("Submit");
        Label l3 = new Label();

        Label l4 = new Label("\nGender : \t");
        RadioButton r1 = new RadioButton("Male");
        RadioButton r2 = new RadioButton("Female");
        ToggleGroup tg = new ToggleGroup();
        r1.setToggleGroup(tg);
        r2.setToggleGroup(tg);
        r1.fire();

        Label l5 = new Label("\nAge : \t");
        String s[] = {"Below 18","19-30","31-50","51-80","80+"};
        ComboBox<String> cb = new ComboBox<String>(FXCollections.observableArrayList(s));
        cb.setValue("Below 18");

        Label l6 = new Label("==> \t");
        ToggleButton tb = new ToggleButton("Virgin");

        Label l7 = new Label("\nHobbies : \t");
        CheckBox c1 = new CheckBox("Movies & TV Shows");
        CheckBox c2 = new CheckBox("Sports");
        CheckBox c3 = new CheckBox("Books");
        CheckBox c4 = new CheckBox("Cooking");

        Label l8 = new Label("List View");
        Label l9 = new Label();
        ListView<String> lv = new ListView<String>(FXCollections.observableArrayList("User","Bot","Moderator","Admin","Owner"));
        lv.setPrefSize(70,70);
        lv.getSelectionModel().selectedItemProperty().addListener(new ChangeListener<String>(){
            public void changed(ObservableValue<? extends String>changed,String ov,String nv)
            {
                l9.setText("Role : \t"+nv);
            }
        });
        // fp.getChildren().addAll(l1,l2,t1,b1,l3);

        EventHandler<ActionEvent> ae = new EventHandler<ActionEvent>()
        {
            public void handle(ActionEvent AE)
            {
                l3.setText(" ");
                String gen=" ";
                String vir=" ";
                String hob = " ";
                if(r1.isSelected())
                {
                    gen = r1.getText();
                }
                else if(r2.isSelected())
                {
                    gen = r2.getText();
                }
                if(tb.isSelected())
                {
                    vir = "A "+tb.getText();
                }
                else
                {
                    vir = "Not a "+tb.getText();
                }
                if(c1.isSelected())
                {
                    hob+=c1.getText();
                }
                if(c2.isSelected())
                {
                    hob+=" , "+c2.getText();
                }
                if(c3.isSelected())
                {
                    hob+=" , "+c3.getText();
                }
                if(c4.isSelected())
                {
                    hob+=" , "+c4.getText();
                }
                String res = "\n\nDetails are\n"+"\nName : \t"+t1.getText()+"\n\nGender : \t"+gen+"\n\nAge : \t"+cb.getValue()+"\n\n"+vir+"\n\nHobbies : \t"+hob;
                l3.setText(res);
            }
        };

        b1.setOnAction(ae);

        gp.addRow(0,l1);
        gp.addRow(1,l2,t1);
        gp.addRow(2,l4,r1,r2);
        gp.addRow(3,l5,cb);
        gp.addRow(4,l6,tb);
        gp.addRow(5,l7,c1,c2,c3,c4);
        gp.addRow(6,l8,lv);
        gp.addRow(7,b1);
        gp.addRow(8,l3);
        gp.addRow(9,l9);

        Scene scene = new Scene(gp,800,800);
        stage.setScene(scene);
        stage.show();
    }
}