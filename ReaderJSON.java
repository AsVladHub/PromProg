import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.JsonArray;
import com.google.gson.JsonObject;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class ReaderJSON {

    public static void main(String[] args) {
       
        String inputFilePath = "input.json";
        String outputFilePath = "output.json";
        
        
        Gson gson = new Gson();
        JsonObject inputJson;
        
        try {
            
            BufferedReader reader = new BufferedReader(new FileReader(inputFilePath));
            inputJson = gson.fromJson(reader, JsonObject.class);
            reader.close();

            
            JsonArray expressionsArray = inputJson.getAsJsonArray("expressions");
            JsonArray resultsArray = new JsonArray();
            ScriptEngine engine = new ScriptEngineManager().getEngineByName("JavaScript");

            for (int i = 0; i < expressionsArray.size(); i++) {
                String expression = expressionsArray.get(i).getAsString();
                try {
                    Object result = engine.eval(expression);
                    resultsArray.add(result.toString());
                } catch (ScriptException | ArithmeticException e) {
                    resultsArray.add("ERROR");
                }
            }

            
            JsonObject outputJson = new JsonObject();
            outputJson.add("results", resultsArray);

            
            BufferedWriter writer = new BufferedWriter(new FileWriter(outputFilePath));
            gson.toJson(outputJson, writer);
            writer.close();

        } catch (IOException e) {
            e.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
