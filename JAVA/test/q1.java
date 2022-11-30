import javafx.application.*;
import javafx.stage.*;
import javafx.scene.*;
import javafx.event.*;
import javafx.scene.image.*;
import javafx.scene.input.*;
import javafx.scene.layout.*;
import javafx.scene.paint.*;
import javafx.scene.text.*;
import javafx.scene.shape.*;

public class q1 extends Application
{
    public static void main(String[] args)
    {
        launch(args);
    }
    @Override
    public void start(Stage stage)
    {
        Group root = new Group();
        Scene scene = new Scene(root,600,600,Color.LIGHTSKYBLUE);
        Image icon = new Image("unnamed.jpg");
        stage.setTitle("JAVAFX Program");
        stage.getIcons().add(icon);

        stage.setHeight(500);
        stage.setWidth(500);
        stage.setResizable(false);
        stage.setFullScreen(true);
        stage.setFullScreenExitHint("Press C to escape");
        stage.setFullScreenExitKeyCombination(KeyCombination.valueOf("C"));

        Text text = new Text();
        text.setText("Hello Guys");
        text.setX(250);
        text.setY(100);
        text.setFont(Font.font("Verdana",50));
        text.setFill(Color.GREEN);

        Line line = new Line();
        line.setStartX(200);
        line.setStartY(200);
        line.setEndX(500);
        line.setEndY(500);
        line.setStrokeWidth(6);
        line.setStroke(Color.RED);
        line.setOpacity(0.5);
        line.setRotate(90);

        Rectangle rect = new Rectangle();
        rect.setX(100);
        rect.setY(200);
        rect.setWidth(100);
        rect.setHeight(100);
        rect.setFill(Color.YELLOW);
        rect.setStrokeWidth(6);
        rect.setStroke(Color.BLACK);

        Polygon tri = new Polygon();
        tri.getPoints().setAll(100.0,300.0,
        200.0,400.0,
        100.0,500.0);
        tri.setFill(Color.YELLOW);
        tri.setStrokeWidth(6);
        tri.setStroke(Color.BLACK);

        Circle cir = new Circle();
        cir.setCenterX(100);
        cir.setCenterY(100);
        cir.setRadius(50);
        cir.setFill(Color.ORANGE);

        Image im = new Image("dv.jpg");
        ImageView iv = new ImageView(im);
        iv.setX(300);
        iv.setY(300);
        iv.setFitHeight(300);
        iv.setFitWidth(300);


        root.getChildren().add(text);
        root.getChildren().add(line);
        root.getChildren().add(rect);
        root.getChildren().add(tri);
        root.getChildren().add(cir);
        root.getChildren().add(iv);


        stage.setScene(scene);
        stage.show();
    }
}