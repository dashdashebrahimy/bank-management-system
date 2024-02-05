class account
{
private:
    std::string accnum, word, balance;

public:
    std::string find_accnum(std::string username)
    {
        std::ifstream myfile;
        myfile.open("Customerinformation.txt");

        if (myfile.is_open())
        {
            while (myfile >> word)
            {
                if (word == username)
                {
                    for (int i = 0; i < 7; ++i)
                        myfile >> word;

                    accnum = word;
                    break;
                }
            }
        }
        else
        {
            std::cout << "The file could not be opened!";
        }

        myfile.close();
        return accnum;
    }

    std::string getbalance(std::string ccn)
    {
        std::ifstream myfile;
        myfile.open("accountNumbers.txt");

        if (myfile.is_open())
        {
            while (myfile >> word)
            {
                if (word == ccn)
                {
                    myfile >> word;
                    myfile >> word;
                    myfile >> word;
                    myfile >> word;
                    myfile >> word;
                    myfile >> word;
                    balance = word;
                    break;
                }
            }
        }
        else
        {
            std::cout << "The file could not be opened!";
        }

        myfile.close();
        return balance;
    }

    void withdraw_money(std::string accnum, std::string balance)
    {
        std::cout << "\n\n\t\t\t\tEnter the amount you want to withdraw: ";
        int New_withdraw;
        std::cin >> New_withdraw;
        int balanceint = std::stoi(balance) - New_withdraw;
        std::cout << "Mission accomplished" << std::endl;
        balance = std::to_string(balanceint);
        int num = std::stoi(accnum.substr(10, 14)) - 1;
        std::string originalFilePath = "accountNumbers.txt";
        int lineNumber = num * 7 + 6;
        std::string newLineContent = "Balance : " + balance;
        std::ifstream originalFile("accountNumbers.txt");
        std::ofstream tempFile("temp.txt");

        if (originalFile.is_open() && tempFile.is_open())
        {
            std::string line;
            int currentLineNumber = 0;

            while (currentLineNumber < lineNumber - 1 && std::getline(originalFile, line))
            {
                tempFile << line << std::endl;
                currentLineNumber++;
            }
            tempFile << newLineContent << std::endl;

            std::getline(originalFile, line);

            while (std::getline(originalFile, line))
            {
                tempFile << line << std::endl;
            }
            originalFile.close();
            tempFile.close();
            std::remove("accountNumbers.txt");
            std::rename("temp.txt", "accountNumbers.txt");
        }
        else
        {
            std::cout << "Error opening files." << std::endl;
        }
    }

    void deposit_money(std::string accnum, std::string balance)
    {
        std::cout << "\n\n\t\t\t\tEnter the amount you want to deposit: ";
        int New_deposit;
        std::cin >> New_deposit;
        int balanceint = std::stoi(balance) + New_deposit;
        std::cout << "Mission accomplished" << std::endl;
        balance = std::to_string(balanceint);
        int num = std::stoi(accnum.substr(10, 14)) - 1;
        std::string originalFilePath = "accountNumbers.txt";
        int lineNumber = num * 7 + 6;
        std::string newLineContent = "Balance : " + balance;
        std::ifstream originalFile("accountNumbers.txt");
        std::ofstream tempFile("temp.txt");

        if (originalFile.is_open() && tempFile.is_open())
        {
            std::string line;
            int currentLineNumber = 0;

            while (currentLineNumber < lineNumber - 1 && std::getline(originalFile, line))
            {
                tempFile << line << std::endl;
                currentLineNumber++;
            }
            tempFile << newLineContent << std::endl;

            std::getline(originalFile, line);

            while (std::getline(originalFile, line))
            {
                tempFile << line << std::endl;
            }
            originalFile.close();
            tempFile.close();
            std::remove("accountNumbers.txt");
            std::rename("temp.txt", "accountNumbers.txt");
        }
        else
        {
            std::cout << "Error opening files." << std::endl;
        }
    }
    std::string getAccNum() const {
        return accnum;
    }
    std::string getBalance() const {
        return balance;
    }
};
