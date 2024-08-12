import javax.swing.*;
import java.awt.*;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class SimpleCPU extends JFrame {
    private static final int MEMORY_SIZE = 256;
    private static final int REGISTER_SIZE = 8;
    private int[] memory = new int[MEMORY_SIZE];
    private int[] registers = new int[REGISTER_SIZE];
    private int programCounter = 0;
    private JTextArea textArea;

    public SimpleCPU() {
        setTitle("Simple CPU Simulator");
        setSize(500, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);

        textArea = new JTextArea();
        textArea.setEditable(false);
        textArea.setFont(new Font("MonoLisa", Font.BOLD, 12));
        textArea.setForeground(Color.green);
        textArea.setBackground(Color.black);

        JScrollPane scrollPane = new JScrollPane(textArea);
        add(scrollPane, BorderLayout.CENTER);

        loadProgram("program.txt");
        loadData("data.txt");

        while (programCounter < memory.length && programCounter < 4) {
            int instruction = memory[programCounter];
            appendToTextArea("Executing instruction: " + Integer.toBinaryString(instruction));
            decodeAndExecute(instruction);
            displayRegisters();
            programCounter++;
        }

        displayRegisters();
    }

    private void loadProgram(String fileName) {
        initializeMemory();

        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String line;
            int address = 0;

            while ((line = br.readLine()) != null) {
                memory[address] = Integer.parseInt(line.trim(), 2);
                address++;
            }
        } catch (IOException | NumberFormatException e) {
            handleException("Error loading program. Exiting.", e);
        }
    }

    private void loadData(String fileName) {
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String line;

            while ((line = br.readLine()) != null) {
                String[] words = line.split(" ");
                int memoryAddress = Integer.parseInt(words[0], 2);
                int data = Integer.parseInt(words[1], 2);

                if (isValidMemoryAddress(memoryAddress)) {
                    memory[memoryAddress] = data;
                } else {
                    handleMemoryAccessError();
                }
            }
        } catch (IOException | NumberFormatException e) {
            handleException("Error loading data. Exiting.", e);
        }
    }

    private void decodeAndExecute(int instruction) {
        int tBit = (instruction >> 15) & 0x1;
        int opcode = (instruction >> 11) & 0xF;
        int iBit = (instruction >> 10) & 0x1;
        int operand1 = (instruction >> 7) & 0x7;
        int operand2 = (instruction >> 3) & 0xF;
        int operand3 = instruction & 0x7;

        int operand1Value = getOperandValue(iBit, operand1, operand2);
        int operand2Value = registers[operand3];

        if (tBit == 1) {
            executeDataTransferInstruction(opcode, operand1, operand2Value);
        } else {
            executeArithmeticOrLogicalInstruction(opcode, operand1, operand1Value, operand2Value);
        }
    }

    private int getOperandValue(int iBit, int operand, int operandValue) {
        return (iBit == 0) ? registers[operand] : operandValue;
    }

    private void executeDataTransferInstruction(int opcode, int operand1, int operand2Value) {
        switch (opcode) {
            case 5:
                appendToTextArea("LOAD instruction");
                registers[operand1] = operand2Value;
                break;
            case 6:
                appendToTextArea("STORE instruction");
                memory[operand2Value] = registers[operand1];
                break;
            default:
                appendToTextArea("Invalid opcode for data transfer instruction");
        }
    }

    private void executeArithmeticOrLogicalInstruction(int opcode, int operand1, int operand1Value, int operand2Value) {
        switch (opcode) {
            case 0:
                appendToTextArea("ADD instruction");
                registers[operand1] = operand1Value + operand2Value;
                break;
            case 1:
                appendToTextArea("SUB instruction");
                registers[operand1] = operand1Value - operand2Value;
                break;
            case 2:
                appendToTextArea("AND instruction");
                registers[operand1] = operand1Value & operand2Value;
                break;
            case 3:
                appendToTextArea("OR instruction");
                registers[operand1] = operand1Value | operand2Value;
                break;
            case 4:
                appendToTextArea("XOR instruction");
                registers[operand1] = operand1Value ^ operand2Value;
                break;
            default:
                appendToTextArea("Invalid opcode for arithmetic or logical instruction");
        }
    }

    private void displayRegisters() {
        StringBuilder registersText = new StringBuilder();
        for (int i = 0; i < registers.length; i++) {
            registersText.append("Register ").append(i).append(": ").append(registers[i]).append("\n");
        }
        appendToTextArea(registersText.toString());
    }

    private void initializeMemory() {
        for (int i = 0; i < MEMORY_SIZE; i++) {
            memory[i] = 0;
        }
    }

    private boolean isValidMemoryAddress(int address) {
        return address >= 0 && address < MEMORY_SIZE;
    }

    private void handleMemoryAccessError() {
        appendToTextArea("Error: Out of bounds memory access. Exiting.");
        System.exit(1);
    }

    private void appendToTextArea(String text) {
        textArea.append(text + "\n");
    }

    private void handleException(String message, Exception e) {
        e.printStackTrace();
        JOptionPane.showMessageDialog(this, message, "Error", JOptionPane.ERROR_MESSAGE);
        System.exit(1);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new SimpleCPU().setVisible(true));
    }
}


// import javax.swing.*;
// import java.awt.*;
// import java.io.BufferedReader;
// import java.io.FileReader;
// import java.io.IOException;

// public class SimpleCPU extends JFrame {
//     private static final int MEMORY_SIZE = 256;
//     private static final int REGISTER_SIZE = 8;
//     private int[] memory = new int[MEMORY_SIZE];
//     private int[] registers = new int[REGISTER_SIZE];
//     private int programCounter = 0;
//     private JTextArea textArea;

//     public SimpleCPU() {
//         setTitle("Simple CPU Simulator");
//         setSize(500, 400);
//         setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
//         setLocationRelativeTo(null);
//         setVisible(true);

//         textArea = new JTextArea();
//         textArea.setEditable(false);
//         textArea.setFont(new Font("MonoLisa", Font.BOLD, 12)); // Set a monospaced font
//         textArea.setForeground(Color.green);
//         textArea.setBackground(Color.black);

//         JScrollPane scrollPane = new JScrollPane(textArea);
//         add(scrollPane, BorderLayout.CENTER);

//         loadProgram("program.txt");
//         loadData("data.txt");

//         while (programCounter < memory.length && programCounter < 4) {
//             int instruction = memory[programCounter];
//             appendToTextArea("Executing instruction: " + Integer.toBinaryString(instruction));
//             decodeAndExecute(instruction);
//             displayRegisters();
//             programCounter++;
//         }

//         displayRegisters();
//     }

//     private void loadProgram(String fileName) {
//         initializeMemory();

//         try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
//             String line;
//             int address = 0;

//             while ((line = br.readLine()) != null) {
//                 memory[address] = Integer.parseInt(line.trim(), 2);
//                 address++;
//             }
//         } catch (IOException | NumberFormatException e) {
//             handleException("Error loading program. Exiting.", e);
//         }
//     }

//     private void loadData(String fileName) {
//         try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
//             String line;

//             while ((line = br.readLine()) != null) {
//                 String[] words = line.split(" ");
//                 int memoryAddress = Integer.parseInt(words[0], 2);
//                 int data = Integer.parseInt(words[1], 2);

//                 if (isValidMemoryAddress(memoryAddress)) {
//                     memory[memoryAddress] = data;
//                 } else {
//                     handleMemoryAccessError();
//                 }
//             }
//         } catch (IOException | NumberFormatException e) {
//             handleException("Error loading data. Exiting.", e);
//         }
//     }

//     private void decodeAndExecute(int instruction) {
//         int tBit = (instruction >> 15) & 0x1;
//         int opcode = (instruction >> 11) & 0xF;
//         int iBit = (instruction >> 10) & 0x1;
//         int operand1 = (instruction >> 7) & 0x7;
//         int operand2 = (instruction >> 3) & 0xF;
//         int operand3 = instruction & 0x7;

//         int operand1Value = getOperandValue(iBit, operand1, operand2);
//         int operand2Value = registers[operand3];

//         if (tBit == 1) {
//             executeDataTransferInstruction(opcode, operand1, operand2Value);
//         } else {
//             executeArithmeticOrLogicalInstruction(opcode, operand1, operand1Value, operand2Value);
//         }
//     }

//     private int getOperandValue(int iBit, int operand, int operandValue) {
//         return (iBit == 0) ? registers[operand] : operandValue;
//     }

//     private void executeDataTransferInstruction(int opcode, int operand1, int operand2Value) {
//         switch (opcode) {
//             case 5:
//                 appendToTextArea("LOAD instruction");
//                 registers[operand1] = operand2Value;
//                 break;
//             case 6:
//                 appendToTextArea("STORE instruction");
//                 memory[operand2Value] = registers[operand1];
//                 break;
//             default:
//                 appendToTextArea("Invalid opcode for data transfer instruction");
//         }
//     }

//     private void executeArithmeticOrLogicalInstruction(int opcode, int operand1, int operand1Value, int operand2Value) {
//         switch (opcode) {
//             case 0:
//                 appendToTextArea("ADD instruction");
//                 registers[operand1] = operand1Value + operand2Value;
//                 break;
//             case 1:
//                 appendToTextArea("SUB instruction");
//                 registers[operand1] = operand1Value - operand2Value;
//                 break;
//             case 2:
//                 appendToTextArea("AND instruction");
//                 registers[operand1] = operand1Value & operand2Value;
//                 break;
//             case 3:
//                 appendToTextArea("OR instruction");
//                 registers[operand1] = operand1Value | operand2Value;
//                 break;
//             case 4:
//                 appendToTextArea("XOR instruction");
//                 registers[operand1] = operand1Value ^ operand2Value;
//                 break;
//             default:
//                 appendToTextArea("Invalid opcode for arithmetic or logical instruction");
//         }
//     }

//     private void displayRegisters() {
//         StringBuilder registersText = new StringBuilder();
//         for (int i = 0; i < registers.length; i++) {
//             registersText.append("Register ").append(i).append(": ").append(registers[i]).append("\n");
//         }
//         appendToTextArea(registersText.toString());
//     }

//     private void initializeMemory() {
//         for (int i = 0; i < MEMORY_SIZE; i++) {
//             memory[i] = 0;
//         }
//     }

//     private boolean isValidMemoryAddress(int address) {
//         return address >= 0 && address < MEMORY_SIZE;
//     }

//     private void handleMemoryAccessError() {
//         appendToTextArea("Error: Out of bounds memory access. Exiting.");
//         System.exit(1);
//     }

//     private void appendToTextArea(String text) {
//         textArea.append(text + "\n");
//     }

//     private void handleException(String message, Exception e) {
//         e.printStackTrace();
//         JOptionPane.showMessageDialog(this, message, "Error", JOptionPane.ERROR_MESSAGE);
//         System.exit(1);
//     }

//     public static void main(String[] args) {
//         SwingUtilities.invokeLater(() -> new SimpleCPU().setVisible(true));
//     }
// }
