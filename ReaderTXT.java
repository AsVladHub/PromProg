import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class ReaderTXT {
    public static void main(String[] args) {
        ScriptEngine engine = new ScriptEngineManager().getEngineByName("JavaScript");
        String inputFile = "input.txt";
        String outputFile = "output.txt";

        try (BufferedReader br = new BufferedReader(new FileReader(inputFile));
             BufferedWriter bw = new BufferedWriter(new FileWriter(outputFile))) {
             
            String line;
            while ((line = br.readLine()) != null) {
                try {
                    
                    Object result = engine.eval(line);
                    bw.write(result.toString());
                } catch (ScriptException e) {
                    
                    bw.write("ERROR");
                } catch (ArithmeticException e) {
                    
                    bw.write("ERROR");
                }
                bw.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
