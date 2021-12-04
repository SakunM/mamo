import java.io.*;
import java.io.IOException;
import java.nio.file.*;
import java.util.List;
import static java.util.stream.Collectors.toList;

public class UserFile {
  public static void main(String[] args) throws IOException {
    UserFile uf = new UserFile();
    uf.ffUser("a:/pj/sc/lib/rs/issues/issue1.txt");
    List<String> lst = uf.list();
    System.out.println(lst);
  }
  List<String> lines; boolean empty;
  public void ffUser(String path) throws IOException{ 
    List<String>lines = Files.readAllLines(Paths.get(path));
    if(lines.size() == 0){ this.empty = true;}
    else{ this.lines =lines; this.empty = false;}
  }
  public List<String> list(){ return this.lines.stream().map(l -> l.trim()).collect(toList());}
}