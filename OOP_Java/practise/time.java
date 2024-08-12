import java.util.Timer;
import java.util.TimerTask;

public class time {
    public static void main(String[] args) {
        Timer timer = new Timer();

        // Schedule the timer task to update every 15 seconds
        timer.scheduleAtFixedRate(new UpdateTask(), 0, 15 * 1000);

        // Schedule the timer task to clear the console every minute
        timer.scheduleAtFixedRate(new ClearConsoleTask(), 0, 60 * 1000);
    }

    static class UpdateTask extends TimerTask {
        @Override
        public void run() {
            // Update task logic here
            System.out.println("** Updating every 15 seconds **");
        }
    }

    static class ClearConsoleTask extends TimerTask {
        @Override
        public void run() {
            // Clear console task logic here
            try {
                // For Windows
                if (System.getProperty("os.name").contains("Windows")) {
                    new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
                } else {
                    // For Unix-based systems
                    System.out.print("\033[H\033[2J");
                    System.out.flush();
                }
            } catch (Exception ex) {
                ex.printStackTrace();
            }

            System.out.println("** Console cleared, starting new minute **");
        }
    }
}
