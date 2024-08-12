// 6.	Write a java program to create Account with 500 rupee minimum balance, deposit amount, withdraw amount and also throws LessBalanceException which returns the statement that says withdraw amount is not valid.

class LessBalanceException extends Exception {
    LessBalanceException(String s) {
        super(s);
    }
}

class p6 {
    private static final int MINIMUM_BALANCE = 500;
    private int balance;

    p6(int initialBalance) {
        if (initialBalance >= MINIMUM_BALANCE) {
            balance = initialBalance;
        } else {
            throw new IllegalArgumentException("Initial balance must be at least " + MINIMUM_BALANCE);
        }
    }

    void deposit(int amount) {
        balance += amount;
    }

    void withdraw(int amount) throws LessBalanceException {
        if (balance - amount >= MINIMUM_BALANCE) {
            balance -= amount;
        } else {
            throw new LessBalanceException("Withdraw amount is not valid, it would result in less than minimum balance.");
        }
    }

    int getBalance() {
        return balance;
    }

    public static void main(String[] args) {
        p6 account = new p6(1000);
        System.out.println("Initial balance: " + account.getBalance());
        account.deposit(500);
        System.out.println("Balance after depositing 500: " + account.getBalance());
        try {
            account.withdraw(1000);
            System.out.println("Balance after withdrawing 1000: " + account.getBalance());
            account.withdraw(1000);
            System.out.println("Balance after withdrawing 1000: " + account.getBalance());
        } catch (LessBalanceException e) {
            System.out.println(e.getMessage());
        }
    }
}