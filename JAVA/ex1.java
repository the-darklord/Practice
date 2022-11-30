import javafx.event.*;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.*;

public class ex1 extends Application
{
	public static void main(String[] args)
	{
		launch(args);
	}
	public void start(Stage stage) throws Exception
	{
		Label l1=new Label("Enter Number 1 : ");
		Label l2=new Label("Enter Number 2 : ");
		Label l3=new Label("Result : ");
		TextField f1 = new TextField();
		TextField f2 = new TextField();
		TextField f3 = new TextField();
		Button b1 = new Button("Add");
		Button b2 = new Button("Sub");
		Button b3 = new Button("Mult");
		Button b4 = new Button("Div");

		b1.setOnAction(new EventHandler<ActionEvent>()
		{
			public void handle(ActionEvent ae)
			{
				String n1 = f1.getText();
				String n2 = f2.getText();
				Double res = Double.parseDouble(n1)+Double.parseDouble(n2);
				f3.setText(res.toString());
			}
		});
		b2.setOnAction(new EventHandler<ActionEvent>()
		{
			public void handle(ActionEvent ae)
			{
				String n1 = f1.getText();
				String n2 = f2.getText();
				Double res = Double.parseDouble(n1)-Double.parseDouble(n2);
				f3.setText(res.toString());
			}
		});
		b3.setOnAction(new EventHandler<ActionEvent>()
		{
			public void handle(ActionEvent ae)
			{
				String n1 = f1.getText();
				String n2 = f2.getText();
				Double res = Double.parseDouble(n1)*Double.parseDouble(n2);
				f3.setText(res.toString());
			}
		});
		b4.setOnAction(new EventHandler<ActionEvent>()
		{
			public void handle(ActionEvent ae)
			{
				String n1 = f1.getText();
				String n2 = f2.getText();
				Double res = Double.parseDouble(n1)/Double.parseDouble(n2);
				f3.setText(res.toString());
			}
		});
		GridPane g = new GridPane();
		g.addRow(0,l1,f1);
		g.addRow(1,l2,f2);
		g.addRow(2,b1,b2,b3,b4);
		g.addRow(3,l3,f3);
		Scene scene = new Scene(g,500,500);
		stage.setTitle("Calculator");
		stage.setScene(scene);
		stage.show();
	}
}