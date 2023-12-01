// 2.	The system will ask you to enter the name of the file to read from. If the file will not exist, the system will ask you, do you want to create – if you press 1 than system will automatically create 	the file and ask to enter the data in the file. Then the system will ask you – do you want to copy the data to another file – if you press 1 than the system will ask you where you want to copy. If your entered file is there in the drive, than the program will append the data in that file otherwise the program will create the new file with that name and copy the data accordingly.

import java.io.*;
import java.util.*;

public class p2 {
    Scanner sc = new Scanner(System.in);
    String fileName;
    File file;
    FileWriter fw;
    FileReader fr;
    BufferedWriter bw;
    BufferedReader br;
    String data;

    public p2() throws IOException {
        System.out.print("Enter the name of the file to read from: ");
        fileName = sc.nextLine();
        file = new File(fileName);
        if (!file.exists()) {
            System.out.print("File does not exist. Do you want to create it? (1/0): ");
            if (sc.nextInt() == 1) {
                file.createNewFile();
                System.out.print("Enter the data to write to the file: ");
                sc.nextLine();
                data = sc.nextLine();
                fw = new FileWriter(file);
                bw = new BufferedWriter(fw);
                bw.write(data);
                bw.close();
                fw.close();
            } else {
                System.exit(0);
            }
        }
        System.out.print("Do you want to copy the data to another file? (1/0): ");
        if (sc.nextInt() == 1) {
            System.out.print("Enter the name of the file to copy to: ");
            sc.nextLine();
            fileName = sc.nextLine();
            file = new File(fileName);
            if (!file.exists()) {
                file.createNewFile();
            }
            fr = new FileReader(this.file);
            br = new BufferedReader(fr);
            fw = new FileWriter(file, true);
            bw = new BufferedWriter(fw);
            while ((data = br.readLine()) != null) {
                bw.write(data);
            }
            bw.close();
            fw.close();
            br.close();
            fr.close();
        }
    }

    public static void main(String[] args) throws IOException {
        new p2();
    }
}
